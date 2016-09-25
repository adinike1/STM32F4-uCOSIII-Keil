#ifndef _LED_H
#define _LED_H
#ifdef __cplusplus
 extern "C" {
#endif
#include "sys.h"

//LED端口定义
#define LED0 PGout(0)
#define LED1 PGout(1)

void LED_Init(void);  //初始化
	 
#ifdef __cplusplus
}
#endif

#endif
