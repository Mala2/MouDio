/* My comments */

#include "Amplifier.h"
#include <Wire.h>
#include <avr/sleep.h>

// Amplifier object
Amplifier::Amplifier() {
}


void Amplifier::init(unsigned int digital_volume, unsigned int analog_gain, unsigned int Select_Fsw, unsigned int I2S_Format)  {
  //pinMode(MUTEPIN, INPUT);
  Wire.begin();
  writeReg8(TAS5825M_ADDRESS, 0x00, 0x00);
  writeReg8(TAS5825M_ADDRESS, 0x7f, 0x00);
  writeReg8(TAS5825M_ADDRESS, 0x03, 0x02);
  writeReg8(TAS5825M_ADDRESS, 0x01, 0x11);
  writeReg8(TAS5825M_ADDRESS, 0x00, 0x00);
  writeReg8(TAS5825M_ADDRESS, 0x00, 0x00);
  writeReg8(TAS5825M_ADDRESS, 0x00, 0x00);
  writeReg8(TAS5825M_ADDRESS, 0x00, 0x00);
  writeReg8(TAS5825M_ADDRESS, 0x00, 0x00);

  writeReg8(TAS5825M_ADDRESS, 0x7f, 0x00);
  writeReg8(TAS5825M_ADDRESS, 0x7d, 0x11);
  writeReg8(TAS5825M_ADDRESS, 0x7e, 0xff);
  writeReg8(TAS5825M_ADDRESS, 0x00, 0x01);
  writeReg8(TAS5825M_ADDRESS, 0x51, 0x05);
  writeReg8(TAS5825M_ADDRESS, 0x00, 0x02);
  writeReg8(TAS5825M_ADDRESS, 0x19, 0xa0);
  writeReg8(TAS5825M_ADDRESS, 0x1d, 0x01);
  writeReg8(TAS5825M_ADDRESS, 0x00, 0x00);
  writeReg8(TAS5825M_ADDRESS, 0x7f, 0x00);
  writeReg8(TAS5825M_ADDRESS, 0x46, 0x01);
  writeReg8(TAS5825M_ADDRESS, 0x00, 0x00);
  writeReg8(TAS5825M_ADDRESS, 0x02, 0x40);// DEVICE_CTRL_1
  writeReg8(TAS5825M_ADDRESS, 0x53, 0x60);
  writeReg8(TAS5825M_ADDRESS, 0x54, 0x00);
  writeReg8(TAS5825M_ADDRESS, 0x00, 0x00);
  writeReg8(TAS5825M_ADDRESS, 0x7f, 0x00);
  writeReg8(TAS5825M_ADDRESS, 0x03, 0x02);

        delay(5);

  writeReg8(TAS5825M_ADDRESS, 0x00, 0x00);
  writeReg8(TAS5825M_ADDRESS, 0x00, 0x00);
  writeReg8(TAS5825M_ADDRESS, 0x00, 0x00);
  writeReg8(TAS5825M_ADDRESS, 0x00, 0x00);
  writeReg8(TAS5825M_ADDRESS, 0x7f, 0x8c);
  writeReg8(TAS5825M_ADDRESS, 0x00, 0x06);
  writeReg8(TAS5825M_ADDRESS, 0x38, 0x00);
  writeReg8(TAS5825M_ADDRESS, 0x39, 0x00);
  writeReg8(TAS5825M_ADDRESS, 0x3a, 0x04);
  writeReg8(TAS5825M_ADDRESS, 0x3b, 0x00);

//Tuning coeffs

  writeReg8(TAS5825M_ADDRESS, 0x00, 0x0b);
  writeReg8(TAS5825M_ADDRESS, 0x50, 0x00);
  writeReg8(TAS5825M_ADDRESS, 0x51, 0x20);
  writeReg8(TAS5825M_ADDRESS, 0x52, 0xc4);
  writeReg8(TAS5825M_ADDRESS, 0x53, 0x9c);
  writeReg8(TAS5825M_ADDRESS, 0x5c, 0x7f);
  writeReg8(TAS5825M_ADDRESS, 0x5d, 0xff);
  writeReg8(TAS5825M_ADDRESS, 0x5e, 0xff);
  writeReg8(TAS5825M_ADDRESS, 0x5f, 0xff);

// Book 0x8c

  writeReg8(TAS5825M_ADDRESS, 0x00, 0x00);
  writeReg8(TAS5825M_ADDRESS, 0x7f, 0x8c);

  writeReg8(TAS5825M_ADDRESS, 0x00, 0x01);
  writeReg8(TAS5825M_ADDRESS, 0x28, 0x40);
  writeReg8(TAS5825M_ADDRESS, 0x29, 0x00);
  writeReg8(TAS5825M_ADDRESS, 0x2a, 0x00);
  writeReg8(TAS5825M_ADDRESS, 0x2b, 0x00);

  writeReg8(TAS5825M_ADDRESS, 0x00, 0x0a);
  writeReg8(TAS5825M_ADDRESS, 0x64, 0x00);
  writeReg8(TAS5825M_ADDRESS, 0x65, 0x80);
  writeReg8(TAS5825M_ADDRESS, 0x66, 0x00);
  writeReg8(TAS5825M_ADDRESS, 0x67, 0x00);
  writeReg8(TAS5825M_ADDRESS, 0x68, 0x00);
  writeReg8(TAS5825M_ADDRESS, 0x69, 0x00);
  writeReg8(TAS5825M_ADDRESS, 0x6a, 0x00);
  writeReg8(TAS5825M_ADDRESS, 0x6b, 0x00);
  writeReg8(TAS5825M_ADDRESS, 0x6c, 0x00);
  writeReg8(TAS5825M_ADDRESS, 0x6d, 0x00);
  writeReg8(TAS5825M_ADDRESS, 0x6e, 0x00);
  writeReg8(TAS5825M_ADDRESS, 0x6f, 0x00);
  writeReg8(TAS5825M_ADDRESS, 0x70, 0x00);
  writeReg8(TAS5825M_ADDRESS, 0x71, 0x00);
  writeReg8(TAS5825M_ADDRESS, 0x72, 0x00);
  writeReg8(TAS5825M_ADDRESS, 0x73, 0x00);
  writeReg8(TAS5825M_ADDRESS, 0x74, 0x00);
  writeReg8(TAS5825M_ADDRESS, 0x75, 0x80);
  writeReg8(TAS5825M_ADDRESS, 0x76, 0x00);
  writeReg8(TAS5825M_ADDRESS, 0x77, 0x00);
  writeReg8(TAS5825M_ADDRESS, 0x78, 0x00);
  writeReg8(TAS5825M_ADDRESS, 0x79, 0x00);
  writeReg8(TAS5825M_ADDRESS, 0x7a, 0x00);
  writeReg8(TAS5825M_ADDRESS, 0x7b, 0x00);
  writeReg8(TAS5825M_ADDRESS, 0x7c, 0x00);
  writeReg8(TAS5825M_ADDRESS, 0x7d, 0x00);
  writeReg8(TAS5825M_ADDRESS, 0x7e, 0x00);
  writeReg8(TAS5825M_ADDRESS, 0x7f, 0x00);

  writeReg8(TAS5825M_ADDRESS, 0x00, 0x0b);
  writeReg8(TAS5825M_ADDRESS, 0x08, 0x00);
  writeReg8(TAS5825M_ADDRESS, 0x09, 0x80);
  writeReg8(TAS5825M_ADDRESS, 0x0a, 0x00);
  writeReg8(TAS5825M_ADDRESS, 0x0b, 0x00);

  writeReg8(TAS5825M_ADDRESS, 0x38, 0x02);
  writeReg8(TAS5825M_ADDRESS, 0x39, 0xa3);
  writeReg8(TAS5825M_ADDRESS, 0x3a, 0x9a);
  writeReg8(TAS5825M_ADDRESS, 0x3b, 0xcc);
  writeReg8(TAS5825M_ADDRESS, 0x3c, 0x00);
  writeReg8(TAS5825M_ADDRESS, 0x3d, 0x06);
  writeReg8(TAS5825M_ADDRESS, 0x3e, 0xd3);
  writeReg8(TAS5825M_ADDRESS, 0x3f, 0x72);

  writeReg8(TAS5825M_ADDRESS, 0x48, 0x04);
  writeReg8(TAS5825M_ADDRESS, 0x49, 0xc1);
  writeReg8(TAS5825M_ADDRESS, 0x4a, 0xff);
  writeReg8(TAS5825M_ADDRESS, 0x4b, 0x93);
  writeReg8(TAS5825M_ADDRESS, 0x4c, 0x01);
  writeReg8(TAS5825M_ADDRESS, 0x4d, 0x12);
  writeReg8(TAS5825M_ADDRESS, 0x4e, 0x6e);
  writeReg8(TAS5825M_ADDRESS, 0x4f, 0x98);

  writeReg8(TAS5825M_ADDRESS, 0x54, 0x7b);
  writeReg8(TAS5825M_ADDRESS, 0x55, 0x3e);
  writeReg8(TAS5825M_ADDRESS, 0x56, 0x00);
  writeReg8(TAS5825M_ADDRESS, 0x57, 0x6d);
  writeReg8(TAS5825M_ADDRESS, 0x58, 0x00);
  writeReg8(TAS5825M_ADDRESS, 0x59, 0x00);
  writeReg8(TAS5825M_ADDRESS, 0x5a, 0xae);
  writeReg8(TAS5825M_ADDRESS, 0x5b, 0xc3);

  writeReg8(TAS5825M_ADDRESS, 0x60, 0x08);
  writeReg8(TAS5825M_ADDRESS, 0x61, 0x13);
  writeReg8(TAS5825M_ADDRESS, 0x62, 0x85);
  writeReg8(TAS5825M_ADDRESS, 0x63, 0x62);
  writeReg8(TAS5825M_ADDRESS, 0x64, 0x00);
  writeReg8(TAS5825M_ADDRESS, 0x65, 0x80);
  writeReg8(TAS5825M_ADDRESS, 0x66, 0x00);
  writeReg8(TAS5825M_ADDRESS, 0x67, 0x00);

  writeReg8(TAS5825M_ADDRESS, 0x6c, 0x00);
  writeReg8(TAS5825M_ADDRESS, 0x6d, 0x78);
  writeReg8(TAS5825M_ADDRESS, 0x6e, 0xd6);
  writeReg8(TAS5825M_ADDRESS, 0x6f, 0xfd);
  writeReg8(TAS5825M_ADDRESS, 0x70, 0x00);
  writeReg8(TAS5825M_ADDRESS, 0x00, 0x00);
  writeReg8(TAS5825M_ADDRESS, 0x71, 0x08);
  writeReg8(TAS5825M_ADDRESS, 0x72, 0x13);
  writeReg8(TAS5825M_ADDRESS, 0x73, 0x85);

//Register Tuning

  writeReg8(TAS5825M_ADDRESS, 0x00, 0x00);
  writeReg8(TAS5825M_ADDRESS, 0x7f, 0x00);
  writeReg8(TAS5825M_ADDRESS, 0x30, 0x00);
  writeReg8(TAS5825M_ADDRESS, 0x60, 0x02);
  writeReg8(TAS5825M_ADDRESS, 0x62, 0x09);
  writeReg8(TAS5825M_ADDRESS, 0x4c, 0x30);
  writeReg8(TAS5825M_ADDRESS, 0x03, 0x03);
  writeReg8(TAS5825M_ADDRESS, 0x00, 0x00);
  writeReg8(TAS5825M_ADDRESS, 0x7f, 0x00);
  writeReg8(TAS5825M_ADDRESS, 0x78, 0x80);

  }

