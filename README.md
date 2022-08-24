
<p align="center">
   <img src="https://github.com/Mala2/Bluetooth-Speaker/blob/main/STL-Files/Pics/1-removebg-preview%2010.39.27%20PM.png?raw=true"  width=200>  

<p align="center">
   <img src="https://raw.githubusercontent.com/Mala2/Bluetooth-Speaker/cb13bf78a5724965e46d3dd32a3a264b87d806b8/STL-Files/Pics/LOGO1.svg"  width=400>  


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
**⚠  This project is currently still under development ⚠️**

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
	
* **Amplifier** - 2x  Texas Instruments® [*TAS5825M*](https://www.ti.com/product/TAS5825M) Which has low distortion can output 2x 30 W, 2.0 Mode (8-Ω, 24 V, THD+N=1%)
* **Connectivity** - The [*FSC-BT806 Feasycom*](https://github.com/Mala2/FSC-BT806) features
 Qualcomm® **CSR8675** - **Bluetooth V5.0** Support HSP, HFP, A2DP, AVRCP, PBAP,MAP,SPP,BLE profile - Coverage up to 15m - 2 microphone inputs - **Audio interfaces:** I²S/PCM and SPDIF

* **Power** - Accept **USB C IN** Delivery **Up to 2.5A  Charge Current**  - **USB A OUT** Capable of **10W-5V,2A** - **Low idle power** consumption - **7500mAh** battery capacity upgradeable to **15000mAh**

* **Arduino IDE Programmable Bluetooth-Speaker**
<p align="center">
   <img src="https://raw.githubusercontent.com/Mala2/Bluetooth-Speaker/d2fb2cd54b1a1c7008afc3e6f91d7903d9749cc6/STL-Files/Pics/line%20logo%20v3.svg"  width=1200>  

 # Repository Contents

👩‍🚀 **[.STL Files ](STL-Files)** • The **Bluetooth-Speaker** components in STL format (probably what you are looking for to 3d print)

🔉 **[Hardware](Hardware)** • The internal PCBs files (Gerber, Schematic)

💻 **[Software](Software)** • Codes and Libraries for use with the **Bluetooth-Speaker**

📄 **[Documentation](Documentation)** • Datasheets, other references

🎲 **[Prototype](Prototype)** • Evaluation board, Cases, etc.

<p align="center">
   <img src="https://raw.githubusercontent.com/Mala2/Bluetooth-Speaker/d2fb2cd54b1a1c7008afc3e6f91d7903d9749cc6/STL-Files/Pics/line%20logo%20v3.svg"  width=1200>  

# Block Diagram

The following displays the latest Block Diagram; Things may change, and probably there may be some discrepancy between the schematic and the block diagram.
	
[![image](https://user-images.githubusercontent.com/63622787/155908226-ed063e92-9d1a-49b5-a607-8d2bb6cb78d0.png)](Hardware)

<p align="center">
   <img src="https://raw.githubusercontent.com/Mala2/Bluetooth-Speaker/d2fb2cd54b1a1c7008afc3e6f91d7903d9749cc6/STL-Files/Pics/line%20logo%20v3.svg"  width=1200>  

# Schematic

The following displays the ****[Main](Documentation/Main/)**** PCB. It contain the **Amplifier** - 2x  Texas Instruments® **TAS5825M** and The **FSC-BT806 Feasycom**

[![image](https://user-images.githubusercontent.com/63622787/155482345-e0b11533-9b19-4149-a2c4-2ca03223af79.png)](https://a360.co/3FjaXoa)
[![image](https://user-images.githubusercontent.com/63622787/155478210-23ff49bb-4f19-4fd2-8a5d-6a32a56c2e9a.png)](https://a360.co/3FjaXoa)
[![image](https://user-images.githubusercontent.com/63622787/155478343-42e6b0ed-c33d-4bdd-bf7c-dd120df9b8a5.png)](https://a360.co/3FjaXoa)

[📐 *View on FUSION 360*](https://a360.co/3FjaXoa)

<p align="center">
   <img src="https://raw.githubusercontent.com/Mala2/Bluetooth-Speaker/d2fb2cd54b1a1c7008afc3e6f91d7903d9749cc6/STL-Files/Pics/line%20logo%20v3.svg"  width=1200>  
	
The following displays the ****[USB-C](Documentation/USB-C/)**** PCB. It contain the **MP2639** - 2S charging IC and The **ATmega328**

[![image](https://user-images.githubusercontent.com/63622787/155482459-88b97265-02f7-410f-854f-1922078902bf.png)](https://a360.co/3fcBBV4)
[![image](https://user-images.githubusercontent.com/63622787/155482541-2bd08a8a-2dc6-4f6b-baf4-197b943a6eee.png)](https://a360.co/3fcBBV4)
[![image](https://user-images.githubusercontent.com/63622787/155480244-e93962e4-1305-4c88-b8e6-c3814633a7e7.png)](https://a360.co/3fcBBV4)
[![image](https://user-images.githubusercontent.com/63622787/155480352-2a0a0748-7e40-4480-87af-a22e0ddd7642.png)](https://a360.co/3fcBBV4)

[📐 *View on FUSION 360*](https://a360.co/3fcBBV4)

<p align="center">
   <img src="https://raw.githubusercontent.com/Mala2/Bluetooth-Speaker/d2fb2cd54b1a1c7008afc3e6f91d7903d9749cc6/STL-Files/Pics/line%20logo%20v3.svg"  width=1200>  	

# Working Principal

**1. First, I am going to use the TPR54 to turn ON/OFF the system atmega328 [I/O_2] if it is pressed for >2s. This module can send either active High/Low signal output as desired. I will explain later why I need this specific module.**
	
[![image](https://github.com/Mala2/Bluetooth-Speaker/blob/main/STL-Files/Pics/TPR54-.png?raw=true)](https://www.azoteq.com/images/stories/pdf/proxsense_gpio_trackpad_datasheet.pdf)

**2. After waking up, the ATmega328 will send a high signal to turn on the LT3042 (LDO 3V3) to power the Bluetooth Module BT-806 and the TAS5825 circuitry.**

🔸	**Startup Procedures: [I/O_2] pressed for >2s**

*	The atmega328 wakes up.

*	Turn on the haptic driver as an indication for 1s.

*	Turn on the LED driver to reflect the current SOC% of the battery with the help of the fuel gauge.

*	Bring up power supplies to LT3042 (LDO 3V3) and load switch if used.

*	Send a 3V3 high signal of more than 100ms to Bluetooth Module BT-806 through VREG_IN (PLAY/PAUSE) pin to boot the module, then bring the signal back to low.

*	Once power supplies are stable, bring up PDN of TAS5825 to High and wait 5ms (Keep in mind PDN is pulled up to 3V3 normally).

*	Set the TAS5825 into the HiZ state and enable DSP via the I2C control port.

*	Wait 5ms at least. Then initialize the DSP Coefficient, then set the TAS5825 to Play state.
		
	<br />
	
🔸	**Shutdown Procedures: [I/O_2] pressed for >2s**

*	Configure the Register 0x03h -D[1:0]=10 (Hiz) via the I2C control port or Pull PDN low.

*	Wait at least 6ms (this time depends on the LRCLK rate, digital volume, and digital volume ramp-down rate).

*	Bring down power supplies LT3042 (LDO 3V3) and load switch if used.

*	The atmega328 goes to deep sleep, waiting for the next event.
	
	<br />

🔸	**Charging Procedures:**

*	Once the charge input is present, the MAX77962 will send an interrupter either through INTB, INOKB pins

*	Turn on the haptic driver as an indication for 1s.

*	Display the current SOC% with 4 LEDs with the help of an LED driver as long as the charge input is present.

<br />
	
**3. Once the speaker is ON, the TPR54 is responsible for interacting with Bluetooth Module BT-806 to change the song and volume. (Keep in mind that the TAS5825 can also change just volume) through TX/RX UART pin between the atmega328 and Bluetooth Module BT-806 at 115200 rate data. For example: Once the atmega328 is connected to BT-806, It can send a command to change the volume. For example,**

![image](https://user-images.githubusercontent.com/63622787/149187244-66467fe5-f23c-40f3-abe1-30d0a50c8069.png)

**And so on. Also, if the BAT SOC is low, alert the user with an LED blinking and start the Shutdown Procedures once the BAT is too low to operate the system > 6V or 15%.**

# To Do List


🔴 **Need help with software part.**

✅ 1- Turns the bt806 after turning the 3v3. Sending a high signal to Vreg for > 2s Upon waking up then remain Low. (OR MOSFET NETWORK)

✅ 2- if the battery < 15% shut down the speaker.

✅ 3- if the battery <35% set the MAX volume to be less than 70%. In other words reduces the volume to not consume more power. TAS5825 has register 0x4c and 0x54 (AGAIN or DIGITAL_VOL) to set that.

4- (after checking the vol range of bt806), send a command AT+SPKVOL and check the volume range of bt806 sent. After that set the TAS5825 accordingly. That can be done with two registers either 0x4c and 0x54 (AGAIN or DIGITAL_VOL).

✅ 5- For example once the user swap to right (Next Song). The leds should indicate that. From left to right emotions.

6- if no sounds or connection established for 30 min turn off the speaker. Either by checking the current flow from the fuel gauge or the BT-806 is not in play status or the TAS5825 register 0x03 is mute status for more than 30 min.

✅ 7- if charger inserted activate the haptic driver as a feedback.

9- If the charger is inserted increase the volume range to be even higher as more power will be provided. This can be done if 0x4C register is changed accordingly with the attached and disattached of the charger.

10- add resetFunc() after touching the middle TAP more than 10s.

11- get the header file for the TAS5825M to act as Dual stereo 2.2 and output the best sounds. You need to get access of the PPC3 Softwware and Hardware to test the setup and extract the best settings.

12- create the initialization code that configures both the bq28z610 fuel gauge to work with the Arduino Uno and create a Library. creating a “control” object for the bq28z610 fuel gauge. This includes configuring the IC’s registers via I2C to set configurations. In addition, looking to expose all features of the target IC’s in code so that a user can easily configure those features using variables.

🔴 **To be continued
	<p align="center">
   <img src="https://raw.githubusercontent.com/Mala2/Bluetooth-Speaker/d2fb2cd54b1a1c7008afc3e6f91d7903d9749cc6/STL-Files/Pics/line%20logo%20v3.svg"  width=1200>  

# Components


🟢**Speakers**


<p align="center">
   <img src="https://www.parts-express.com/SSP%20Applications/PartsExpress@SuiteCentric/SCA%202019.1/img/290-206_HR_0.default.jpg?resizeid=106&resizeh=1200&resizew=1200)](https://www.parts-express.com/Dayton-Audio-ND65-8-2-1-2-Aluminum-Cone-Full-Range-Driver-8-290-206?gclid=CjwKCAjwkvWKBhB4EiwA-GHjFrtrRhF_nZh4KP2HR51msc4nOYF4FvnND1y967XQK91w8MbXJw41TxoC_Y0QAvD_BwE"  width=200>  

[*ND65-8 2-1/2"*](https://www.parts-express.com/Dayton-Audio-ND65-8-2-1-2-Aluminum-Cone-Full-Range-Driver-8-290-206?gclid=CjwKCAjwkvWKBhB4EiwA-GHjFrtrRhF_nZh4KP2HR51msc4nOYF4FvnND1y967XQK91w8MbXJw41TxoC_Y0QAvD_BwE) **X2**

OR

[*ND65-4 2-1/2"*](https://www.parts-express.com/Dayton-Audio-ND65-4-2-1-2-Aluminum-Cone-Full-Range-Driver-290-204?quantity=1&custcol1=Dayton%20Audio%20ND65-4%202-1%2F2%22%20Aluminum%20Cone%20Full-Range%20Driver&custcol_ava_item=290-204&custcol_ava_incomeaccount=General&custcol_ava_upccode=844632081460&custcol_ava_pickup=F&custcol_disableshopping=F) **X2**

🟢**Tweeters**


<p align="center">
   <img src="https://www.parts-express.com/SSP%20Applications/PartsExpress@SuiteCentric/SCA%202019.1/img/275-030_HR_0.default.jpg?resizeid=106&resizeh=1200&resizew=1200)](https://www.parts-express.com/Dayton-Audio-ND20FA-6-3-4-Soft-Dome-Neodymium-Tweeter-275-030?quantity=1&custcol1=Dayton%20Audio%20ND20FA-6%203%2F4%22%20Soft%20Dome%20Neodymium%20Tweeter&custcol_ava_item=275-030&custcol_ava_incomeaccount=General&custcol_ava_upccode=844632000874&custcol_ava_pickup=F&custcol_disableshopping=F"  width=200>  


[*ND20FA-6 3/4"*](https://www.parts-express.com/Dayton-Audio-ND20FA-6-3-4-Soft-Dome-Neodymium-Tweeter-275-030?quantity=1&custcol1=Dayton%20Audio%20ND20FA-6%203%2F4%22%20Soft%20Dome%20Neodymium%20Tweeter&custcol_ava_item=275-030&custcol_ava_incomeaccount=General&custcol_ava_upccode=844632000874&custcol_ava_pickup=F&custcol_disableshopping=F) **X2**

🟢**Acousta-Stuf Polyfill**


<p align="center">
   <img src="https://user-images.githubusercontent.com/63622787/149180385-775761d5-e528-4509-bb9d-688302a13862.png"  width=200>  


[*Acousta-Stuf Polyfill*](https://www.parts-express.com/Acousta-Stuf-Polyfill-1-lb.-Bag-260-317?quantity=1&custcol1=Acousta-Stuf%20Polyfill%201%20lb.%20Bag&custcol_ava_item=260-317&custcol_ava_incomeaccount=General&custcol_ava_upccode=844632037382&custcol_ava_pickup=F&custcol_disableshopping=F)



🟢**Brass Threaded Metal**
M3 3mm M3-0.5 Brass Threaded Metal Heat Set Screw Inserts for 3D Printing


<p align="center">
   <img src="https://i.ebayimg.com/images/g/HL8AAOSw0A9aRQZl/s-l1600.jpg"  width=200>  


[*Brass Threaded Metal*](https://www.ebay.com/itm/292174792941) **X10**


[![Mo's github stats](https://github-readme-stats.vercel.app/api?username=Mala2&count_private=true&show_icons=true&theme=radical&hide_rank=false)](https://github.com/anuraghazra/github-readme-stats)
<p align="center">
   <img src="https://raw.githubusercontent.com/Mala2/Bluetooth-Speaker/d2fb2cd54b1a1c7008afc3e6f91d7903d9749cc6/STL-Files/Pics/line%20logo%20v3.svg"  width=1200>  
