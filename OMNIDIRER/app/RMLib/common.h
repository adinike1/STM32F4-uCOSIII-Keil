#ifndef _COMMON_H_
#define _COMMON_H_

#include "stm32f4xx.h"

#define VAL_LIMIT(val, min, max) \
{\
	if(val <= min)\
	{\
		val = min;\
	}\
	else if(val >= max)\
	{\
		val = max;\
	}\
}\

#endif