/////////////////////////////////////////////////////////////  
boolean Amplifier::btnPressed() {
  boolean data;
  if ( digitalRead(MUTEPIN) == HIGH ) {
    data = true;
  }
  else {
    data = false;
  }
  return data;
}

void Amplifier::sleepBtnWake() {
  
writeReg8(TAS5825M_ADDRESS, DEVICE_CTRL_2, B00001011);
    interrupts ();
    delay(500);
}
//////////////////////////////////////////////////////////////

int Amplifier::getDIE_ID() {
  byte data = readReg8(TAS5825M_ADDRESS, DIE_ID);
  return data;
}

int Amplifier::getCHAN_FAULT() {
  byte data = readReg8(TAS5825M_ADDRESS, CHAN_FAULT);
  return data;
}

int Amplifier::getGPIO0_SEL() {
  byte data = readReg8(TAS5825M_ADDRESS, GPIO0_SEL);
  return data;
}

int Amplifier::getGLOBAL_FAULT2() {
  byte data = readReg8(TAS5825M_ADDRESS, GLOBAL_FAULT2);
  return data;
}

int Amplifier::getWARNING() {
  byte data = readReg8(TAS5825M_ADDRESS, WARNING);
  return data;
}

int Amplifier::getFS_MON() {
  byte data = readReg8(TAS5825M_ADDRESS, FS_MON);
  return data;
}

