#ifndef __DELAY_H
#define __DELAY_H 			  
#ifdef __cplusplus
 extern "C" {
#endif
	 
#include <sys.h>	  

void delay_init(u8 SYSCLK);
void delay_ms(u16 nms);
void delay_us(u32 nus);

#ifdef __cplusplus
}
#endif
#endif





























