
<p align="center">
   <img src="https://github.com/Mala2/Moudio/blob/main/Documentation/Pics/MASHA.png?raw=true"  width=200>  

<p align="center">
   <img src="https://raw.githubusercontent.com/Mala2/Moudio/5eee7f0046a20fc856ecd1f677f850bbddd510a9/3D-Files/Pics/LOGO1.svg"  width=400>  

https://a360.co/3dSuCTA


</p>
<p align="center">
	<a href="https://github.com/Mala2/Bluetooth-Speaker/repo-size" alt="repo-size">
		<img src="https://img.shields.io/github/repo-size/Mala2/Bluetooth-Speaker.svg" /></a>
	<a href="https://github.com/Mala2/Bluetooth-Speaker/issues" alt="Issues">
		<img src="https://img.shields.io/github/issues/Mala2/Bluetooth-Speaker.svg" /></a>
	<a href="https://github.com/sparkfun/Qwiic_SerLCD_Py/blob/master/LICENSE" alt="License">
		<img src="https://img.shields.io/badge/license-MIT-blue.svg" /></a>
	  <br/>
  	<a href="https://discord.gg/jvKunuGb8d">
   		<img src="https://img.shields.io/badge/discord-join-7289DA.svg?logo=discord&longCache=true&style=flat" />
	<a href="https://twitter.com/intent/follow?screen_name=Muhammadalali">
        	<img src="https://img.shields.io/twitter/follow/Muhammadalali.svg?style=social&logo=twitter"
           	 alt="follow on Twitter"></a>
	<a href="https://github.com/Mala2">
        	<img src="https://img.shields.io/github/followers/mala2?style=social"/></a>
	<a href="https://github.com/Mala2/Bluetooth-Speaker/stargazers" alt="stars">
		<img src="https://img.shields.io/github/stars/mala2/Bluetooth-Speaker?style=social" /></a>

<p align="center">
🚨 ⚠ This project is currently still under development ⚠️ 🚨

# Overview
A fully functional Bluetooth Speaker implements most of the modern features. The goal is to have a High-performance portable Bluetooth speaker with a modern design.

In this speaker, I tried combining all modern features to have pure sound and the easiest method to construct it, keeping it affordable. ATmega328P microcontroller at its core, and compatibility with Arduino. Along with FSC-BT806 featuring Qualcomm® CSR8675. And as for the amplifier, 2x Texas Instruments® TAS5825M, Which has low distortion and can output 2x 30 W. 

So far, I have built and tested PCBs as prototypes, which work as expected. The hardware design is mainly done. However, the software part is still under process; and this is where I need most of the help. Please refer to the shared files for more information.