int Amplifier::getPVDD_ADC() {
  byte data = readReg8(TAS5825M_ADDRESS, PVDD_ADC);
  return data;
}

int Amplifier::getAUTOMUTE_STATE() {
  byte data = readReg8(TAS5825M_ADDRESS, AUTOMUTE_STATE);
  return data;
}

int Amplifier::getGLOBAL_FAULT1() {
  byte data = readReg8(TAS5825M_ADDRESS, GLOBAL_FAULT1);
  return data;
}

int Amplifier::getPOWER_STATE() {
  byte data = readReg8(TAS5825M_ADDRESS, POWER_STATE);
  return data;
}

int Amplifier::getCLKDET_STATUS() {
  byte data = readReg8(TAS5825M_ADDRESS, CLKDET_STATUS);
  return data;
}

int Amplifier::getRESET_CHANGE_PAGE() {
  byte data = readReg8(TAS5825M_ADDRESS, RESET_CHANGE_PAGE);
  return data;
}

int Amplifier::getBook() {
  byte data = readReg8(TAS5825M_ADDRESS, Book);
  return data;
}

int Amplifier::getAGAIN() {
  byte data = readReg8(TAS5825M_ADDRESS, AGAIN);
  return data;
}

int Amplifier::getFAULT_CLEAR() {
  byte data = readReg8(TAS5825M_ADDRESS, FAULT_CLEAR);
  return data;
}


