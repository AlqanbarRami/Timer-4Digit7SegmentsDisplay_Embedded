#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <time.h> 

#define SegA (1<<PD1)
#define SegB (1<<PD2)
#define SegC (1<<PD3)
#define SegD (1<<PD4)
#define SegE (1<<PD5)
#define SegF (1<<PD6)
#define SegG (1<<PD7)
#define SegP (1<<PD0)

void rensa(){    //break for button
    PORTB=PORTB &~ 1 <<PB5;
    PORTB=PORTB &~ 1 <<PB0;
    PORTB=PORTB &~1 <<PB3;
    PORTB=PORTB &~ 1 << PB4;
}

//numbers
void Zero(){
PORTD |= SegA;
PORTD |= SegC;
PORTD |= SegD;
PORTD |= SegE;
PORTD |= SegF;
PORTD |= SegG;
PORTD |= SegP;
}
void One(){

PORTD |= SegC;
PORTD |= SegD;

PORTD |= SegP;
}
void Two(){
PORTD |= SegB;
PORTD |= SegC;
PORTD |=SegE;
PORTD |=SegF;
PORTD |= SegG;
PORTD |= SegP;
}
void Three(){

PORTD |= SegB;
PORTD |= SegC;
PORTD |= SegD;
PORTD |=SegE;

PORTD |= SegG;
PORTD |= SegP;
}

void Four(){
PORTD |= SegA;
PORTD |= SegB;
PORTD |= SegC;
PORTD |= SegD;
PORTD |= SegP;
}
 void Five(){
PORTD |= SegA;
PORTD |= SegB;
PORTD |= SegD;
PORTD |=SegE;
PORTD |= SegG;
PORTD |= SegP;
 }
 void Six(){
PORTD |= SegA;
PORTD |= SegB;
PORTD |= SegD;
PORTD |=SegE;
PORTD |=SegF;
PORTD |=SegG;
PORTD |= SegP;
 }

 void Seven(){

PORTD |= SegC;
PORTD |= SegD;
PORTD |=SegG;
PORTD |= SegP;
 }

 void Eight(){
PORTD |= SegA;
PORTD |= SegB;
PORTD |= SegC;
PORTD |= SegD;
PORTD |= SegE;
PORTD |= SegF;
PORTD |= SegG;
PORTD |= SegP;
 }

 void Nine(){
PORTD |= SegA;
PORTD |= SegB;
PORTD |= SegC;
PORTD |= SegD;
PORTD |= SegG;
PORTD |= SegP;
}

// take a number
void Take(int x){
switch (x)
{
case 1: One();
break;
case 2: Two();
break;
case 3:
Three();
break;
case 4: 
Four();
break;
case 5: 
Five();
break;
case 6: 
Six();
break;
case 7 :
Seven();
break;
case 8:
Eight();
break;
case 9:
Nine();
break;
default:
Zero();
  break;
}
}
void TakeDigit(int x, int y){

switch (x)
{

case 1:
  PORTB=PORTB &~ 1 <<PB5;
PORTB=PORTB | 1 <<PB0;
PORTB=PORTB | 1 <<PB3;
PORTB=PORTB | 1 <<PB4;
  break;
case 2:
PORTB=PORTB &~ 1 <<PB0;
PORTB=PORTB | 1 <<PB5;
PORTB=PORTB | 1 <<PB3;
PORTB=PORTB | 1 <<PB4;
  break;
case 3:
  PORTB=PORTB &~ 1 <<PB3;
   PORTB=PORTB | 1 <<PB5;
PORTB=PORTB | 1 <<PB0;
PORTB=PORTB | 1 <<PB4;
  break;
case 4:
  PORTB=PORTB &~ 1 <<PB4;
   PORTB=PORTB | 1 <<PB5;
PORTB=PORTB | 1 <<PB0;
PORTB=PORTB | 1 <<PB3;
  break;

default:
  break;
 
}
 Take(y);
}

void TurnOffAll(){
  PORTB=0;
  PORTD=0;
}

void start(int x, int y){
  if(x==1){
  TurnOffAll();
  TakeDigit(1,y);
  _delay_ms(2);
  
  }
  if(x==2){
  TurnOffAll();
  TakeDigit(2,y);
  _delay_ms(2);
  }
   if(x==3){
  TurnOffAll();
  TakeDigit(3,y);
  _delay_ms(2);
  }
   if(x==4){
  TurnOffAll();
  TakeDigit(4,y);
  _delay_ms(2);
  }
  _delay_ms(1);
  
}





//for waiting at the beginning    
void wait(){
int x = rand() % 7 +3;
for(int i=0; i<x;i++){
PORTD &= ~ SegA;
PORTD |= SegB;
PORTD &= ~ SegC;
PORTD &= ~SegD;
PORTD &= ~ SegE;
PORTD &= ~ SegF;
PORTD &= ~ SegG;
PORTD &= ~ SegP;
_delay_ms(500);
PORTD &= ~ SegA;
PORTD &= ~SegB;
PORTD &= ~ SegC;
PORTD &= ~SegD;
PORTD &= ~ SegE;
PORTD &= ~ SegF;
PORTD &= ~ SegG;
_delay_ms(500);
 }
 x=0;
}


 


int main(){
    DDRB=255; 
    DDRD=255;
    DDRC=0;
    int x1,x2,x3,x4;
    int count = 0;
    int n =0;
  
while (1)
{

while (PINC & 1 << PC2)
{
start(1,x1);
start(2,x2);
start(3,x3); 
start(4,x4);  
}
rensa();
wait();
while(PINC | 1 << PC2){
start(4,x4=(n/1000));  
start(3,(x3=(n % 1000) / 100)); 
start(2,(x2=n % 100 / 10)); 
start(1,(x1=n % 10)); 
n++;
if(PINC & 1 << PC2){
  rensa();
  n=0;
  break;
}
}
 
}

  return 0;
}