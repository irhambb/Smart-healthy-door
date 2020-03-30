#include <Servo.h>;

 const int servoPin = 9;
 Servo servo;
int merah1 =10;
int ijo1 = 11;
int trigpin1 = 13;    //penginisal kaki trigpin masuk pin 3
int echopin1 = 12;
float durasi1, jarak1;


void setup() {
  // put your setup code here, to run once:
servo.attach (servoPin);
pinMode(merah1, OUTPUT);
pinMode(ijo1, OUTPUT);
pinMode(trigpin1,OUTPUT);  //pin trigpin sebagai OUTPUT
pinMode(echopin1,INPUT);


}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(trigpin1,LOW); 
delayMicroseconds(2);
digitalWrite(trigpin1,HIGH);  
delayMicroseconds(10);
digitalWrite(trigpin1,LOW);    


 
int durasi1 = pulseIn(echopin1,HIGH);   //pin echo membaca atau menerima sinyal
int jarak1 = durasi1 /58;    //rumus dalam cm


if (jarak1 > 20) //jarak (cm) dapat diatur dan disesuaikan
{
digitalWrite(merah1,1);
digitalWrite(ijo1,0);
 
  servo.write(0); 
    delay(1000);
 
}
 else if (jarak1 < 10)
{
  digitalWrite(merah1,0);
digitalWrite(ijo1,1);

 servo.write(90);
}
delay(6000);


}
