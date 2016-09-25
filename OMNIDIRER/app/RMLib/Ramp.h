#ifndef _RAMP_H_
#define _RAMP_H_
#include "stm32f4xx.h"

class Ramp{
public:
	Ramp(int32_t scale){
		XSCALE = scale;
	}
	
	float Calc()
	{
		count++;
		if(count>=XSCALE)
		{
			count = XSCALE;
		}
		return (count)/((float)XSCALE);		
	}
	
	void SetScale(int32_t scale)
	{
		XSCALE = scale;
	}
	
	void ResetCnt()
	{
		count = 0;
	}
	
	int32_t GetScale()
	{
		return XSCALE;
	}
	
	int32_t GetCount()
	{
		return count;
	}
	
private:
	float out;
	int32_t count;
	int32_t XSCALE;
};

#endif

