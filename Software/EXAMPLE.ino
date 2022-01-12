#include "Amplifier.h"
#include <avr/sleep.h>
#include <Wire.h>

#define Digital_Volume    1 //dB 0-24 dB Maximum is 24 dB
#define Analog_Gain       10 //dB 0-15 dB Maximum is 15 dB
#define Select_Fsw        64 // 64 FOR THE HIGHEST QUALITY
//0 = 348K,BTL,BD MODE
//1 = 348K,BTL,1SPW MODE
//2 = 348K,BTL,HYB MODE
//6 = 348K,PBTL,HYB MODE
//5 = 348K,PBTL,1SPW MODE
//4 = 348K,PBTL,BD MODE
//64 = 768K,BTL,BD MODE
//65 = 768K,BTL,1SPW MODE
//66 = 768K,BTL,HYB MODE
//70 = 768K,PBTL,HYB MODE
//69 = 768K,PBTL,1SPW MODE
//68 = 768K,PBTL,BD MODE
#define I2S_Format        3
//3 = I2S, 32 bits
//19 = TDM/DSP, 32 bits
//35 = RTJ, 32 bits
//51 = LTJ, 32 bits, -1 For 24 bits, -2 For 20 bits, -3 For 16 bits
//---------------
char* readLine(char c)
{ // parameter 'c' ==> character that was read
  // return NULL ==> line not ready yet
  // return pointer ==> points to received lineBuffer
  static char lineBuffer[25]; // define maximum string length + terminating '\0'
  static byte counter=0;
  if (counter==0) memset(lineBuffer,0,sizeof(lineBuffer));// clear buffer before using it
  if (c<32) // non printable control character, line finished
  {
    if (counter==0) return NULL;
    counter=0;
    return lineBuffer;
  }
  else if (counter<sizeof(lineBuffer)-1) // printable character received and we have room for it
  {
    lineBuffer[counter]=c; // insert character into lineBuffer
    counter++; // increment character counter
  }
  return NULL;
}
//---------------

// Instantiate Amplifier object, name it anything, in this case 'TAS5825'
Amplifier TAS5825; //Amplifier

unsigned long previousMillis = 0;

void setup() {
  Serial.begin(115200);
  TAS5825.init(Digital_Volume, Analog_Gain, Select_Fsw, I2S_Format);
 
  Serial.println("AT+REBOOT"); //Soft reboot
  delay(1000);
  Serial.println("AT+NAME=MoAudio"); //Change Name of BT-806
  delay(5000);
  //Serial.println("AT+I2SCFG=65"); //Set I2S/PCM configuration to: I2S master, 32-bit resolution,48kHz. https://document.feasycom.com/web/#/2.1.22
  //delay(2000);
  //Serial.println("AT+REBOOT"); //Soft reboot
}

