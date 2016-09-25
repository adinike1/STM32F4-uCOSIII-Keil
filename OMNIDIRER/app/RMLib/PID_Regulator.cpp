#include <stm32f4xx.h>
#include "PID_Regulator.h"
#include "common.h"
PID_Regulator::PID_Regulator()
{
	
}

void PID_Regulator::SetParam(float kp,float ki,float kd)
{
	m_kp = kp;
	m_ki = ki;
	m_kd = kd;
}

void PID_Regulator::SetRef(float ref)
{
	m_ref = ref;
}

void PID_Regulator::SetFfb(float fdb)
{
	m_fdb = fdb;
}

void PID_Regulator::SetParamOffset(float kp_offset, float ki_offset, float kd_offset)
{
	m_kp_offset = kp_offset;
	m_ki_offset = ki_offset;
	m_kd_offset = kd_offset;
}
//PID计算函数需要修改，增加防积分饱和功能
void PID_Regulator::Calc()
{
	m_err[0] = m_err[1];
	m_err[1] = m_ref - m_fdb;
	m_kp = (m_kp_base + m_kp_offset);
	m_ki = (m_ki_base + m_ki_offset);
	m_kd = (m_kd_base + m_kd_offset);
	m_componentKp = m_kp * m_err[1];
	m_componentKi += m_ki * m_err[1];
	m_componentKd = m_kd * (m_err[1] - m_err[0]);
	VAL_LIMIT(m_componentKp, -m_componentKpMax, m_componentKpMax);
	VAL_LIMIT(m_componentKi, -m_componentKiMax, m_componentKiMax);
	VAL_LIMIT(m_componentKd, -m_componentKdMax, m_componentKdMax);
	m_output = m_componentKp+m_componentKi+m_componentKd;
	VAL_LIMIT(m_output, -m_outputMax, m_outputMax);
}

void PID_Regulator::Reset()
{
	m_componentKp = 0;
	m_componentKi = 0;
	m_componentKd = 0;
}
