/*  AD525X_Commands.ino

    AD525X Digital potentiometer demo program.
    This code controls the Digital potentiometer and brigthens and dims 4 LEDs connected between wipper and ground with a current limiting resistor
    More documentation can be found at http://familia-herrera.com/wordpress/archives/576
    Copyright (C) 2014  Guillermo Herrera

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
    */

#include <Wire.h>

int RDAC0 = 0;
int RDAC1 = 1;
int RDAC2 = 2;
int RDAC3 = 3;

int EEMEM0= RDAC0 +32;
int EEMEM1= RDAC1 +32;
int EEMEM2= RDAC2 +32;
int EEMEM3= RDAC3 +32;

int RDACvalread;
int EEMEMvalread;
int valentered;
int address;
int num;

//Set up routine
void setup()
{
Wire.begin(); // join i2c bus (address optional for master)
}

//*********************Start Main Loop**********************
void loop()
{
int sec = 1;
for (int i = 0; i < 100; i++)
{
  writeRDAC(RDAC0,155+i); //dim LED on RDAC0
  writeRDAC(RDAC2,155+i); //dim LED on RDAC2
  delay(sec);
  writeRDAC(RDAC1,255-i); //brigthen LED on RDAC1
  writeRDAC(RDAC3,255-i); //brigthen LED on RDAC3
}
for (int i = 0; i < 256; i++)
{
  writeRDAC(RDAC0,255-i); //brigthen LED on RDAC0
  writeRDAC(RDAC2,255-i); //brigthen LED on RDAC2
  delay(sec);
  writeRDAC(RDAC1,155+i); //dim LED on RDAC1
  writeRDAC(RDAC3,155+i); //dim LED on RDAC3
}
  
}
//*************************End MAin Loop ***************************

void writeRDAC(int Num, int val)
{
  RDACWrite(Num, val);
}

void readRDAC(int Num)
{
  RDACvalread = RDACread (Num);
  Serial.println(RDACvalread,DEC);
}

//********************Start Function to Reads Current Value set for all EEMEM************
void readAllEEMEM()
{
Wire.beginTransmission(0x2c); // transmit to device U1 (0x2c or hex for 0101100)
Wire.write(0x20);
Wire.endTransmission();
Wire.requestFrom(0x2c, 4);
int eemnum = 0;
while(Wire.available())    // slave may write less than requested
{
byte eem = Wire.read(); // read a byte as character
Serial.print("EEMEM");
Serial.print(eemnum,DEC);
Serial.print(" = ");
Serial.print(eem,DEC);         // print the character
Serial.print(" ");
eemnum++;
}
Serial.println(" ");
}
//**************************END Function************************************************

// ************Start Function to Read All RDAC Current Values**********
int readAllRDAC()
{
Wire.beginTransmission(0x2c); // transmit to device U1 (0x2c or hex for 0101100)
Wire.write(0x00);
Wire.endTransmission();
Wire.requestFrom(0x2c, 4);  //Request four bytes from 
int rdacnum = 0;
while(Wire.available())    // slave may write less than requested
{
byte rdac = Wire.read(); // read a byte as character
Serial.print("RDAC");
Serial.print(rdacnum,DEC);
Serial.print(" = ");
Serial.print(rdac,DEC);         // print the character
Serial.print(" ");
rdacnum++;
}
Serial.println(" ");
}
//*****************End Function*************************************


//***************Start Function to read Individual RDAC Current Value *******************
byte RDACread(int address)
{
Wire.beginTransmission(0x2c); // transmit to device U1 (0x2c or hex for 0101100)
Wire.write(address);           //RDAC Address 0 - 3
Wire.endTransmission();
Wire.requestFrom(0x2c, 1);
byte rdac;
if(Wire.available()) {   // slave may write less than requested
rdac = Wire.read(); // read a byte as character
}
return (rdac);
}
//*********************END function*****************************************************


//************START Function to READ Indvidual EEMEM Values*****************************
byte EEMEMread(int address)
{
//address = address + 32;
Wire.beginTransmission(0x2c); // transmit to device U1 (0x2c or hex for 0101100)
Wire.write(address);         //RDAC Address 0 - 3
Wire.endTransmission();
Wire.requestFrom(0x2c, 1);
byte eem;
while(Wire.available())    // slave may write less than requested
{
eem = Wire.read(); // read a byte as character
}
return (eem);
}
//**********************END Function ****************************************************

//************************START Function to Write to individual RDAC*********************
void RDACWrite(int address, int value) {
Wire.beginTransmission(0x2c);
Wire.write(address);            // writes instruction byte to RDAC1 (0x01 or hex for 0000001)
Wire.write(value);
Wire.endTransmission();
}
//*******************************ENF Function*********************************************

//************************START Function to Write to individual EEMEM*********************
void EEMEMWrite(int address, int value) {
Wire.beginTransmission(0x2c);
Wire.write(address);            // writes Current Wipper Setting for RDAC to EEMEM (0x20 or hex for 0010000 DEC 32 for EEMEM0)
Wire.write(value);
//Wire.write(address + 32);
Wire.endTransmission();
}
//*******************************ENF Function*********************************************
