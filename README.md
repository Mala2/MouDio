# Bluetooth-Speaker
<p align="center">
**⚠  This project is currently still under development. If you came from Reddit just wait I will organize the files soon ⚠️**
	
Discord https://discord.gg/edw5AbDd
<p align="center">
   <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/8/87/Arduino_Logo.svg/2560px-Arduino_Logo.svg.png"  width=200>  

</p>
<p align="center">
	<a href="https://github.com/Mala2/Bluetooth-Speaker/repo-size" alt="repo-size">
		<img src="https://img.shields.io/github/repo-size/Mala2/Bluetooth-Speaker.svg" /></a>
	<a href="https://github.com/Mala2/Bluetooth-Speaker/issues" alt="Issues">
		<img src="https://img.shields.io/github/issues/Mala2/Bluetooth-Speaker.svg" /></a>
	<a href="https://github.com/sparkfun/Qwiic_SerLCD_Py/blob/master/LICENSE" alt="License">
		<img src="https://img.shields.io/badge/license-MIT-blue.svg" /></a> 
 	<a href="https://discord.gg/GqjnZJyF" alt="Issues">
		<img src="https://img.shields.io/discord/895439756681437185.svg" /></a>
	<a href="https://twitter.com/intent/follow?screen_name=Electricshocksa">
        	<img src="https://img.shields.io/twitter/follow/Electricshocksa.svg?style=social&logo=twitter"
           	 alt="follow on Twitter"></a>
	<a href="https://twitter.com/intent/follow?screen_name=Muhammadalali">
        	<img src="https://img.shields.io/twitter/follow/Muhammadalali.svg?style=social&logo=twitter"
           	 alt="follow on Twitter"></a>
	<a href="https://github.com/Mala2">
        	<img src="https://img.shields.io/github/followers/mala2?style=social"/></a>
	<a href="https://github.com/Mala2/Bluetooth-Speaker/stargazers" alt="stars">
		<img src="https://img.shields.io/github/stars/mala2/Bluetooth-Speaker?style=social" /></a>
	
	

Overview
-------------------
A fully function Bluetooth Speaker implement most of the modern features. The goal is to have a High-performance portable Bluetooth speaker. In this speaker, I tried to combine all modern features to have a pure sound and make sure it is easy to build and affordable. Atmega328p at its core, and compatibility with Arduino, MicroPython. Along with BT-806 featuring Qualcomm® CSR8675. And as for the amplifier 2x Texas Instruments® TAS5825M Which has low distortion can output 2 × 30 W. 

So far I have built and tested PCBs as prototypes and they work as expected so the hardware design is mainly done. **However, the software part is still under process. and this is where I need most of the help**
Please refer to the shared files for more information 	



[![FUSION 360](https://user-images.githubusercontent.com/63622787/149157830-eaebf44f-39f2-4e88-8a10-c6501fab80e7.png)](https://a360.co/3340jVi)

[![FUSION 360](https://user-images.githubusercontent.com/63622787/149152517-441e5d39-1810-485c-9a43-e8fb07174685.png)](https://a360.co/3340jVi)



[*🎨 📐 View on FUSION 360*](https://a360.co/3340jVi)

Features
-------------------
* **Amplifier** - 2x  Texas Instruments® [*TAS5825M*](https://www.ti.com/product/TAS5825M) Which has low distortion can output 2 × 30 W, 2.0 Mode (8-Ω, 24 V, THD+N=1%)
* **Connectivity** - The [*FSC-BT806 Feasycom*](https://github.com/Mala2/FSC-BT806) features 
 Qualcomm® **CSR8675** - **Bluetooth V5.0** Support HSP, HFP, A2DP, AVRCP, PBAP,MAP,SPP,BLE profile - Coverage up to 15m - 2 microphone inputs - **Audio interfaces:** I²S/PCM and SPDIF


* **Power** - Accept **USB C IN** Delivery **Up to 2.5A  Charge Current**  - **USB A OUT** Capable of **10W-5V,2A** - **Low idle power** consumption - **5000mAh** battery capacity upgradeable to **10000mAh**

* **Arduino IDE Programmable Bluetooth-Speaker**

Repository Contents
-------------------

👩‍🚀 **[.STL Files ](STL-Files)** • The **Bluetooth-Speaker** components in STL format (probably what you are looking for to 3d print)

🔉 **[Hardware](Hardware)** • The internal PCBs files (Gerber, Schematic) 

💻 **[Software](Software)** • Codes and Libraries for use with the **Bluetooth-Speaker**

📄 **[Documentation](Documentation)** • Data sheets, other references

🎥 **[Video](Video)** • Demonstration videos of the final project

🎲 **[Prototype](Prototype)** • Evaluation board, Cases, etc...

To Do List
-------------------

🔴 **Minimize the use of microcontrollers as the esp32 can handle much of the work done by atmegas.**
	
🔴 **Battery efficiency is critical here so using every possible way to reduce the consumption is needed.**
	
🔴 **The front PCB can only display time. I wanted to display weather temperature too with the help of ESP32.**


