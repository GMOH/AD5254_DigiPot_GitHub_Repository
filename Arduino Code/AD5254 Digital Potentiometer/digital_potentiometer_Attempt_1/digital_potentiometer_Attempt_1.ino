// I2C Digital Potentiometer
// by Nicholas Zambetti <http://www.zambetti.com>
// and Shawn Bonkowski <http://people.interaction-ivrea.it/s.bonkowski/>

// Demonstrates use of the Wire library
// Controls AD5171 digital potentiometer via I2C/TWI

// Created 31 March 2006

// This example code is in the public domain.

// This example code is in the public domain.


#include <Wire.h>
int led = 13;

void setup()
{
  Wire.begin(); // join i2c bus (address optional for master)
  pinMode (led, OUTPUT);
}

byte val = 0;

void loop()
{
//  Wire.beginTransmission(0x58); // transmit to device #44 (0x2c)
//                              // device address is specified in datasheet
//  //Wire.write(byte(0x00));            // sends instruction byte
//  Wire.write(0x01);              //sends address for wiper setting
//  //Wire.write(0x00);             // sends potentiometer value byte  
//  Wire.endTransmission();     // stop transmitting
//  delay(500);
  for (int i = 0; i < 1000; i++)
 { 
   digitalWrite(led, HIGH);
   delay (50);
   digitalWrite(led, LOW);
   //int twbrback = TWBR;  //i2c specific and don't understand it
   //TWBR = 12; //0x0c; // 400 khz //i2c specific and it sets the comm freq.
  Wire.beginTransmission(0x2C); // transmit to device #44 (0x2c)
                              // device address is specified in datasheet
  //Wire.write(byte(0x00));            // sends instruction byte
  //Wire.write(0x00);              //sends address for wiper setting
  Wire.write(byte(0xD8));             // sends potentiometer value byte  
  Wire.endTransmission();     // stop transmitting
  //TWBR = twbrback;   //i2c specific
  delay(50);
 }
 for (int i = 0; i < 10; i++)
 {
   digitalWrite(led, HIGH);
   delay (100);
   digitalWrite(led, LOW);
   delay (100);
 }
}

