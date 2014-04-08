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
Serial.begin(9600);  // start serial for output
Wire.begin(); // join i2c bus (address optional for master)


//Reads all RDAC Current Values and prints them on serial
//readAllRDAC();
//byte rdac = readRDAC(0);
//Serial.print("RDAC0 Initial Value =");
//Serial.println(rdac,DEC);

//Reads all EEMEM Current Values and prints them on serial
//readAllEEMEM();
//byte eem = readEEMEM(1);
//Serial.println(eem,DEC);
}

//*********************Start Main Loop**********************
void loop()
{
//Serial.println("Enter one of the folowing numbers");Serial.println(" ");
//Serial.println(" 0. Read all EEMEMs and RDACs");Serial.println(" ");
//Serial.print(" 1. Read RDAC0");Serial.print("\t");Serial.print("\t");
//Serial.print(" 2. Read RDAC1");Serial.print("\t");Serial.print("\t");
//Serial.print(" 3. Read RDAC2");Serial.print("\t");Serial.print("\t");
//Serial.println(" 4. Read RDAC3");
//
//Serial.print(" 5. Read EEMEM0");Serial.print("\t");Serial.print("\t");
//Serial.print(" 6. Read EEMEM1");Serial.print("\t");Serial.print("\t");
//Serial.print(" 7. Read EEMEM2");Serial.print("\t");Serial.print("\t");
//Serial.println(" 8. Read EEMEM3");
//
//Serial.print("11. Write RDAC0");Serial.print("\t");Serial.print("\t");
//Serial.print("12. Write RDAC1");Serial.print("\t");Serial.print("\t");
//Serial.print("13. Write RDAC2");Serial.print("\t");Serial.print("\t");
//Serial.println("14. Write RDAC3");
//
//Serial.print("15. Write EEMEM0");Serial.print("\t");
//Serial.print("16. Write EEMEM1");Serial.print("\t");
//Serial.print("17. Write EEMEM2");Serial.print("\t");
//Serial.println("18. Write EEMEM3");
//Serial.println(" ");
//
//while (Serial.available() == 0);
//{
// valentered = Serial.parseInt();
//  switch (valentered)
// {
//   //Write Cases
//   case 1:
//   address = RDAC0;
//   num = 0;
//   break;
//   case 2:
//   address = RDAC1;
//   num = 1;
//   break;
//   case 3:
//   address = RDAC2;
//   num = 2;
//   break;
//   case 4:
//   address = RDAC3;
//   num = 3;
//   break;
//   case 5:
//   address = EEMEM0;
//   num = 0;
//   break;
//   case 6:
//   address = EEMEM1;
//   num = 1;
//   break;
//   case 7:
//   address = EEMEM2;
//   num = 2;
//   break;
//   case 8:
//   address = EEMEM3;
//   num = 3;
//   break;
//   
//   //Read Cases
//   case 11:
//   address = RDAC0;
//   num = 0;
//   break;
//   case 12:
//   address = RDAC1;
//   num = 1;
//   break;
//   case 13:
//   address = RDAC2;
//   num = 2;
//   break;
//   case 14:
//   address = RDAC3;
//   num = 3;
//   break;
//   case 15:
//   address = EEMEM0;
//   num = 0;
//   break;
//   case 16:
//   address = EEMEM1;
//   num = 1;
//   break;
//   case 17:
//   address = EEMEM2;
//   num = 2;
//   break;
//   case 18:
//   address = EEMEM3;
//   num = 3;
//   break;
// }
////Read operations 
// if (valentered == 0)
// {
//     readAllEEMEM();
//     readAllRDAC();
// }
// else if (valentered >= 1 && valentered <= 4)
// {
//   Serial.print("RDAC");
//   Serial.print(num,DEC);
//   Serial.print(" Value = ");
//   RDACvalread = readRDAC (address);
//   Serial.println(RDACvalread,DEC);
// }
// else if (valentered >= 5 && valentered <= 8)
// {
//   Serial.print("EEMEM");
//   Serial.print(num,DEC);
//   Serial.print(" Value = ");
//   EEMEMvalread = readEEMEM(address);
//   Serial.println(EEMEMvalread,DEC);
// }
// 
// //Write operations
//  else if (valentered >= 11 && valentered <= 14)
// {
//   Serial.print("Enter a value between 0 and 255 to send to RDAC");
//   Serial.print(num,DEC);
//   Serial.print(" and press enter ");
//   while (Serial.available() == 0);
//   {
//     valentered = Serial.parseInt(); 
//     RDACWrite(address, valentered);
//   }
// }
// else if (valentered >= 15 && valentered <= 18)
// {
//   Serial.print("Enter a value between 0 and 255 to send to RDAC");
//   Serial.print(num,DEC);
//   Serial.print(" and press enter ");
//   while (Serial.available() == 0);
//   {
//     valentered = Serial.parseInt();
//     EEMEMWrite(address, valentered);
//   }
// }
// else
// {
//   Serial.println("Not a valid selection");
// }
//   
//}
//Serial.println("");
  int sec = 1;
for (int i = 0; i < 100; i++)
{
  writeRDAC(RDAC0,155+i);
  writeRDAC(RDAC2,155+i);
  delay(sec);
  writeRDAC(RDAC1,255-i);
  writeRDAC(RDAC3,255-i);
  //readRDAC(RDAC0);
}
for (int i = 0; i < 256; i++)
{
  writeRDAC(RDAC0,255-i);
  writeRDAC(RDAC2,255-i);
  delay(sec);
  writeRDAC(RDAC1,155+i);
  writeRDAC(RDAC3,155+i);
 
  //readRDAC(RDAC0);
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
