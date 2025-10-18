#include<Servo.h>
#define x_pin A0
#define y_pin A1
#define hardcoded_vcc A2
#define hardcoded_gnd A3

Servo myServo;
void setup() {
  Serial.begin(9600);
  pinMode(hardcoded_vcc, OUTPUT);
  pinMode(hardcoded_gnd, OUTPUT);
  digitalWrite(hardcoded_vcc,HIGH);
  digitalWrite(hardcoded_gnd,LOW);
  myServo.attach(6);

}

void loop() {
  //get value of x and y 

  int x_val=analogRead(x_pin);
  int y_val=analogRead(y_pin);
  //map servo monitor to x;
  int angle=map(x_val,0,1023,0,180);//angle got by manipulating x
  myServo.write(angle);
  delay(15);
  //print values on the serial
  Serial.print("(");
  Serial.print(x_val);
  Serial.print(",");
  Serial.print(y_val);
  Serial.println(")");
  

}