void loop() {

 unsigned long currentMillis = millis();
  if ( currentMillis - previousMillis >= 1000 ) {
    
    /////////  DIE_ID
 
    if ( TAS5825.getDIE_ID() == 149 ) {
      Serial.println("TAS5825 founded !");
    }
    else {
      Serial.println("TAS5825 not found ! Please check connections");
    } 
    
    Serial.println("TAS5825 Parameter : \n===============================================================");

////////////////////**Checking Importnant registers////////////////////

    /////////  RESET_CHANGE_PAGE   
    Serial.print("**RESET_PAGE 0x00 : \t");
    Serial.print( TAS5825.getRESET_CHANGE_PAGE(), HEX );
    if ( TAS5825.getRESET_CHANGE_PAGE() == 0 ) {
      Serial.println(",HEX >>>Reset ");
    }
    
    /////////  Book  
    Serial.print("**Book Page 0x7f : \t");
    Serial.print( TAS5825.getBook(), HEX );
    if ( TAS5825.getBook() == 0 ) {
      Serial.println(",HEX >>>Right Page");
    }
    
    /////////  Digital volume  
    Serial.print("**Digital volume 0x4c : \t");
    Serial.print( 24 - 0.5 * TAS5825.getDIG_VOL(), DEC );
    Serial.println(" dB");


    /////////  DEVICE_CTRL_2 
    Serial.print("**DEVICE_CTRL_2 0x03: \t");
    Serial.print( TAS5825.getDEVICE_CTRL_2(), HEX );
    if ( TAS5825.getDEVICE_CTRL_2() == 16 ) {
      Serial.println(",HEX >>>Reset the DSP");
    }
    else if ( TAS5825.getDEVICE_CTRL_2() == 3 )
    {
      Serial.println(",HEX >>>Play"); 
      }
    else if  ( TAS5825.getDEVICE_CTRL_2() == 0 )
    {
      Serial.println(",HEX >>>MUTE ");
    }    
    
    /////////  Set analog gain
    Serial.print("**Analog Gain 0x54 : \t");
    Serial.print( TAS5825.getAGAIN()/2, DEC );
    Serial.println(" dB");


    /////////  Fault clear
    Serial.print("**Fault Clear 0x78 : \t");
    Serial.print( TAS5825.getFAULT_CLEAR(), HEX );
    if ( TAS5825.getFAULT_CLEAR() == 0 ) {
      Serial.println(",HEX >>>Fault Clear");
    }
    
//_______________________________________________________________//
     
    /////////  CLKDET_STATUS
    // TO DO; see what is up with this REG
    Serial.print("--CLKDET_STATUS  0x39 : \t");
    Serial.print( TAS5825.getCLKDET_STATUS(), HEX );
    if ( TAS5825.getCLKDET_STATUS() == 8 ) {
      Serial.println(",HEX >>>Normal Opertion");
    }
    else {
      Serial.println(",HEX >>>Look At the Datasheet it should be 3,HEX");
    }
      
    /////////  POWER_STATE
    Serial.print("--POWER_STATE  0x68 : \t");
    Serial.print( TAS5825.getPOWER_STATE(), HEX );
    if ( TAS5825.getPOWER_STATE() == 3 ) {
      Serial.println(",HEX >>>Play");
    }
    else if ( TAS5825.getPOWER_STATE() == 2) {
      Serial.println(",HEX >>>HIZ");
    }    
    else if ( TAS5825.getPOWER_STATE() == 1 ){
      Serial.println(",HEX >>>sleep");
    }    
     else {
      Serial.println(",HEX >>>Deep Sleep");
    }
                   
    /////////  CHAN_FAULT
    Serial.print("--CHAN_FAULT  0x69 : \t");
    Serial.print( TAS5825.getCHAN_FAULT(), HEX );
    if ( TAS5825.getCHAN_FAULT() == 0 ) {
      Serial.println(",HEX >>>Normal Opertion");
    }
    else {
      Serial.println(",HEX >>>Look At the Datasheet it should be 0,HEX");
    }
    
    /////////  AUTOMUTE_STATE  
    Serial.print("--AUTOMUTE_STATE  0x70 : \t");
    Serial.print( TAS5825.getAUTOMUTE_STATE(), HEX );
    if ( TAS5825.getAUTOMUTE_STATE() == 0 ) {
      Serial.println(",HEX >>>Normal Opertion");
    }
    else {
      Serial.println(",HEX >>>Look At the Datasheet it should be 0,HEX");
    }
    
    /////////  GLOBAL_FAULT1 
    Serial.print("--GLOBAL_FAULT1  0x71 : \t");
    Serial.print( TAS5825.getGLOBAL_FAULT1(), HEX );
    if ( TAS5825.getGLOBAL_FAULT1() == 0 ) {
      Serial.println(",HEX >>>Normal Opertion");
    }
    else if ( TAS5825.getGLOBAL_FAULT1() == 4 ) {
      Serial.println(",HEX >>>Clock fault");
    }    
    
    else {
      Serial.println(",HEX >>>Look At the Datasheet it should be 0,HEX");
    }
    
    /////////  GLOBAL_FAULT2  
    Serial.print("--GLOBAL_FAULT2  0x72 : \t");
    Serial.print( TAS5825.getGLOBAL_FAULT2(), HEX );
    if ( TAS5825.getGLOBAL_FAULT2() == 0 ) {
      Serial.println(",HEX >>>Normal Opertion");
    }
    else {
      Serial.println(",HEX >>>Look At the Datasheet it should be 0,HEX");
    }
    
    /////////  WARNING 
    Serial.print("--WARNING  0x73 : \t");
    Serial.print( TAS5825.getWARNING(), HEX );
    if ( TAS5825.getWARNING() == 0 ) {
      Serial.println(",HEX >>>Normal Opertion");
    }
    else {
      Serial.println(",HEX >>>Look At the Datasheet it should be 0,HEX");
    }
              
//******************************************* CHECKING DONE *************************************//
    
    /////////  RESET_CTRL
    
    Serial.print("RESET_CTRL : \t\t");
    Serial.print( TAS5825.getRESET_CTRL(), HEX );
    if ( TAS5825.getRESET_CTRL() == 17 ) {
      Serial.println(",HEX >>>Reset DIG_CORE (Reset Full Digital Signal Path) & Reset Registers (Reset I2C Control Port Registers)");
    }
    else {
      Serial.println(",HEX >>>Reset DIG_CORE (Normal) & Reset Registers (Normal)");
    }

    /////////  DEVICE_CTRL_1
    
    Serial.print("DEVICE_CTRL_1 : \t");
    Serial.print( TAS5825.getDEVICE_CTRL_1(), DEC );
    if ( TAS5825.getDEVICE_CTRL_1() == 64 ) {
      Serial.println(",DEC >>>SELECT FSW (768K) & SET DAMP TO BTL MODE & BD MODE");
    } 
    else if ( TAS5825.getDEVICE_CTRL_1() == 0 ){
      Serial.println(",DEC >>>SELECT FSW (384K) & SET DAMP TO BTL MODE & BD MODE");
    }
    

      /////////  SIG_CH_CTRL
    
    Serial.print("SIG_CH_CTRL : \t\t");
    Serial.print( TAS5825.getSIG_CH_CTRL(), HEX );
    if ( TAS5825.getSIG_CH_CTRL() == 0 ) {
      Serial.println(",HEX >>>Auto detection");
    }
    else {
      Serial.println(",HEX >>>Look At the Datasheet");
    }
    
      /////////  SAP_CTRL1
    
    Serial.print("SAP_CTRL1 : \t\t");
    Serial.print( TAS5825.getSAP_CTRL1()*8+8, DEC );
    Serial.println(" bits, I2S Data Format");
 
      /////////  BCK
    
    Serial.print("BCK : \t\t\t");
    Serial.print( TAS5825.getBCK(), DEC );
    Serial.println(" FS");     
      
     /////////  FS_MON
    
    Serial.print("FS_MON : \t\t");
    Serial.print( TAS5825.getFS_MON(), DEC );
    if ( TAS5825.getFS_MON() == 9 ) {
      Serial.println(",DEC >>> Sampling Rate = 48KHz");
    } 
      else if( TAS5825.getFS_MON() == 11 ){
      Serial.println(",DEC >>>> Sampling Rate = 96KHz");
    }
      else if( TAS5825.getFS_MON() == 0 ){
      Serial.println(",DEC >>>> FS Error");
    }   
         
     /////////  PVDD_ADC
    
    Serial.print("PVDD_ADC : \t\t");
    Serial.print( TAS5825.getPVDD_ADC()/ 8.4, DEC );
    Serial.println(" V");
    
         
     /////////  GPIO0_SEL
    
    Serial.print("GPIO0_SEL : \t\t");
    Serial.print( TAS5825.getGPIO0_SEL(), DEC );
   if ( TAS5825.getGPIO0_SEL() == 6 ) {
      Serial.println(",HEX >>> GPIO 0 = Clock invalid ");
    }
    else {
      Serial.println(",HEX >>>Look At the Datasheet");
    }       
    
    
      Serial.println();
      previousMillis = currentMillis;
 
  }

  delay(15000);
 TAS5825.sleep_on();
}

void wake_CPU (void){
  
  // cancel sleep as a precaution
  sleep_disable();
  // precautionary while we do other stuff
  detachInterrupt (digitalPinToInterrupt(2));
 Serial.println("wake");

 TAS5825.wake_AMP();
}  // end of wake

void sleep_CPU(void) 
{
  
  TAS5825.sleep_AMP();
  
  
  set_sleep_mode (SLEEP_MODE_PWR_DOWN);  
  sleep_enable();
  // Do not interrupt before we go to sleep, or the
  // ISR will detach interrupts and we won't wake.
  noInterrupts ();
  // will be called when pin D0 goes low  
  attachInterrupt (digitalPinToInterrupt(2), wake_CPU, FALLING);
  EIFR = bit (INTF0);  // clear flag for interrupt 0
   // We are guaranteed that the sleep_cpu call will be done
  // as the processor executes the next instruction after
  // interrupts are turned on.
  interrupts ();  // one cycle
  sleep_cpu ();   // one cycle
  }
