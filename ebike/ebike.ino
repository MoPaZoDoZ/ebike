#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);



int throttle = 0;
int throttle2 = 0;
int input = 0;
int on = 0;
int rpm_count = 0;
float rpm = 0;
int rpm_count_c = 0;
int timeold = 0;
int I = 0;
int charging = 0;


void setup() {
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  pinMode(7,INPUT_PULLUP);
  pinMode(8,OUTPUT);
  pinMode(3,OUTPUT);

  //TCCR2B = (TCCR2B & 0xF8) | 0x05;
  attachInterrupt(0, motor_rpm, CHANGE);
  
  for (int I = 0; I < 5; I++)
  {
    tone(10, 1000 + I * 200);
    delay(100);
  }
  noTone(10);
  tone(10, 1000, 50);
  delay(70);
  tone(10, 2000, 50);
  delay(70);
}


void loop() {
  
  charging=!digitalRead(7);
  if(charging==1)
    {
    tone(10, 4000, 50);
    delay(1000);
    }
  else{
    input = analogRead(A0);
    throttle = max(map(input, 199, 860, 100, 0),0);
  
    rpm_count_c = rpm_count;

  
    rpm = rpm_count_c;
    rpm_count = 0;
  
    throttle2 = max(min(throttle2 + 2, throttle-rpm*3),0);
    //analogWrite(11,throttle2*2.55);
  
    if (throttle >0 && !on)
    {
     digitalWrite(8,true);
      on = 1;
      tone(10, 2000, 50);
      delay(100);
      tone(10, 2000+throttle*50, 50);
      delay(100);
    }
    else if (throttle == 0 && on)
    {
      on = 0;
      tone(10, 1000, 150);
    }
  
    if(on==1){
      digitalWrite(8,true);
      analogWrite(3, throttle2 * 2.55);
 
      }
    else{
       I+=1;
      digitalWrite(8,false);
      analogWrite(3, 0);
      }
      
    }
    delay(50);
  tone(10, 1000, 5);
  
  display.clearDisplay();
  display.setCursor(0,0);
  display.print("Throttle: ");
  display.print(input);
  display.print(" mapped: ");
  display.print(throttle2);
  display.print(" rpm: ");
  display.print(rpm);
  display.print(" rpm_count: ");
  display.print(rpm_count);
  display.print(" motor controller temp: ");
  display.print(analogRead(A3));
  display.print(" motor temp: ");
  display.print(analogRead(A1));
  display.print(" battery level: ");
  display.print(analogRead(A2)*0.0279);
  display.print("V");
  display.print(" Charging: ");
  display.print(charging);
  
  display.println("");
  
  display.display();
  
  
  Serial.print("Throttle: ");
  Serial.print(input);
  Serial.print(" mapped: ");
  Serial.print(throttle2);
  Serial.print(" rpm: ");
  Serial.print(rpm);
  Serial.print(" rpm_count: ");
  Serial.print(rpm_count);
  Serial.print(" motor controller temp: ");
  Serial.print(analogRead(A3));
  Serial.print(" motor temp: ");
  Serial.print(analogRead(A1));
  Serial.print(" battery level: ");
  Serial.print(analogRead(A2));
  Serial.print("V");
  Serial.print(" Charging: ");
  Serial.print(charging);
  
  Serial.print(" Amp1: ");
  Serial.print(analogRead(A6));
  Serial.print(" Amp2: ");
  Serial.print(analogRead(A7));
  
  Serial.println("");
  

}

 void motor_rpm(){
  rpm_count+=1;
 }
