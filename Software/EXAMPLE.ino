#include "Amplifier.h"
#include "MAX17043.h"
#include <avr/sleep.h>
#include <Wire.h>
#include "Adafruit_DRV2605.h"

//#include <FastLED.h>
//#include <Adafruit_NeoPixel.h>
//#define LED_PIN     10 //
//#define NUM_LEDS    52
//#define LED_TYPE    WS2812B
//#define COLOR_ORDER GRB
//CRGB leds[NUM_LEDS];


//-------------------------------------------------BT-806--------------------------------------------
char* readLine(char c)
{ // parameter 'c' ==> character that was read
  // return NULL ==> line not ready yet
  // return pointer ==> points to received lineBuffer
  static char lineBuffer[25]; // define maximum string length + terminating '\0'
  static byte counter = 0;
  if (counter == 0) memset(lineBuffer, 0, sizeof(lineBuffer)); // clear buffer before using it
  if (c < 32) // non printable control character, line finished
  {
    if (counter == 0) return NULL;
    counter = 0;
    return lineBuffer;
  }
  else if (counter < sizeof(lineBuffer) - 1) // printable character received and we have room for it
  {
    lineBuffer[counter] = c; // insert character into lineBuffer
    counter++; // increment character counter
  }
  return NULL;
}
//---------------------------------------------------------------------------------------------------

// Instantiate Amplifier object, name it anything, in this case 'TAS5825'
Amplifier TAS5825; //Amplifier
Adafruit_DRV2605 drv; //LED Driver


const int pinLED = 12; //As an indiscation of ON/OFF SYS
const int lowLED = 11; //As an indiscation of low bat
const int pinSwitch = 2; //ON/OFF
const int Pinchargecon = 3; //intrupt for input charger
const int Next = 6; //Next
const int Back = 7; //Back
const int Up = 5; //Up+
const int Down = 4; //Down-
float Low_Bat;

byte
currSwitch,
lastSwitch,charge=0,last_state;
unsigned long
timeStart;
bool
bCheckingSwitch;

// Variables will change:
int ledState = LOW; // ledState used to set the LED
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0; // will store last time LED was updated

// constants won't change:
const long interval = 1000; // interval at which to blink (milliseconds)



void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  FuelGauge.begin();
  drv.begin();
  drv.selectLibrary(1);
  drv.setWaveform(0, 84);  // ramp up medium 1, see datasheet part 11.2
  drv.setWaveform(1, 1);  // strong click 100%, see datasheet part 11.2
  drv.setWaveform(2, 0);  // end of waveforms
  pinMode( pinLED, OUTPUT );
  pinMode( lowLED, OUTPUT );
  digitalWrite( pinLED, LOW );
  pinMode( pinSwitch, INPUT_PULLUP );
  lastSwitch = digitalRead( pinSwitch );
  bCheckingSwitch = false;

  TAS5825.init();
  TAS5825.init_IS31FL3195();
  TAS5825.Mode_IS31FL3195();
  TAS5825.put_bat_voltage();
//
// Serial.println(TAS5825.get_bat_stat(), BIN);
//  Serial.println(TAS5825.getCHG_DETAILS_02(), BIN);
}

void loop() {

  wake_BTN ();
  CTRL_BTN ();
  Low_Bat_AMP ();
  SHOW_BAT_LEDS ();

///////////////////////READINGS///////////////////////
 unsigned long currentMillis = millis();
  if ( currentMillis - previousMillis >= 5000 ) {

   Serial.println("MAX17320 Parameter : \n===============================================================");
   Serial.print("SOC % : \t\t");
   Serial.print( TAS5825.BATpercent() );
   Serial.print("%   \t\t");


   Serial.print("\nBATT  : \t\t");
   Serial.print( TAS5825.getPCKP() );
   Serial.print("V   \t\t");


   Serial.print("\nAvgVCell  : \t\t");
   Serial.print( TAS5825.getAvgVCell() );
   Serial.print("V   \t\t");


   Serial.print("\nRemaining Capacity  : \t\t");
   Serial.print( TAS5825.getRepCap() );
   Serial.print("mA   \t\t");

   Serial.print("\nTemperature  : \t\t");
   Serial.print( TAS5825.getTemp() );
   Serial.print("C   \t\t");


      Serial.println();
      previousMillis = currentMillis;

    }
}


void wake_BTN () {
  //read the switch (for simplicity, no debouncing done)
  currSwitch = digitalRead( pinSwitch );

  if ( currSwitch != lastSwitch )
  {
    //if low now, the change was unpressed to pressed
    if ( currSwitch == HIGH )
    {
      //in that case, get the time now to start the
      //5-sec delay...
      timeStart = millis();
      //...indicate we're now timing a press...
      bCheckingSwitch = true;
    }//if
    else
    {
      bCheckingSwitch = false;
     }//else

    //and save the
    lastSwitch = currSwitch;
  }
  if ( bCheckingSwitch )
  {
    //if the millis count now is 5000 or more higher
    //than it was when the press was detected (timeStart),
    //turn on the LED
    if ( (millis() - timeStart ) < 1000 ){
      Serial.println("AT+PLAYPAUSE");

    }
    else if ((millis() - timeStart ) >= 3000) {
      Serial.println("Going to sleep");
      drv.go();
      delay(500);//sleep time
      digitalWrite( pinLED, LOW );
//      TAS5825.Vol_Down();
      delay(1000);//sleep time

      sleep_CPU();
    }
  }
}


