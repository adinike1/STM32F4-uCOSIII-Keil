#ifndef _LED_H
#define _LED_H
#ifdef __cplusplus
 extern "C" {
#endif
#include "sys.h"

//LED�˿ڶ���
#define LED0 PGout(0)
#define LED1 PGout(1)

void LED_Init(void);  //��ʼ��
	 
#ifdef __cplusplus
}
#endif

#endif