int Amplifier::getDIG_VOL() {
  byte data = readReg8(TAS5825M_ADDRESS, DIG_VOL);
  return data;
}

int Amplifier::getRESET_CTRL() {
  byte data = readReg8(TAS5825M_ADDRESS, RESET_CTRL);
  return data;
}

int Amplifier::getDEVICE_CTRL_1() {
  byte data = readReg8(TAS5825M_ADDRESS, DEVICE_CTRL_1);
  return data;
}


int Amplifier::getDEVICE_CTRL_2() {
  byte data = readReg8(TAS5825M_ADDRESS, DEVICE_CTRL_2);
  return data;
}

int Amplifier::getSIG_CH_CTRL() {
  byte data = readReg8(TAS5825M_ADDRESS, SIG_CH_CTRL);
  return data;
}

int Amplifier::getSAP_CTRL1() {
  byte data = readReg8(TAS5825M_ADDRESS, SAP_CTRL1);
  return data;
}

int Amplifier::getBCK() {
  byte data = readReg8(TAS5825M_ADDRESS, BCK);
  return data;
}
//////////////////////////////////////////////////////////////



byte Amplifier::readReg8(int deviceAddress, int regAddress) {
  byte data = 0;
  Wire.beginTransmission(deviceAddress);
  Wire.write(regAddress);
  Wire.endTransmission();
  Wire.requestFrom(deviceAddress, 1);
  data = Wire.read();
  return(data);
}

void Amplifier::writeReg8(int deviceAddress, int regAddress, byte data) {
  Wire.beginTransmission(deviceAddress);
  Wire.write(regAddress);
  Wire.write(data);
  Wire.endTransmission();
}

void Amplifier::writeReg16(int deviceAddress, int regAddress, word data) {
  Wire.beginTransmission(deviceAddress);
  Wire.write(regAddress);
  Wire.write(highByte(data));
  Wire.write(lowByte(data));
  Wire.endTransmission();
}

 void Amplifier::sleep_on(void){


writeReg8(TAS5825M_ADDRESS, DEVICE_CTRL_2, B00000000);
    interrupts ();
    delay(1000);
  writeReg8(TAS5825M_ADDRESS, DEVICE_CTRL_2, B00000011);
  }

void wake_AMP (void){
    
     Amplifier::writeReg8(TAS5825M_ADDRESS, DEVICE_CTRL_2, B00000011);
     
  }
  
  void sleep_AMP(void){
    
     Amplifier::writeReg8(TAS5825M_ADDRESS, DEVICE_CTRL_2, B00000000);
     
  }
