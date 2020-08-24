/* 
 * File:   LED_SEGMANT.h
 * Author: acer
 *
 * Created on April 22, 2020, 3:26 AM
 */

#ifndef LED_SEGMANT_H
#define	LED_SEGMANT_H

#ifdef	__cplusplus
extern "C" {
#endif

#define SEGMENT_BLINK_ON_TIME  100
#define SEGMENT_BLINK_OFF_TIME 100
    
#define DP  1
#define BL  1

#define _A    (1<<0)
#define _B    (1<<1)
#define _C    (1<<2)
#define _D    (1<<3)
#define _E    (1<<4)
#define _F    (1<<5)
#define _G    (1<<6)
#define _Dp   (1<<7)

void LED_7SEGMENT_Update(char val[]);


#ifdef	__cplusplus
}
#endif

#endif	/* LED_SEGMANT_H */

