#include<xc.h>
#include "TRAFFIC.h"

void Latch_Traffic_LED(int *LATptr)
{
    PORTA=  *LATptr;
   PORTB=(*LATptr>>8);

}

void Counting(void)
{
    static  char i=0;
     static signed char s1=10;
     static signed char s2=10;
     static signed char s3=20;
     static signed char s4=30;
     static char j=0;
     static char T=1;
     static char S1;
     static char S2;
     static char S3;
     static char S4;
     if(reset)
     {
        reset=j=i=0;
        s1=s2=10;
        s3=20;
        s4=30;
        LED|=(T1GREEN|T2RED|T3RED|T4RED);
        LED&=~(T1RED|T2GREEN|T3GREEN|T4GREEN|T1YELLOW|T2YELLOW|T3YELLOW|T4YELLOW);
     }
     i++;
     if(i<200)
         return;
     j++;
     
     if(j>=10)
     {
         j=0;
         T++;
     }
         
     s1--;
     s2--;
     s3--;
     s4--;
     i=0;
     
     T=(T>4)? 1:T;
         
     switch(T)
     {
         case 0:
         case 1:
             S1=10;
             S2=10;
             S3=20;
             S4=30;
             LED|=(T1GREEN|T2RED|T3RED|T4RED);
             LED&=~(T1RED|T2GREEN|T3GREEN|T4GREEN|T1YELLOW|T2YELLOW|T3YELLOW|T4YELLOW);
             break;
         case 2:
                S2=10;
             S1=30;
             S3=10;
             S4=20;
             LED|=(T2GREEN|T1RED|T3RED|T4RED);
             LED&=~(T2RED|T1GREEN|T3GREEN|T4GREEN|T1YELLOW|T2YELLOW|T3YELLOW|T4YELLOW);
             break;
         case 3:
                S3=10;
             S1=20;
             S2=30;
             S4=10;
              LED|=(T3GREEN|T1RED|T2RED|T4RED);
             LED&=~(T3RED|T1GREEN|T2GREEN|T4GREEN|T1YELLOW|T2YELLOW|T3YELLOW|T4YELLOW);
             break;
         case 4:
             S4=10;
             S2=20;
             S3=30;
             S1=10;
             LED|=(T4GREEN|T2RED|T3RED|T1RED);
             LED&=~(T4RED|T2GREEN|T3GREEN|T1GREEN|T1YELLOW|T2YELLOW|T3YELLOW|T4YELLOW);
             break;
         default:
             while(1)
                 ;
             break;
     }
     if((~LED&T1RED)&&(s1<=1))
     {
         LED|=T1YELLOW;
         LED&=~T1GREEN;
     }
      if((~LED&T2RED)&&(s2<=1))
      {
         LED|=T2YELLOW;
         LED&=~T2GREEN;
      }
      if((~LED&T3RED)&&(s3<=1))
      {
         LED|=T3YELLOW;
         LED&=~T3GREEN;
      }
      if((~LED&T4RED)&&(s4<=1))
      {
         LED|=T4YELLOW;
         LED&=~T4GREEN;
      }
     s1=(s1>0) ? s1: S1;
     s2=(s2>0) ? s2: S2;
     s3=(s3>0) ? s3: S3;
     s4=(s4>0) ? s4: S4;
     Sec2Time(s1,s2,s3,s4);
     
                
}
void Sec2Time(char t1,char t2,char t3,char t4)
{ 
    for(char k=0;k<8;k++)
         Seg[k]=0;
    while(t1>=10)
    {
        Seg[0]++;
        t1-=10;
    }
     while(t2>=10)
     {
        Seg[2]++;
        t2-=10;
    }
     while(t3>=10){
        Seg[4]++;
        t3-=10;
    }
     while(t4>=10)
     {
        Seg[6]++;
        t4-=10;
    }
    Seg[1]=t1;
    Seg[3]=t2;
    Seg[5]=t3;
    Seg[7]=t4;
}
void Traffic_Light(int led)
{
    if((led&T1RED))
        Trafficlight->LED.t1red=1;
    if((led&T1YELLOW))
        Trafficlight->LED.t1yellow=1;
    if((led&T1GREEN))
        Trafficlight->LED.t1green=1;
     if((led&T2RED))
        Trafficlight->LED.t2red=1;
     if((led&T2YELLOW))
        Trafficlight->LED.t2yellow=1;
      if((led&T2GREEN))
        Trafficlight->LED.t2green=1;
       if((led&T3RED))
        Trafficlight->LED.t3red=1;
        if((led&T3YELLOW))
         Trafficlight->LED.t3yellow=1;
        if((led&T3GREEN))
             Trafficlight->LED.t3green=1;
        if((led&T4RED))
             Trafficlight->LED.t4red=1;
        if((led&T4YELLOW))
             Trafficlight->LED.t4yellow=1;
         if((led&T4GREEN))
             Trafficlight->LED.t4green=1;
}
inline void Clr_LED(void)
{
    LAT=0;
    
}