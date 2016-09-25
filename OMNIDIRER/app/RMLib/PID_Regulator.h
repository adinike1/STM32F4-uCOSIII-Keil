#ifndef _PID_REGULATOR_H_
#define _PID_REGULATOR_H_
#include "stm32f4xx.h"

class PID_Regulator
{
public:
	PID_Regulator();
	void SetParam(float kp,float ki,float kd);
	void SetParamOffset(float kp_offset, float ki_offset, float kd_offset);
	void SetRef(float ref);
	void SetFfb(float fdb);
	void Calc();
	void Reset();	
	
private:
	float m_ref;
	float m_fdb;
	float m_err[2];
	float m_kp;
	float m_ki;
	float m_kd;
	float m_kp_base;
	float m_ki_base;
	float m_kd_base;
	float m_kp_offset;
	float m_ki_offset;
	float m_kd_offset;
	float m_componentKp;
	float m_componentKi;
	float m_componentKd;
	float m_output;
	float m_componentKpMax;
	float m_componentKiMax;
	float m_componentKdMax;
	float m_outputMax;
};

#endif