void CTRL_BTN () {
  //To control TPR54
  delay(100);
  int sensorVal1 = digitalRead(Next);
  if (sensorVal1 == HIGH) {
    Serial.println("AT+FORWARD");
    TAS5825.show_led_Next();//
    delay(1000);//sleep time
    SHOW_BAT_LEDS ();
  bat_pres_solid();
      SHOW_BAT_LEDS ();

  }


  int sensorVal2 = digitalRead(Back);
  if (sensorVal2 == HIGH) {
    Serial.println("AT+BACKWARD");
  }

  int sensorVal3 = digitalRead(Up);
  if (sensorVal3 == HIGH) {
    Serial.println("AT+SPKVOL=+");
  }

  int sensorVal4 = digitalRead(Down);
  if (sensorVal4 == HIGH) {
    Serial.println("AT+SPKVOL=-");
  }
}


 void SHOW_BAT_LEDS () {

byte cha_state=0;
  cha_state=TAS5825.get_bat_stat();

 if(cha_state & 0x01 ){
 // Serial.println("fi");
    charge=1;
  }
  else{
    charge=0;
  }

  if(cha_state & 0x02){
   // Serial.println("se");
    charge=1;
  }
  else{
    charge=0;
  }
  if(charge != last_state)
  {last_state=charge;
   if(charge==0){
  bat_pres_solid();}
  else{
    bat_pres();
    //Serial.println(charge, BIN);
  }}
//Serial.println(cha_state, BIN);


}


void Low_Bat_AMP (void) {
  Low_Bat = TAS5825.getPVDD_ADC() / 8.4;
  if (Low_Bat < 6 && Low_Bat > 1) {
    unsigned long currentMillis = millis();

    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;
      if (ledState == LOW) {
        ledState = HIGH;
      } else {
        ledState = LOW;
      }
      digitalWrite(lowLED, ledState);
    }
  }
  else {
    digitalWrite(lowLED, LOW);
  }
}

void bat_pres(void){
  uint16_t pres=0;
   pres = FuelGauge.percent();
   Serial.println(pres);
   if((pres>=0) && (pres<25)){
    TAS5825.show_led_0();
   }
   else if((pres>=25) && (pres<50)){
    TAS5825.show_led_25();
   }
   else if((pres>=50) && (pres<75)){
    TAS5825.show_led_50();
   }
   else if((pres>=75) && (pres<95)){
    TAS5825.show_led_75();
   }
   else if(pres>96){
    TAS5825.show_led_100();
   }
}

void bat_pres_solid(void){
  uint16_t pres=0;
   pres = FuelGauge.percent();
   Serial.println(pres);
   if((pres>=0) && (pres<25)){
    TAS5825.show_led_0_flash();
   }
   else if((pres>=25) && (pres<50)){
    TAS5825.show_led_25_solid();
   }
   else if((pres>=50) && (pres<75)){
    TAS5825.show_led_50_solid();
   }
   else if((pres>=75) && (pres<95)){
    TAS5825.show_led_75_solid();
   }
   else if(pres>96){
    TAS5825.show_led_100_solid();
   }
}

void wake_CPU (void) {

  // cancel sleep as a precaution
  sleep_disable();
  // precautionary while we do other stuff
charge=0;
  detachInterrupt (0);
  detachInterrupt (1);
  delay(100);
  Serial.println("Wake_all");
  interrupts ();
  interrupts ();
  interrupts ();
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  drv.go();
  delay(500);//sleep time
  digitalWrite( pinLED, HIGH );
  TAS5825.wake_AMP();
  TAS5825.otg_off();
 bat_pres_solid();// I ADDED THIS
  delay(1000);
}  // end of wake

void wake_CPU_LED (void) {

  // cancel sleep as a precaution
  sleep_disable();
  // precautionary while we do other stuff
charge=1;
  //detachInterrupt (0);
  detachInterrupt (1);
  delay(100);
  Serial.println("Wake_LED");
  interrupts ();
  interrupts ();
  interrupts ();
  //pinMode(2, INPUT);
  //pinMode(3, INPUT);
  //drv.go();
  delay(500);//sleep time
  //digitalWrite( pinLED, HIGH );
  if(digitalRead(3)==HIGH){
    charge=0;
    TAS5825.sleep_led();
  }
  else{
    charge=1;
    bat_pres();
  }

   //attachInterrupt (1, wake_CPU_LED, CHANGE);
  //EIFR = bit (INTF1);  // clear flag for interrupt 0
  // We are guaranteed that the sleep_cpu call will be done
  // as the processor executes the next instruction after
  // interrupts are turned on.
  //noInterrupts ();
 // set_sleep_mode (SLEEP_MODE_PWR_DOWN);
 // sleep_enable();
  //interrupts ();  // one cycle
  //TAS5825.show_LED();
  sleep_CPU();
  //TAS5825.wake_AMP();
  //delay(1000);
}  // end of wake

void sleep_CPU(void)
{
  TAS5825.sleep_AMP();
// Do not interrupt before we go to sleep, or the
// ISR will detach interrupts and we won't wake.
  TAS5825.otg_off();

  // will be called when pin D0 goes low
  Serial.println("Sleep");
  delay(100);
  EIFR = bit (INTF0);

  attachInterrupt (0, wake_CPU, CHANGE);
  EIFR = bit (INTF0);
// attachInterrupt (1, wake_CPU_LED, CHANGE);
  if(charge==0){
  TAS5825.sleep_led();
   EIFR = bit (INTF1);
  attachInterrupt (1, wake_CPU_LED, CHANGE);}
  else{EIFR = bit (INTF1);attachInterrupt (1, wake_CPU_LED, RISING);}
  EIFR = bit (INTF1);  // clear flag for interrupt 0
// We are guaranteed that the sleep_cpu call will be done
// as the processor executes the next instruction after
// interrupts are turned on.
  noInterrupts ();
  set_sleep_mode (SLEEP_MODE_PWR_DOWN);
  sleep_enable();
  interrupts ();  // one cycle
  sleep_cpu ();   // one cycle
}
