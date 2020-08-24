/* 
 * File:   Traffic.h
 * Author: acer
 *
 * Created on April 22, 2020, 3:46 AM
 */

#ifndef TRAFFIC_H
#define	TRAFFIC_H

#ifdef	__cplusplus
extern "C" {
#endif
#include<xc.h>
#define SEGMENT_PORT  PORTC
#define DIGIT_PORT        PORTD
    
    typedef struct {
        
  struct {
        char t1red:1;
        char t1yellow:1;
        char t1green:1;
        char t2red:1;
        char t2yellow:1;
        char t2green:1;
        char t3red:1;
        char t3yellow:1;
        char t3green:1;
        char t4red:1;
        char t4yellow:1;
        char t4green:1;
  }LED;
  
    }TrafficLight; 

    typedef union {
        
        struct{
            char s1d1:1;
            char s1d2:1;
            char s2d1:1;
            char s2d2:1;
            char s3d1:1;
            char s3d2:1;
            char s4d1:1;
            char s4d2:1;
        }Seg;
        
    }Segment;
    
 #define VIP1 4
 #define VIP2 5
 #define VIP3 6
 #define VIP4 7
    const char VIP_PrioTab[16]={0,VIP1,VIP2,VIP2,
                                        VIP3,VIP3,VIP3,VIP3,
                                        VIP4,VIP4,VIP4,VIP4,
                                        VIP4,VIP4,VIP4,VIP4};
    char reset=0;
    char VIP=0;
    char Temp=0;
    int  LAT;
    char Seg[10]={1,2,3,4,2,4,2,4,0,0};
    char SegDigit;
    int LED=0;
    void Latch_Traffic_LED(int *LATptr);
    void Traffic_SegmentDisplay(char val);
    void Sec2Time(char t1,char t2,char t3,char t4);
    void Counting(void);
    void Traffic_Light (int led);
    inline void Clr_LED(void);
    void VIP_mode(void);
 
 

#define bitset(var,bitno)    var|=1<<bitno
#define bitclr(var,bitno)    var&=~(1<<bitno)
#define bittest(var,bitno)   (var & (1<<bitno))

#define T1RED            1
#define T1YELLOW     (1<<1)
#define T1GREEN         (1<<2)
#define T2RED           (1<<3)
#define T2YELLOW     (1<<4)
#define T2GREEN         (1<<5)
#define T3RED           (1<<6)
#define T3YELLOW     (1<<7)
#define T3GREEN         (1<<8)
#define T4RED           (1<<9)
#define T4YELLOW     (1<<10)
#define T4GREEN         (1<<11)
#define DIGIT   ((Segment*)&DIGIT_PORT)
#define Trafficlight ((TrafficLight*)&LAT) 


    
#ifdef	__cplusplus
}
#endif

#endif	/* TRAFFIC_H */

