//this code for PCINT
int count=0;
void setup() {
DDRB |=B00010000;
//DDRC |=B00000000;  
//PORTC |=B00000010;
PORTB |=B00000000;
DDRD |=B00000111;

PCICR |=B00000001;
PCMSK0 |=B00000010;

}
ISR(PCINT0_vect){
  if(count<=1){
    PORTB |=B00010000;
  count++;
  }
  else if(count==2){
    PORTB &=B00000000;
    count++;
    }
  else{
    PORTB &=B00000000;
    count=0;
    }
  }

void loop() {

for(int i=0;i<3;i++){
  PORTD =B00000000;
  PORTD |=(1<<i);
  delay(500);
  }
for(int i=0;i<3;i++){
  PORTD =B00000000;
  PORTD |=(B00000100>>i);
  delay(500);
  }
/*  if(0==(PINC>>1)){
    PORTB |=B00010000;
    }
   else{
    PORTB &=B00000000;
    }
*/
}
