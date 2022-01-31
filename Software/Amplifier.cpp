/* My comments */

#include "Amplifier.h"
#include <Wire.h>
#include <avr/sleep.h>

// Amplifier object
Amplifier::Amplifier() {
}

/////////////////////TAS5825M//////////////////////
void Amplifier::init()  {
    Wire.begin();
    //  Wire.setClock(400000);//I2C 400kHz
    // Header file for PurePath3 to set up the AMP as desired
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

void Amplifier::wake_AMP(void){
// Seq to turn ON the AMP
    writeReg8(TAS5825M_ADDRESS, DEVICE_CTRL_2, B00000010);//Hiz
    delay(10);
    writeReg8(TAS5825M_ADDRESS, DEVICE_CTRL_2, B00000011);//Play
    writeReg8(TAS5825M_ADDRESS, DIG_VOL, 0x30);//-0.5 dB
     }

void Amplifier::sleep_AMP(void){
// Seq to turn OFF the AMP
    writeReg8(TAS5825M_ADDRESS, DEVICE_CTRL_2, B00000010);//Hiz
    delay(10);
    writeReg8(TAS5825M_ADDRESS, DEVICE_CTRL_2, B00000001);//Sleep
    delay(5);
    writeReg8(TAS5825M_ADDRESS, DEVICE_CTRL_2, B00000000);// Deep Sleep
     }

void Amplifier::Vol_Down(void){
    //digital volume ramp down
    writeReg8(TAS5825M_ADDRESS, DIG_VOL, 0x30);//-0.5 dB
    delay(300);
    writeReg8(TAS5825M_ADDRESS, DIG_VOL, 0x32);//-0.5 dB
    delay(300);
    writeReg8(TAS5825M_ADDRESS, DIG_VOL, 0x34);//-0.5 dB
    delay(300);
    writeReg8(TAS5825M_ADDRESS, DIG_VOL, 0x36);//-0.5 dB
    delay(300);
    writeReg8(TAS5825M_ADDRESS, DIG_VOL, 0x38);//-0.5 dB
    delay(300);
    writeReg8(TAS5825M_ADDRESS, DIG_VOL, 0x3a);//-0.5 dB
    delay(300);
    writeReg8(TAS5825M_ADDRESS, DIG_VOL, 0x3c);//-0.5 dB
    delay(300);
    writeReg8(TAS5825M_ADDRESS, DIG_VOL, 0x42);//-0.5 dB
    delay(300);
    writeReg8(TAS5825M_ADDRESS, DIG_VOL, 0x44);//-0.5 dB
    delay(300);
    writeReg8(TAS5825M_ADDRESS, DIG_VOL, 0x46);//-0.5 dB
    delay(300);
    writeReg8(TAS5825M_ADDRESS, DIG_VOL, 0x48);//-0.5 dB
    delay(300);
    writeReg8(TAS5825M_ADDRESS, DIG_VOL, 0x4c);//-0.5 dB
    delay(300);
    writeReg8(TAS5825M_ADDRESS, DIG_VOL, 0x52);//-0.5 dB
    delay(300);
    writeReg8(TAS5825M_ADDRESS, DIG_VOL, 0x54);//-0.5 dB
    delay(300);
    writeReg8(TAS5825M_ADDRESS, DIG_VOL, 0x56);//-0.5 dB
    delay(300);
    writeReg8(TAS5825M_ADDRESS, DIG_VOL, 0x58);//-0.5 dB
    delay(300);
    writeReg8(TAS5825M_ADDRESS, DIG_VOL, 0x5c);//-0.5 dB
    delay(300);
    writeReg8(TAS5825M_ADDRESS, DIG_VOL, 0x62);//-0.5 dB
    delay(300);
    writeReg8(TAS5825M_ADDRESS, DIG_VOL, 0x64);//-0.5 dB
    delay(300);
    writeReg8(TAS5825M_ADDRESS, DIG_VOL, 0x66);//-0.5 dB
    delay(300);
    writeReg8(TAS5825M_ADDRESS, DIG_VOL, 0x68);//-0.5 dB
    delay(300);
    writeReg8(TAS5825M_ADDRESS, DIG_VOL, 0x6c);//-0.5 dB
    delay(300);
    writeReg8(TAS5825M_ADDRESS, DIG_VOL, 0x72);//-103 dB
    delay(300);
    writeReg8(TAS5825M_ADDRESS, DIG_VOL, 0x74);//-0.5 dB
    delay(300);
    writeReg8(TAS5825M_ADDRESS, DIG_VOL, 0x76);//-0.5 dB
    delay(300);
    writeReg8(TAS5825M_ADDRESS, DIG_VOL, 0x78);//-0.5 dB
    delay(300);
    writeReg8(TAS5825M_ADDRESS, DIG_VOL, 0x7c);//-0.5 dB
    delay(300);
    writeReg8(TAS5825M_ADDRESS, DIG_VOL, 0x82);//-0.5 dB
    delay(300);
    writeReg8(TAS5825M_ADDRESS, DIG_VOL, 0x84);//-0.5 dB
    delay(300);
    writeReg8(TAS5825M_ADDRESS, DIG_VOL, 0x86);//-0.5 dB
    delay(300);
    writeReg8(TAS5825M_ADDRESS, DIG_VOL, 0x88);//-0.5 dB
    delay(300);
    writeReg8(TAS5825M_ADDRESS, DIG_VOL, 0x8c);//-0.5 dB
    delay(300);
    writeReg8(TAS5825M_ADDRESS, DIG_VOL, 0x92);//-0.5 dB
    delay(300);
    writeReg8(TAS5825M_ADDRESS, DIG_VOL, 0x94);//-0.5 dB
    delay(300);
    writeReg8(TAS5825M_ADDRESS, DIG_VOL, 0x96);//-0.5 dB
    delay(300);
    writeReg8(TAS5825M_ADDRESS, DIG_VOL, 0x98);//-103 dB
    delay(300);
    writeReg8(TAS5825M_ADDRESS, DIG_VOL, 0x9c);//-0.5 dB
    delay(300);
    writeReg8(TAS5825M_ADDRESS, DIG_VOL, 0xa0);//-0.5 dB
    delay(300);
    writeReg8(TAS5825M_ADDRESS, DIG_VOL, 0xa5);//-0.5 dB
    delay(300);
    writeReg8(TAS5825M_ADDRESS, DIG_VOL, 0xaa);//-0.5 dB
    delay(300);
    writeReg8(TAS5825M_ADDRESS, DIG_VOL, 0xaf);//-0.5 dB
    delay(300);
    writeReg8(TAS5825M_ADDRESS, DIG_VOL, 0xb4);//-0.5 dB
    delay(300);
    writeReg8(TAS5825M_ADDRESS, DIG_VOL, 0xb9);//-0.5 dB
    delay(300);
    writeReg8(TAS5825M_ADDRESS, DIG_VOL, 0xbe);//-0.5 dB
    delay(300);
    writeReg8(TAS5825M_ADDRESS, DIG_VOL, 0xc3);//-0.5 dB
    delay(300);
    writeReg8(TAS5825M_ADDRESS, DIG_VOL, 0xc8);//-103 dB
    delay(300);
    writeReg8(TAS5825M_ADDRESS, DIG_VOL, 0xcd);//-0.5 dB
    delay(300);
    writeReg8(TAS5825M_ADDRESS, DIG_VOL, 0xd2);//-0.5 dB
    delay(300);
    writeReg8(TAS5825M_ADDRESS, DIG_VOL, 0xd7);//-0.5 dB
    delay(300);
    writeReg8(TAS5825M_ADDRESS, DIG_VOL, 0xdc);//-103 dB
    delay(300);
    writeReg8(TAS5825M_ADDRESS, DIG_VOL, 0xe1);//-0.5 dB
    delay(300);
    writeReg8(TAS5825M_ADDRESS, DIG_VOL, 0xe6);//-0.5 dB
    delay(300);
    writeReg8(TAS5825M_ADDRESS, DIG_VOL, 0xeb);//-0.5 dB
    delay(300);
    writeReg8(TAS5825M_ADDRESS, DIG_VOL, 0xf0);//-0.5 dB
    delay(300);
    writeReg8(TAS5825M_ADDRESS, DIG_VOL, 0xf5);//-0.5 dB
    delay(300);
    writeReg8(TAS5825M_ADDRESS, DIG_VOL, 0xfa);//-0.5 dB
    delay(300);
    writeReg8(TAS5825M_ADDRESS, DIG_VOL, 0xff);//Mute
    }

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

int Amplifier::getPOWER_STATE() {
  byte data = readReg8(TAS5825M_ADDRESS, POWER_STATE);
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

////////////////////IS31FL3195////////////////////

void Amplifier::init_IS31FL3195(){
  writeReg8(IS31_ADDRESS,0x01,0xF1);//Normal operation
  writeReg8(IS31_ADDRESS,0x02,0x80);//LED mode choose
  writeReg8(IS31_ADDRESS,0x03,0x00);//Charge Pump Setting-1
  writeReg8(IS31_ADDRESS,0x05,0xFF);//Current Band Setting
  }

void Amplifier::Mode_IS31FL3195(){
  writeReg8(IS31_ADDRESS,0x10,0x00);
  writeReg8(IS31_ADDRESS,0x21,0x00);
  writeReg8(IS31_ADDRESS,0x32,0x00);
  }

void show_LED(void){

  }

void Amplifier::sleep_led(void){
  writeReg8(IS31_ADDRESS,0x01,0x04);//Normal operation
  }

void Amplifier::show_led_0(void){
   writeReg8(IS31_ADDRESS,0x01,0xF1);//Normal operation
   writeReg8(IS31_ADDRESS,0x02,0x10);//LED mode choose
   writeReg8(IS31_ADDRESS,0x03,0x00);//Charge Pump Setting-1
   writeReg8(IS31_ADDRESS,0x05,0xFF);//Current Band Setting

   writeReg8(IS31_ADDRESS,0x10,0x00);
   writeReg8(IS31_ADDRESS,0x21,0x00);
   writeReg8(IS31_ADDRESS,0x32,0x00);
   writeReg8(IS31_ADDRESS,0x40,0x00);

   writeReg8(IS31_ADDRESS,0x1D,0x00);//Color Cycle Times
   writeReg8(IS31_ADDRESS,0x1C,0x07);//P4 Color Enable
   writeReg8(IS31_ADDRESS,0x19,0x44);//TS &T1 Setting
   writeReg8(IS31_ADDRESS,0x1A,0x44);//T2 &T3 Setting
   writeReg8(IS31_ADDRESS,0x1B,0x44);//TP &T4 Setting
   writeReg8(IS31_ADDRESS,0x1E,0x11);//P1 NXT
   writeReg8(IS31_ADDRESS,0x1F,0x01);//Loop Times

   writeReg8(IS31_ADDRESS,0x10,0x01);
   writeReg8(IS31_ADDRESS,0x13,0x01);
   writeReg8(IS31_ADDRESS,0x16,0x01);

   writeReg8(IS31_ADDRESS,0x50,0x00);
   writeReg8(IS31_ADDRESS,0x51,0x00);
   writeReg8(IS31_ADDRESS,0x52,0x00);
   writeReg8(IS31_ADDRESS,0x53,0x00);
   writeReg8(IS31_ADDRESS,0x54,0x00);
   }

void Amplifier::show_led_25(void){
   writeReg8(IS31_ADDRESS,0x01,0xF1);//Normal operation
   writeReg8(IS31_ADDRESS,0x02,0x20);//LED mode choose
   writeReg8(IS31_ADDRESS,0x03,0x00);//Charge Pump Setting-1
   writeReg8(IS31_ADDRESS,0x05,0xFF);//Current Band Setting

   writeReg8(IS31_ADDRESS,0x10,0xFF);
   writeReg8(IS31_ADDRESS,0x21,0x00);
   writeReg8(IS31_ADDRESS,0x32,0x00);
   writeReg8(IS31_ADDRESS,0x40,0x00);

   writeReg8(IS31_ADDRESS,0x2D,0x00);//Color Cycle Times
   writeReg8(IS31_ADDRESS,0x2C,0x07);//P4 Color Enable
   writeReg8(IS31_ADDRESS,0x29,0x44);//TS &T1 Setting
   writeReg8(IS31_ADDRESS,0x2A,0x44);//T2 &T3 Setting
   writeReg8(IS31_ADDRESS,0x2B,0x44);//TP &T4 Setting
   writeReg8(IS31_ADDRESS,0x2E,0x11);//P2 NXT
   writeReg8(IS31_ADDRESS,0x2F,0x01);//Loop Times

   writeReg8(IS31_ADDRESS,0x21,0x3f);
   writeReg8(IS31_ADDRESS,0x24,0x3f);
   writeReg8(IS31_ADDRESS,0x27,0x3f);

   writeReg8(IS31_ADDRESS,0x50,0x00);
   writeReg8(IS31_ADDRESS,0x51,0x00);
   writeReg8(IS31_ADDRESS,0x52,0x00);
   writeReg8(IS31_ADDRESS,0x53,0x00);
   writeReg8(IS31_ADDRESS,0x54,0x00);
   }

void Amplifier::show_led_50(void){
   writeReg8(IS31_ADDRESS,0x01,0xF1);//Normal operation
   writeReg8(IS31_ADDRESS,0x02,0x40);//LED mode choose SINGLE/PATTERN/3-PATTERN
   writeReg8(IS31_ADDRESS,0x03,0x00);//Charge Pump Setting-1
   writeReg8(IS31_ADDRESS,0x05,0xFF);//Current Band Setting MAX

   writeReg8(IS31_ADDRESS,0x10,0xFF);//1-ON
   writeReg8(IS31_ADDRESS,0x21,0xFF);//2-ON
   writeReg8(IS31_ADDRESS,0x32,0x00);//3-PATTERN
   writeReg8(IS31_ADDRESS,0x40,0x00);//4-OFF

   writeReg8(IS31_ADDRESS,0x3D,0x00);//Color Cycle Times
   writeReg8(IS31_ADDRESS,0x3C,0x07);//P4 Color Enable
   writeReg8(IS31_ADDRESS,0x39,0x44);//TS &T1 Setting
   writeReg8(IS31_ADDRESS,0x3A,0x44);//T2 &T3 Setting
   writeReg8(IS31_ADDRESS,0x3B,0x44);//TP &T4 Setting
   writeReg8(IS31_ADDRESS,0x3E,0x11);//P3 NXT
   writeReg8(IS31_ADDRESS,0x3F,0x01);//Loop

   writeReg8(IS31_ADDRESS,0x32,0xff);//BRIGHTENEES
   writeReg8(IS31_ADDRESS,0x35,0xff);
   writeReg8(IS31_ADDRESS,0x38,0xff);

   writeReg8(IS31_ADDRESS,0x50,0x00);//UPDATE
   writeReg8(IS31_ADDRESS,0x51,0x00);
   writeReg8(IS31_ADDRESS,0x52,0x00);
   writeReg8(IS31_ADDRESS,0x53,0x00);
   writeReg8(IS31_ADDRESS,0x54,0x00);
   }

void Amplifier::show_led_75(void){
   writeReg8(IS31_ADDRESS,0x01,0xF1);//Normal operation
   writeReg8(IS31_ADDRESS,0x02,0x80);//LED mode choose
   writeReg8(IS31_ADDRESS,0x03,0x00);//Charge Pump Setting-1
   writeReg8(IS31_ADDRESS,0x05,0xFF);//Current Band Setting

   writeReg8(IS31_ADDRESS,0x10,0xFF);
   writeReg8(IS31_ADDRESS,0x21,0xFF);
   writeReg8(IS31_ADDRESS,0x32,0xFF);
   writeReg8(IS31_ADDRESS,0x40,0x00);

   //P4 time and cycle
   writeReg8(IS31_ADDRESS,0x4D,0x00);//Color Cycle Times
   writeReg8(IS31_ADDRESS,0x4C,0x07);//P4 Color Enable
   writeReg8(IS31_ADDRESS,0x49,0x44);//TS &T1 Setting
   writeReg8(IS31_ADDRESS,0x4A,0x44);//T2 &T3 Setting
   writeReg8(IS31_ADDRESS,0x4B,0x44);//TP &T4 Setting
   writeReg8(IS31_ADDRESS,0x4E,0x11);//P4 NXT
   writeReg8(IS31_ADDRESS,0x4F,0x01);//Loop Times

   writeReg8(IS31_ADDRESS,0x40,0xff);
   writeReg8(IS31_ADDRESS,0x41,0xff);
   writeReg8(IS31_ADDRESS,0x42,0xff);

   writeReg8(IS31_ADDRESS,0x50,0x00);
   writeReg8(IS31_ADDRESS,0x51,0x00);
   writeReg8(IS31_ADDRESS,0x52,0x00);
   writeReg8(IS31_ADDRESS,0x53,0x00);
   writeReg8(IS31_ADDRESS,0x54,0x00);
   }

void Amplifier::show_led_100(void){
   writeReg8(IS31_ADDRESS,0x01,0xF1);//Normal operation
   writeReg8(IS31_ADDRESS,0x02,0xF0);//LED mode choose
   writeReg8(IS31_ADDRESS,0x03,0x00);//Charge Pump Setting-1
   writeReg8(IS31_ADDRESS,0x05,0xFF);//Current Band Setting

   writeReg8(IS31_ADDRESS,0x10,0xFF);
   writeReg8(IS31_ADDRESS,0x21,0xFF);
   writeReg8(IS31_ADDRESS,0x32,0xFF);
   writeReg8(IS31_ADDRESS,0x40,0x00);

   //P4 time and cycle
   writeReg8(IS31_ADDRESS,0x1D,0x00);//Color Cycle Times
   writeReg8(IS31_ADDRESS,0x1C,0x07);//P4 Color Enable
   writeReg8(IS31_ADDRESS,0x19,0x58);//TS &T1 Setting
   writeReg8(IS31_ADDRESS,0x1A,0x58);//T2 &T3 Setting
   writeReg8(IS31_ADDRESS,0x1B,0x44);//TP &T4 Setting
   writeReg8(IS31_ADDRESS,0x1E,0x11);//P1 NXT
   writeReg8(IS31_ADDRESS,0x1F,0x01);//Loop Times

   writeReg8(IS31_ADDRESS,0x2D,0x00);//Color Cycle Times
   writeReg8(IS31_ADDRESS,0x2C,0x07);//P4 Color Enable
   writeReg8(IS31_ADDRESS,0x29,0x58);//TS &T1 Setting
   writeReg8(IS31_ADDRESS,0x2A,0x58);//T2 &T3 Setting
   writeReg8(IS31_ADDRESS,0x2B,0x44);//TP &T4 Setting
   writeReg8(IS31_ADDRESS,0x2E,0x11);//P2 NXT
   writeReg8(IS31_ADDRESS,0x2F,0x01);//Loop Times

   writeReg8(IS31_ADDRESS,0x3D,0x00);//Color Cycle Times
   writeReg8(IS31_ADDRESS,0x3C,0x07);//P4 Color Enable
   writeReg8(IS31_ADDRESS,0x39,0x58);//TS &T1 Setting
   writeReg8(IS31_ADDRESS,0x3A,0x58);//T2 &T3 Setting
   writeReg8(IS31_ADDRESS,0x3B,0x44);//TP &T4 Setting
   writeReg8(IS31_ADDRESS,0x3E,0x11);//P3 NXT
   writeReg8(IS31_ADDRESS,0x3F,0x01);//Loop

   writeReg8(IS31_ADDRESS,0x4D,0x00);//Color Cycle Times
   writeReg8(IS31_ADDRESS,0x4C,0x07);//P4 Color Enable
   writeReg8(IS31_ADDRESS,0x49,0x58);//TS &T1 Setting
   writeReg8(IS31_ADDRESS,0x4A,0x58);//T2 &T3 Setting
   writeReg8(IS31_ADDRESS,0x4B,0x44);//TP &T4 Setting
   writeReg8(IS31_ADDRESS,0x4E,0x11);//P4 NXT
   writeReg8(IS31_ADDRESS,0x4F,0x01);//Loop Times

   writeReg8(IS31_ADDRESS,0x40,0xff);
   writeReg8(IS31_ADDRESS,0x41,0xff);
   writeReg8(IS31_ADDRESS,0x42,0xff);

   writeReg8(IS31_ADDRESS,0x50,0x00);
   writeReg8(IS31_ADDRESS,0x51,0x00);
   writeReg8(IS31_ADDRESS,0x52,0x00);
   writeReg8(IS31_ADDRESS,0x53,0x00);
   writeReg8(IS31_ADDRESS,0x54,0x00);
   }

void Amplifier::show_led_0_flash(void){
   writeReg8(IS31_ADDRESS,0x01,0xF1);//normal operation
   writeReg8(IS31_ADDRESS,0x02,0x10);//LED mode choose
   writeReg8(IS31_ADDRESS,0x03,0x00);//Charge Pump Setting-1
   writeReg8(IS31_ADDRESS,0x05,0xFF);//Current Band Setting

   writeReg8(IS31_ADDRESS,0x10,0x00);
   writeReg8(IS31_ADDRESS,0x21,0x00);
   writeReg8(IS31_ADDRESS,0x32,0x00);
   writeReg8(IS31_ADDRESS,0x40,0x00);

   writeReg8(IS31_ADDRESS,0x1D,0x00);//Color Cycle Times
   writeReg8(IS31_ADDRESS,0x1C,0x07);//P4 Color Enable
   writeReg8(IS31_ADDRESS,0x19,0x11);//TS &T1 Setting
   writeReg8(IS31_ADDRESS,0x1A,0x11);//T2 &T3 Setting
   writeReg8(IS31_ADDRESS,0x1B,0x11);//TP &T4 Setting
   writeReg8(IS31_ADDRESS,0x1E,0x11);//P1 NXT
   writeReg8(IS31_ADDRESS,0x1F,0x01);//Loop Times

   writeReg8(IS31_ADDRESS,0x10,0x01);
   writeReg8(IS31_ADDRESS,0x13,0x01);
   writeReg8(IS31_ADDRESS,0x16,0x01);

   writeReg8(IS31_ADDRESS,0x50,0x00);
   writeReg8(IS31_ADDRESS,0x51,0x00);
   writeReg8(IS31_ADDRESS,0x52,0x00);
   writeReg8(IS31_ADDRESS,0x53,0x00);
   writeReg8(IS31_ADDRESS,0x54,0x00);
   }

void Amplifier::show_led_25_solid(void){
   writeReg8(IS31_ADDRESS,0x01,0xF1);//normal operation
   writeReg8(IS31_ADDRESS,0x02,0x00);//LED mode choose
   writeReg8(IS31_ADDRESS,0x03,0x00);//Charge Pump Setting-1
   writeReg8(IS31_ADDRESS,0x05,0xFF);//Current Band Setting

   writeReg8(IS31_ADDRESS,0x10,0xFF);
   writeReg8(IS31_ADDRESS,0x21,0x00);
   writeReg8(IS31_ADDRESS,0x32,0x00);
   writeReg8(IS31_ADDRESS,0x40,0x00);

   writeReg8(IS31_ADDRESS,0x50,0x00);
   writeReg8(IS31_ADDRESS,0x51,0x00);
   writeReg8(IS31_ADDRESS,0x52,0x00);
   writeReg8(IS31_ADDRESS,0x53,0x00);
   writeReg8(IS31_ADDRESS,0x54,0x00);
   }

void Amplifier::show_led_50_solid(void){
   writeReg8(IS31_ADDRESS,0x01,0xF1);//normal operation
   writeReg8(IS31_ADDRESS,0x02,0x00);//LED mode choose SINGLE/PATTERN/3-PATTERN
   writeReg8(IS31_ADDRESS,0x03,0x00);//Charge Pump Setting-1
   writeReg8(IS31_ADDRESS,0x05,0xFF);//Current Band Setting MAX

   writeReg8(IS31_ADDRESS,0x10,0xFF);//1-ON
   writeReg8(IS31_ADDRESS,0x21,0xFF);//2-ON
   writeReg8(IS31_ADDRESS,0x32,0x00);//3-PATTERN
   writeReg8(IS31_ADDRESS,0x40,0x00);//4-OFF

   writeReg8(IS31_ADDRESS,0x50,0x00);//UPDATE
   writeReg8(IS31_ADDRESS,0x51,0x00);
   writeReg8(IS31_ADDRESS,0x52,0x00);
   writeReg8(IS31_ADDRESS,0x53,0x00);
   writeReg8(IS31_ADDRESS,0x54,0x00);
   }

void Amplifier::show_led_75_solid(void){
   writeReg8(IS31_ADDRESS,0x01,0xF1);//normal operation
   writeReg8(IS31_ADDRESS,0x02,0x00);//LED mode choose
   writeReg8(IS31_ADDRESS,0x03,0x00);//Charge Pump Setting-1
   writeReg8(IS31_ADDRESS,0x05,0xFF);//Current Band Setting

   writeReg8(IS31_ADDRESS,0x10,0xFF);
   writeReg8(IS31_ADDRESS,0x21,0xFF);
   writeReg8(IS31_ADDRESS,0x32,0xFF);
   writeReg8(IS31_ADDRESS,0x40,0x00);

   writeReg8(IS31_ADDRESS,0x50,0x00);
   writeReg8(IS31_ADDRESS,0x51,0x00);
   writeReg8(IS31_ADDRESS,0x52,0x00);
   writeReg8(IS31_ADDRESS,0x53,0x00);
   writeReg8(IS31_ADDRESS,0x54,0x00);
   }

void Amplifier::show_led_100_solid(void){
   writeReg8(IS31_ADDRESS,0x01,0xF1);//normal operation
   writeReg8(IS31_ADDRESS,0x02,0x00);//LED mode choose
   writeReg8(IS31_ADDRESS,0x03,0x00);//Charge Pump Setting-1
   writeReg8(IS31_ADDRESS,0x05,0xFF);//Current Band Setting

   writeReg8(IS31_ADDRESS,0x10,0xFF);
   writeReg8(IS31_ADDRESS,0x21,0xFF);
   writeReg8(IS31_ADDRESS,0x32,0xFF);
   writeReg8(IS31_ADDRESS,0x40,0xFF);

   writeReg8(IS31_ADDRESS,0x50,0x00);
   writeReg8(IS31_ADDRESS,0x51,0x00);
   writeReg8(IS31_ADDRESS,0x52,0x00);
   writeReg8(IS31_ADDRESS,0x53,0x00);
   writeReg8(IS31_ADDRESS,0x54,0x00);
   }
//////////motions:

void Amplifier::show_led_Next(void){
   writeReg8(IS31_ADDRESS,0x01,0xF1);//Normal operation
   writeReg8(IS31_ADDRESS,0x02,0xF0);//LED mode choose
   writeReg8(IS31_ADDRESS,0x03,0x00);//Charge Pump Setting-1
   writeReg8(IS31_ADDRESS,0x05,0xFF);//Current Band Setting

   writeReg8(IS31_ADDRESS,0x10,0xFF);
   writeReg8(IS31_ADDRESS,0x21,0xFF);
   writeReg8(IS31_ADDRESS,0x32,0xFF);
   writeReg8(IS31_ADDRESS,0x40,0xFF);

   //P1-P4 time and cycle
   writeReg8(IS31_ADDRESS,0x1D,0x01);//Color Cycle Times
   writeReg8(IS31_ADDRESS,0x1C,0x07);//P4 Color Enable
   writeReg8(IS31_ADDRESS,0x19,0x10);//TS &T1 Setting
   writeReg8(IS31_ADDRESS,0x1A,0x40);//T2 &T3 Setting
   writeReg8(IS31_ADDRESS,0x1B,0xff);//TP &T4 Setting
   writeReg8(IS31_ADDRESS,0x1E,0x11);//P1 NXT
   writeReg8(IS31_ADDRESS,0x1F,0x01);//Loop Times

   writeReg8(IS31_ADDRESS,0x2D,0x01);//Color Cycle Times
   writeReg8(IS31_ADDRESS,0x2C,0x07);//P4 Color Enable
   writeReg8(IS31_ADDRESS,0x29,0x20);//TS &T1 Setting
   writeReg8(IS31_ADDRESS,0x2A,0x30);//T2 &T3 Setting
   writeReg8(IS31_ADDRESS,0x2B,0xff);//TP &T4 Setting
   writeReg8(IS31_ADDRESS,0x2E,0x11);//P2 NXT
   writeReg8(IS31_ADDRESS,0x2F,0x01);//Loop Times

   writeReg8(IS31_ADDRESS,0x3D,0x01);//Color Cycle Times
   writeReg8(IS31_ADDRESS,0x3C,0x07);//P4 Color Enable
   writeReg8(IS31_ADDRESS,0x39,0x30);//TS &T1 Setting
   writeReg8(IS31_ADDRESS,0x3A,0x20);//T2 &T3 Setting
   writeReg8(IS31_ADDRESS,0x3B,0xff);//TP &T4 Setting
   writeReg8(IS31_ADDRESS,0x3E,0x11);//P3 NXT
   writeReg8(IS31_ADDRESS,0x3F,0x01);//Loop

   writeReg8(IS31_ADDRESS,0x4D,0x01);//Color Cycle Times
   writeReg8(IS31_ADDRESS,0x4C,0x07);//P4 Color Enable
   writeReg8(IS31_ADDRESS,0x49,0x40);//TS &T1 Setting
   writeReg8(IS31_ADDRESS,0x4A,0x10);//T2 &T3 Setting
   writeReg8(IS31_ADDRESS,0x4B,0xff);//TP &T4 Setting
   writeReg8(IS31_ADDRESS,0x4E,0x11);//P4 NXT
   writeReg8(IS31_ADDRESS,0x4F,0x01);//Loop Times

   writeReg8(IS31_ADDRESS,0x10,0xff);
   writeReg8(IS31_ADDRESS,0x13,0xff);
   writeReg8(IS31_ADDRESS,0x16,0xff);
   writeReg8(IS31_ADDRESS,0x21,0xff);
   writeReg8(IS31_ADDRESS,0x24,0xff);
   writeReg8(IS31_ADDRESS,0x27,0xff);
   writeReg8(IS31_ADDRESS,0x32,0xff);//BRIGHTENEES
   writeReg8(IS31_ADDRESS,0x35,0xff);
   writeReg8(IS31_ADDRESS,0x38,0xff);
   writeReg8(IS31_ADDRESS,0x40,0xff);
   writeReg8(IS31_ADDRESS,0x41,0xff);
   writeReg8(IS31_ADDRESS,0x42,0xff);

   writeReg8(IS31_ADDRESS,0x50,0x00);
   writeReg8(IS31_ADDRESS,0x51,0x00);
   writeReg8(IS31_ADDRESS,0x52,0x00);
   writeReg8(IS31_ADDRESS,0x53,0x00);
   writeReg8(IS31_ADDRESS,0x54,0x00);
   }

////////////////////MAX77962//////////////////////

int Amplifier::get_bat_stat(void){
    int retval = -1;
    Wire.beginTransmission(MAX77962_READ_ADDRESS);
    Wire.write(0x14);
    Wire.endTransmission();
    Wire.requestFrom(MAX77962_READ_ADDRESS,1);
    if (Wire.available()<=1)
     retval = (Wire.read());
    return(retval);
    }

void Amplifier::otg_on(void){
    Wire.beginTransmission(MAX77962_READ_ADDRESS);
    Wire.write(CHG_CNFG_00);
    Wire.write(0x0A);// Charge=ON, OTG=ON, DCDC=ON
    Wire.endTransmission();
    }
void  Amplifier::otg_off(void){
    Wire.beginTransmission(MAX77962_READ_ADDRESS);
    Wire.write(CHG_CNFG_00);
    Wire.write(0x05);// Charge=ON, OTG=OFF, DCDC=ON
    Wire.endTransmission();
    }

Amplifier::put_bat_voltage(void){
    Wire.beginTransmission(MAX77962_READ_ADDRESS);
    Wire.write(CHG_CNFG_06);
    Wire.write(0x8c);// Unlock writing and EN fast charge current
    Wire.endTransmission();

    Wire.beginTransmission(MAX77962_READ_ADDRESS);
    Wire.write(CHG_CNFG_08);
    Wire.write(0x79);// CHGIN Input Current Limit 3000mA
    Wire.endTransmission();

    Wire.beginTransmission(MAX77962_READ_ADDRESS);
    Wire.write(CHG_CNFG_02);
//  Wire.write(0x1);
    Wire.write(0xD8);// Fast Charge Current Limit 3000mA
    Wire.endTransmission();

    Wire.beginTransmission(MAX77962_READ_ADDRESS);
    Wire.write(CHG_CNFG_04);
    Wire.write(0xB2);// Charge Termenatin Voltage 8.4V **why not 32
    Wire.endTransmission();



  int retval = -1;

    Wire.beginTransmission(MAX77962_READ_ADDRESS);
    Wire.write(CHG_CNFG_04);
    Wire.endTransmission();
    Wire.requestFrom(MAX77962_READ_ADDRESS,1);
    if (Wire.available()<=1)
    retval = (Wire.read());
//    Serial.println(retval, HEX);
    Wire.beginTransmission(MAX77962_READ_ADDRESS);
    Wire.write(CHG_CNFG_02);
    Wire.endTransmission();
    Wire.requestFrom(MAX77962_READ_ADDRESS,1);
    if (Wire.available()<=1)
    retval = (Wire.read());
//    Serial.println(retval, HEX);
     // delay(1000);
   }

//////////////////////////////////////////////////////////////

int Amplifier::getCHG_DETAILS_00() {
  byte data = readReg16(MAX77962_READ_ADDRESS, CHG_DETAILS_00);
  return data;
}
int Amplifier::getCHG_DETAILS_01() {
  byte data = readReg16(MAX77962_READ_ADDRESS, CHG_DETAILS_01);
  return data;
}
int Amplifier::getCHG_DETAILS_02() {
  byte data = readReg16(MAX77962_READ_ADDRESS, CHG_DETAILS_02);
  return data;
}
int Amplifier::getCHG_CNFG_00() {
  byte data = readReg16(MAX77962_READ_ADDRESS, CHG_CNFG_00);
  return data;
}
int Amplifier::getCHG_CNFG_01() {
  byte data = readReg16(MAX77962_READ_ADDRESS, CHG_CNFG_01);
  return data;
}
int Amplifier::getCHG_CNFG_02() {
  byte data = readReg16(MAX77962_READ_ADDRESS, CHG_CNFG_02);
  return data;
}
int Amplifier::getCHG_CNFG_03() {
  byte data = readReg16(MAX77962_READ_ADDRESS, CHG_CNFG_03);
  return data;
}
int Amplifier::getCHG_CNFG_04() {
  byte data = readReg16(MAX77962_READ_ADDRESS, CHG_CNFG_04);
  return data;
}
int Amplifier::getCHG_CNFG_05() {
  byte data = readReg16(MAX77962_READ_ADDRESS, CHG_CNFG_05);
  return data;
}
int Amplifier::getCHG_CNFG_06() {
  byte data = readReg16(MAX77962_READ_ADDRESS, CHG_CNFG_05);
  return data;
}
int Amplifier::getCHG_CNFG_07() {
  byte data = readReg16(MAX77962_READ_ADDRESS, CHG_CNFG_07);
  return data;
}
int Amplifier::getCHG_CNFG_08() {
  byte data = readReg16(MAX77962_READ_ADDRESS, CHG_CNFG_08);
  return data;
}
int Amplifier::getCHG_CNFG_09() {
  byte data = readReg16(MAX77962_READ_ADDRESS, CHG_CNFG_09);
  return data;
}
int Amplifier::getCHG_CNFG_10() {
  byte data = readReg16(MAX77962_READ_ADDRESS, CHG_CNFG_10);
  return data;
}


/////////////////////MAX17320//////////////////////


bool Amplifier::begin()
{
  this->_address = MAX17320;
  return this->begin(true, this->_address);
}

bool Amplifier::begin(bool initializeWire)
{
  this->_address = MAX17320;
  return this->begin(initializeWire, this->_address);
}

bool Amplifier::begin(bool initializeWire, uint8_t address)
{
  bool returnValue = false;

  this->_address = address;


    returnValue = true;


  return returnValue;
}

bool Amplifier::begin(TwoWire* wire)
{
  this->_wire = wire;
  return this->begin();
}

bool Amplifier::begin(TwoWire* wire, uint8_t address)
{
  this->_wire = wire;
  return this->begin(address);
}

bool Amplifier::begin(TwoWire* wire, bool initializeWire, uint8_t address)
{
  this->_wire = wire;
  return this->begin(initializeWire, address);
}

uint8_t Amplifier::address()
{
  return this->_address;
}

float Amplifier::BATpercent()
{
  //
  // Read the 16-bit register value
  //
  uint16_t value = 0;//this->readRegister16(REGISTER_SOC);

  //
  // The high byte is the percentage.
  //
  //float percentage = (float)toHighByte(registerValue);

  //
  // The low byte contains additional resolution of 1/256%.
  //
  readRegister_16_N(RepSOC , &value);
  float fraction = ((float)(value) / 256.f);

  return fraction;//percentage + fraction;
}

float Amplifier::getPCKP()
{

  uint16_t value = 0;//this->readRegister16(REGISTER_SOC);
  readRegister_16_N(PCKP , &value);
  float fraction = ((float)(value/ 3202.f));

  return fraction;
}

float Amplifier::getAvgVCell()
{

  uint16_t value = 0;//this->readRegister16(REGISTER_SOC);
  readRegister_16_N(AvgVCell , &value);
  float fraction = ((float)(value/12787.f));

  return fraction;
}

float Amplifier::getRepCap()
{

  uint16_t value = 0;//this->readRegister16(REGISTER_SOC);
  readRegister_16_N(RepCap , &value);
  float fraction = ((float)(value));

  return fraction;
}

float Amplifier::getTemp()
{

  uint16_t value = 0;//this->readRegister16(REGISTER_SOC);
  readRegister_16_N(Temp , &value);
  float fraction = ((float)(value/232.f));

  return fraction;
}



///////////////////////////// General function to read I2c registers ////////////////////////////////

// General function to read 8 bit I2c registers
byte Amplifier::readReg8(int deviceAddress, int regAddress) {
  byte data = 0;
  Wire.beginTransmission(deviceAddress);
  Wire.write(regAddress);
  Wire.endTransmission();
  Wire.requestFrom(deviceAddress, 1);
  data = Wire.read();
  return(data);
}

// General function to read 16 bit I2c registers
word Amplifier::readReg16(int deviceAddress, int regAddress) {
  word data = 0;
  Wire.beginTransmission(deviceAddress);
  Wire.write(regAddress);
  Wire.endTransmission(false);
  Wire.requestFrom(deviceAddress, 2);
  byte lowByteData = Wire.read();
  byte highByteData = Wire.read();
  data = word(highByteData, lowByteData);
  return(data);
}

// General function to write to 8 bit I2c registers
void Amplifier::writeReg8(int deviceAddress, int regAddress, byte data) {
  Wire.beginTransmission(deviceAddress);
  Wire.write(regAddress);
  Wire.write(data);
  Wire.endTransmission();
}

// General function to write to 16 bit I2c registers
void Amplifier::writeReg16(int deviceAddress, int regAddress, word data) {
  Wire.beginTransmission(deviceAddress);
  Wire.write(regAddress);
  Wire.write(highByte(data));
  Wire.write(lowByte(data));
  Wire.endTransmission();
}
///////////////////////////// General function to read I2c registers MAX17320////////////////////////////////

uint16_t Amplifier::readRegister16(uint8_t registerId)
{
  this->writeRegisterId(registerId);
  this->_wire->requestFrom((uint8_t)this->_address, (uint8_t)2);

  uint8_t highByte = this->_wire->read();
  uint8_t lowByte = this->_wire->read();

  uint16_t data = toUint16(highByte, lowByte);
  return data;
}

void Amplifier::readRegister_16_N(byte reg, uint16_t *value)
{
  byte MSB = 0;
  byte LSB = 0;
    Wire.beginTransmission(MAX17320);
  Wire.write(reg);
  Wire.endTransmission();
  Wire.requestFrom(MAX17320, 2);
  LSB = Wire.read();
  MSB = Wire.read();
    *value = (MSB << 8) | LSB;
}

void Amplifier::writeRegisterId(uint8_t registerId)
{
  this->_wire->beginTransmission(this->_address);
  this->_wire->write(registerId);
  this->_wire->endTransmission(false);
}

void Amplifier::writeRegister16(uint8_t registerId, uint16_t data)
{
  this->_wire->beginTransmission(this->_address);
  this->_wire->write(registerId);
  this->_wire->write(toHighByte(data));
  this->_wire->write(toLowByte(data));
  this->_wire->endTransmission(true);
}
