#define data 5
#define clk 6
#define latch 7

void setup() {
  // put your setup code here, to run once:
pinMode(data,OUTPUT);
pinMode(clk,OUTPUT);
pinMode(latch,OUTPUT);
}

void latchIt(){
digitalWrite(latch,HIGH);
delayMicroseconds(10);
digitalWrite(latch,LOW);
delayMicroseconds(10);  
}

void loop() {
  for(int i=0; i<1000; i++){
  shiftOut(data,clk,MSBFIRST,0b01010001);
  latchIt();
  delay(1);
  shiftOut(data,clk,MSBFIRST,0b01011001);
  latchIt();
  delay(2);
  }
  for(int i=0; i<1000; i++){
  shiftOut(data,clk,MSBFIRST,0b10011010);
  latchIt();
  delay(1);
  shiftOut(data,clk,MSBFIRST,0b10011010);
  latchIt();
  delay(2);
  }
  
}
