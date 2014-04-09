/*  AD525X_Exmaple1.ino

    AD525X Digital potentiometer demo program.
    This code Starts by reading all current Pots Values and the EEMEM stored values.
    The EEMEM stored values are the values that the pots start at power up.
    Pot Values are from 0 - 255 for 0 to full scale resistance.
    
    After it shows the values in the serial monitor, it requests a value for RDAC0
    Sets the wiper for RDAC0 to the corresponding resistnace and stores the value to EEMEM0
    
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

//Set up routine
void setup()
{
Serial.begin(9600);  // start serial for output
Serial.println("*********************************************************************");
Serial.println("AD525X Digital potentiometer  Copyright (C) 2014  Guillermo Herrera");
Serial.println("This program comes with ABSOLUTELY NO WARRANTY");
Serial.println("More info at http://familia-herrera.com/wordpress/archives/576");
Serial.println("*********************************************************************");
Serial.println("");
Wire.begin(); // join i2c bus (address optional for master)


//Reads all RDAC Current Values and prints them on serial
Serial.println("Current RDAC Positions out of 255");
readAllRDAC();
//byte rdac = readRDAC(0);
//Serial.print("RDAC0 Initial Value =");
//Serial.println(rdac,DEC);

//Reads all EEMEM Current Values and prints them on serial
Serial.println("Current EEMEM Positions stored out of 255");
readAllEEMEM();
//byte eem = readEEMEM(1);
//Serial.println(eem,DEC);
}

//*********************Start Main Loop**********************
void loop()
{
Serial.println("Enter a number to set RDAC0 to");
while (Serial.available() == 0);
{
 int valentered = Serial.parseInt();
 RDACWrite(RDAC0, valentered);
 delay(5);
 EEMEMWrite(EEMEM0, valentered);
 delay(5);
 
 int RDACvalread = readRDAC (0);
 delay(5);

 int EEMEMvalread = readEEMEM(EEMEM0);
 Serial.print("RDAC0 Value =");
 Serial.println(RDACvalread,DEC);
 Serial.print("EEMEM0 Saved Value =");
 Serial.println(EEMEMvalread,DEC);
}
}
//*************************End MAin Loop ***************************

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
byte readRDAC(int address)
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

//************START Function to READ Indvidual EEMEM Values*****************************
byte readEEMEM(int address)
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
