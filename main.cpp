#include "mbed.h"
#include "arm_book_lib.h"
#define BLINKING_RATE     200ms
    DigitalIn b1(BUTTON1);
    DigitalIn d2(D2);
    DigitalIn d3(D3);
    DigitalIn d4(D4);
    DigitalIn d5(D5);
    DigitalIn d6(D6);
    DigitalIn d7(D7);
    AnalogIn a5(A5);
    DigitalOut led1(LED1);
    DigitalOut led2(LED2);
    DigitalOut led3(LED3);

void Emergency(){
    d5.mode(PullDown);
    d4.mode(PullDown);
    d3.mode(PullDown);
    d2.mode(PullDown);
    int i = 1;
    int count, flag = 0;
    while(i == 1){
    led3 = !led3;
    led2 = !led2;
    ThisThread::sleep_for(BLINKING_RATE/2);
    if(d5 && d4 && d3 && !d2){
            return;
    } else if(d5 || d4 || d3 || d2){
        while(d5 || d4 || d3 || d2){
        }
         count = count + 1;
      if (count == 5){
          led2 = OFF;
          led3 = OFF;
          while(flag <= 300 ){
            led1 = !led1;
           ThisThread::sleep_for(BLINKING_RATE);
           flag = flag + 1;
          }
          led1 = OFF;
          count = 0;
      }
    }

 }
}

void Alarm(){
        int i = 1;

    while(i == 1){
       led3 = !led3;
        ThisThread::sleep_for(BLINKING_RATE);
        if(d6 == ON && d7 == ON){
        Emergency();
        led3 = OFF;
        led2 = OFF;
        break;
     }
 }
}
int main()
{
    d6.mode(PullDown);
    d7.mode(PullDown);
    
    led1 = OFF;
    led2 = OFF;
    led3 = OFF;
while (true) {
    if(d6 == ON || d7 == ON){
        Alarm();
     }
    }
}