[![image](https://user-images.githubusercontent.com/63622787/149161019-443c6ed5-2b7f-4a77-8a0c-c58f14e8bd33.png)](https://a360.co/3340jVi)
[![image](https://user-images.githubusercontent.com/63622787/149161185-76ba31c0-4a93-4759-8a88-698c24c4fad2.png)](https://a360.co/3340jVi)
![Alt Text](https://github.com/Mala2/Bluetooth-Speaker/blob/main/STL-Files/Pics/finalcut.gif?raw=true)

[*🎨 View on FUSION 360*](https://a360.co/3340jVi)
<p align="center">
   <img src="https://raw.githubusercontent.com/Mala2/Bluetooth-Speaker/d2fb2cd54b1a1c7008afc3e6f91d7903d9749cc6/STL-Files/Pics/line%20logo%20v3.svg"  width=1200>  

# Features
	
* **Amplifier** - 2x  Texas Instruments® [*TAS5825M*](https://www.ti.com/product/TAS5825M) Which has low distortion can output 2x 30 W, 2.2 Mode (8-Ω, 24 V, THD+N=1%)
* **Connectivity** - The [*FSC-BT806 Feasycom*](https://github.com/Mala2/FSC-BT806) features
 Qualcomm® **CSR8675** - **Bluetooth V5.0** Support HSP, HFP, A2DP, AVRCP, PBAP,MAP,SPP,BLE profile - Coverage up to 15m - 2 microphone inputs - **Audio interfaces:** I²S/PCM and SPDIF

* **Power** - Accept **USB C IN** Delivery **Up to 2.5A  Charge Current**  - **USB A OUT** Capable of **10W-5V,2A** - **Low idle power** consumption - **7500mAh** battery capacity upgradeable to **15000mAh**

* **Arduino IDE Programmable Bluetooth-Speaker**
<p align="center">
   <img src="https://raw.githubusercontent.com/Mala2/Bluetooth-Speaker/d2fb2cd54b1a1c7008afc3e6f91d7903d9749cc6/STL-Files/Pics/line%20logo%20v3.svg"  width=1200>  

 # Repository Contents

👩‍🚀 **[.3D Files ](3D-Files)** • The **Bluetooth-Speaker** components in many formats (probably what you are looking for to 3d print)

🔉 **[Hardware](Hardware)** • The internal PCBs files (Gerber, Schematic)

💻 **[Software](Software)** • Codes and Libraries for use with the **MouDio**

📄 **[Documentation](Documentation)** • Datasheets, other references

🎲 **[Prototype](Prototype)** • Evaluation board, Cases, etc.

<p align="center">
   <img src="https://raw.githubusercontent.com/Mala2/Bluetooth-Speaker/d2fb2cd54b1a1c7008afc3e6f91d7903d9749cc6/STL-Files/Pics/line%20logo%20v3.svg"  width=1200>  

# Block Diagram

The following displays the latest Block Diagram; Things may change, and probably there may be some discrepancy between the schematic and the block diagram.
	
[![image](https://user-images.githubusercontent.com/63622787/155908226-ed063e92-9d1a-49b5-a607-8d2bb6cb78d0.png)](Hardware)

<p align="center">
   <img src="https://raw.githubusercontent.com/Mala2/Bluetooth-Speaker/d2fb2cd54b1a1c7008afc3e6f91d7903d9749cc6/STL-Files/Pics/line%20logo%20v3.svg"  width=1200>  

# Schematics

The following displays the ****[TOP Main](Documentation/TOP_Main/)**** PCB. It contain the Atmega328|ESP32 uC, LED Driver, Haptic Driver, RTC, Touch Sensor (TPR54|48), EEPROM*, Supervisory, Addressable LEDs
	
![image](https://user-images.githubusercontent.com/63622787/205257953-cc04c984-0cd3-4453-a4a4-a5c7381ed39f.png)
	
![image](https://user-images.githubusercontent.com/63622787/205258100-91fef7d8-6f85-478d-b2b9-72e3e4c2aff1.png)
![image](https://user-images.githubusercontent.com/63622787/205258171-768a88d8-0153-4d4d-a95c-9c6bd6f854da.png)

[📐 *View on FUSION 360*](https://a360.co/3FjaXoa)******

<p align="center">
   <img src="https://raw.githubusercontent.com/Mala2/Bluetooth-Speaker/d2fb2cd54b1a1c7008afc3e6f91d7903d9749cc6/STL-Files/Pics/line%20logo%20v3.svg"  width=1200>  
	
The following displays the ****[BACK Charger](Documentation/BACK_Charger/)**** PCB.It contain MAX77961 3S Charger, MAX17320 Fuel Gauge, MAX25231ATCA 5V Buck, MAX77503BEWC33 3V3 Buck, 3S Battery.

![image](https://user-images.githubusercontent.com/63622787/205258570-6a4cc24a-7623-479a-a7d2-cd6fa71c4473.png)
	
![image](https://user-images.githubusercontent.com/63622787/205258651-e757365f-73a4-4afa-943f-e38054116621.png)
![image](https://user-images.githubusercontent.com/63622787/205258702-95c8b73a-a0a3-4b11-bbab-3177f6f54bf7.png)

[📐 *View on FUSION 360*](https://a360.co/3fcBBV4)*******
	

<p align="center">
   <img src="https://raw.githubusercontent.com/Mala2/Bluetooth-Speaker/d2fb2cd54b1a1c7008afc3e6f91d7903d9749cc6/STL-Files/Pics/line%20logo%20v3.svg"  width=1200>  
	
The following displays the ****[BOTTOM Amplifier](Documentation/BOTTOM_Amplifier/)**** PCB.It contain the Amplifier - 2x Texas Instruments® TAS5825M and The FSC-BT806 Feasycom Bluetooth Moduel.

![image](https://user-images.githubusercontent.com/63622787/205259174-c7367f22-2c25-42a6-954b-ad810d128e00.png)
	
![image](https://user-images.githubusercontent.com/63622787/205259300-dfab4e11-0d12-45d0-a1fd-49a1b6b62747.png)
![image](https://user-images.githubusercontent.com/63622787/205259502-6c5d0c4f-b804-4309-a095-925ea3a69c1c.png)	
[📐 *View on FUSION 360*](https://a360.co/3fcBBV4)*******	
	

<p align="center">
   <img src="https://raw.githubusercontent.com/Mala2/Bluetooth-Speaker/d2fb2cd54b1a1c7008afc3e6f91d7903d9749cc6/STL-Files/Pics/line%20logo%20v3.svg"  width=1200>  
	
The following displays the ****[FRONT Speaker](Documentation/FRONT_Speaker/)**** PCB.To hold the Speakers and front acrylic grill


![image](https://user-images.githubusercontent.com/63622787/205259718-d144ce8e-ec39-4092-a8d7-02391e73b247.png)
	
![image](https://user-images.githubusercontent.com/63622787/205259770-1f94ebea-87ad-4526-ba7f-9827b583c5cb.png)
![image](https://user-images.githubusercontent.com/63622787/205259825-dc52bc25-21b0-43f9-897a-4dcf9ae00392.png)
[📐 *View on FUSION 360*](https://a360.co/3fcBBV4)*******	

	
<p align="center">
   <img src="https://raw.githubusercontent.com/Mala2/Bluetooth-Speaker/d2fb2cd54b1a1c7008afc3e6f91d7903d9749cc6/STL-Files/Pics/line%20logo%20v3.svg"  width=1200>  	

# Working Principal

**1. First, I am going to use the TPR54 Touch Sensor Modules to turn ON/OFF the system, if pin [I/O-2] "TAP" it is pressed >2s. This module can send  active High signal output to the ATmega328p pin 2 [INT0].**
	
[![image](https://github.com/Mala2/Bluetooth-Speaker/blob/main/STL-Files/Pics/TPR54-.png?raw=true)](https://www.azoteq.com/images/stories/pdf/proxsense_gpio_trackpad_datasheet.pdf)

**2. After waking up, the ATmega328 will send a high signal to turn on the Bluetooth Module BT-806 through pin [8] "Vreg" and the TAS5825 circuitry through pin [A3] "PDN".**

🔸	**Startup Procedures: [I/O_2] "TAP" pressed for >2s**

*	The ATmega328p wakes up upon High signal on pin 2 [INT0].

*	Send a 3V3 high signal to haptic driver to enable the IC.

*       initialize the LED driver IS31FL3195 to wakeup.

*	Turn on the haptic driver as an indication for 1s.

*	Turn on the LED driver to play a motion from left to right as wake up inication.

*	Turn on the LED driver to reflect the current SOC% of the battery with the help of the fuel gauge MAX17320 and check whether the charger is presnt or not set the LEDs accordingly. 

*	Send a 3V3 high signal of more than 100ms to Bluetooth Module BT-806 through VREG_IN (PLAY/PAUSE) pin to boot the module, then bring the signal back to low.

*	Once power supplies are stable, bring up PDN of TAS5825 to High and wait 5ms.

*	Set the Amplifier TAS5825 into the HiZ state and enable DSP via the I2C control port.

*	Wait 5ms at least. Then initialize the DSP Coefficient, then set the TAS5825 to Play state.

*       initialize the charger MAX77961.

		
	<br />
	
🔸	**Shutdown Procedures: [I/O_2] "TAP" pressed for >2s**

*	Configure the Register 0x03h -D[1:0]=10 (Hiz) via the I2C control port and Pull PDN low.

*	Wait at least 6ms (this time depends on the LRCLK rate, digital volume, and digital volume ramp-down rate).

*	Send a 3V3 high signal of more than 100ms to Bluetooth Module BT-806 through VREG_IN (PLAY/PAUSE) pin to turn off the module, then bring the signal back to low.

*	The ATmega328 goes to deep sleep, waiting for the next event.
	
	<br />

🔸	**Charging Procedures:**

*	Once the charge input is present, the MAX77961 will send an interrupter either through INTB, INOKB pins

*	Turn on the haptic driver as an indication for 1s.

*	Display the current SOC% with 4 LEDs with the help of an LED driver as long as the charge input is present. Otherwaise, the ATmega328 goes to deep sleep, waiting for the next event.

<br />
	
**3. Once the speaker is ON, the TPR54 is responsible for interacting with Bluetooth Module BT-806 to change the song and volume. (Keep in mind that the TAS5825 can also change just the volume) through TX/RX UART pin between the ATmega328 and Bluetooth Module BT-806 at 115200 rate data. For example: Once the ATmega328 is connected to BT-806, It can send a command to change the volume. For example,**

![image](https://user-images.githubusercontent.com/63622787/149187244-66467fe5-f23c-40f3-abe1-30d0a50c8069.png)

**And so on. Also, if the BAT SOC% is low, alert the user with an LED blinking and start the Shutdown Procedures once the BAT is too low to operate the system > 15%.**

# To Do List

♦️ **Need help with software part.**

1- After making sure the BT806 is OFF through the commands AT+, Turns the BT806 after turning the 3v3. Sending a high signal to Vreg for > 2s upon waking up, then remain Low. (OR MOSFET NETWORK)
	
2- If the battery is < 15%, shut down the speaker if no charging is present.
			     
✅ 3- If the battery is <35%, set the MAX volume to be less than 70%. In other words, it reduces the volume to not consume more power. TAS5825 has register 0x4c and 0x54 (AGAIN or DIGITAL_VOL) to set that.

4- (after checking the vol range of bt806), send a command AT+SPKVOL and check the volume range of BT806 sent. After that, set the TAS5825 accordingly; that can be done with two registers, either 0x4c and 0x54 (AGAIN or DIGITAL_VOL).
	
✅ 5- For example, once the user swap to the right (Next Song). The LEDs should indicate that from left to right emotions.

6- If no sounds or connection is established for 30 min, turn off the speaker. Either by checking the current flow from the fuel gauge MAX17320 or the BT-806 is not in play status or the TAS5825 register 0x03 is mute status for more than 30 min.

✅ 7- If the charger is inserted, activate the haptic driver as feedback.

9- If the charger is inserted, increase the volume range to be even higher as more power will be provided. This can be done if the 0x4C register is changed accordingly with the attached and disattached of the charger.

10- Add resetFunc() after touching the middle TAP more than 10s.

11- Get the header file for the TAS5825M to act as Dual stereo 2.2 and output the best sounds. You need PPC3 software and hardware access to test the setup and extract the best DSP settings.

12- Create the initialization code configuring the bq28z610 fuel gauge to work with the Arduino Uno and create a Library, and also create a “control” object for the bq28z610 fuel gauge. This includes configuring the IC’s registers via I2C to set configurations. In addition, looking to expose all features of the target ICs in code so that a user can easily configure those features using variables.

♦️ TO BE CONTINUED
	<p align="center">
   <img src="https://raw.githubusercontent.com/Mala2/Bluetooth-Speaker/d2fb2cd54b1a1c7008afc3e6f91d7903d9749cc6/STL-Files/Pics/line%20logo%20v3.svg"  width=1200>  
# Components

🔷 **Speakers**

<p align="center">
   <img src="https://www.parts-express.com/SSP%20Applications/PartsExpress@SuiteCentric/SCA%202019.1/img/290-206_HR_0.default.jpg?resizeid=106&resizeh=1200&resizew=1200)](https://www.parts-express.com/Dayton-Audio-ND65-8-2-1-2-Aluminum-Cone-Full-Range-Driver-8-290-206?gclid=CjwKCAjwkvWKBhB4EiwA-GHjFrtrRhF_nZh4KP2HR51msc4nOYF4FvnND1y967XQK91w8MbXJw41TxoC_Y0QAvD_BwE"  width=200>  

[*ND65-8 2-1/2"*](https://www.parts-express.com/Dayton-Audio-ND65-8-2-1-2-Aluminum-Cone-Full-Range-Driver-8-290-206?gclid=CjwKCAjwkvWKBhB4EiwA-GHjFrtrRhF_nZh4KP2HR51msc4nOYF4FvnND1y967XQK91w8MbXJw41TxoC_Y0QAvD_BwE) **X2**

🔷 **Tweeters**

<p align="center">
   <img src="https://www.parts-express.com/SSP%20Applications/PartsExpress@SuiteCentric/SCA%202019.1/img/275-030_HR_0.default.jpg?resizeid=106&resizeh=1200&resizew=1200)](https://www.parts-express.com/Dayton-Audio-ND20FA-6-3-4-Soft-Dome-Neodymium-Tweeter-275-030?quantity=1&custcol1=Dayton%20Audio%20ND20FA-6%203%2F4%22%20Soft%20Dome%20Neodymium%20Tweeter&custcol_ava_item=275-030&custcol_ava_incomeaccount=General&custcol_ava_upccode=844632000874&custcol_ava_pickup=F&custcol_disableshopping=F"  width=200>  

[*ND20FA-6 3/4"*](https://www.parts-express.com/Dayton-Audio-ND20FA-6-3-4-Soft-Dome-Neodymium-Tweeter-275-030?quantity=1&custcol1=Dayton%20Audio%20ND20FA-6%203%2F4%22%20Soft%20Dome%20Neodymium%20Tweeter&custcol_ava_item=275-030&custcol_ava_incomeaccount=General&custcol_ava_upccode=844632000874&custcol_ava_pickup=F&custcol_disableshopping=F) **X2**

🔷 **Acousta-Stuf Polyfill**

<p align="center">
   <img src="https://user-images.githubusercontent.com/63622787/149180385-775761d5-e528-4509-bb9d-688302a13862.png"  width=200>  

[*Acousta-Stuf Polyfill*](https://www.parts-express.com/Acousta-Stuf-Polyfill-1-lb.-Bag-260-317?quantity=1&custcol1=Acousta-Stuf%20Polyfill%201%20lb.%20Bag&custcol_ava_item=260-317&custcol_ava_incomeaccount=General&custcol_ava_upccode=844632037382&custcol_ava_pickup=F&custcol_disableshopping=F)

🔷 **Brass Threaded Metal**
M3 3mm M3-0.5 Brass Threaded Metal Heat Set Screw Inserts for 3D Printing

<p align="center">
   <img src="https://i.ebayimg.com/images/g/HL8AAOSw0A9aRQZl/s-l1600.jpg"  width=200>  

[*Brass Threaded Metal*](https://www.ebay.com/itm/292174792941)
	
	
🔷 **Silicone Rubber Mat 60x8x3mm**

<p align="center">
   <img src="https://ae01.alicdn.com/kf/Hc616a29456824813b6d46c72e8e32774m/4Pc-Self-Adhesive-Silicone-Rubber-Oval-Mat-Cabinet-Equipment-Anti-slip-Feet-Pad-Floor-Protectors-Width.jpg_Q90.jpg_.webp"  width=200>  

[*Silicone Rubber Mat*](https://www.aliexpress.com/item/3256801841973589.html?spm=a2g0o.order_list.0.0.21ef1802Ng4OPe&gatewayAdapt=4itemAdapt)**X2**
	
	
	
	
	

[![Mo's github stats](https://github-readme-stats.vercel.app/api?username=Mala2&count_private=true&show_icons=true&theme=radical&hide_rank=false)](https://github.com/anuraghazra/github-readme-stats)
<p align="center">
   <img src="https://raw.githubusercontent.com/Mala2/Bluetooth-Speaker/d2fb2cd54b1a1c7008afc3e6f91d7903d9749cc6/STL-Files/Pics/line%20logo%20v3.svg"  width=1200>  
