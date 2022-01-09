# Bluetooth-Speaker
<p align="center">
**⚠  This project is currently still under development. If you came from Reddit just wait I will organize the files soon ⚠️**

<p align="center">
   <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/8/87/Arduino_Logo.svg/2560px-Arduino_Logo.svg.png"  width=200>  
   <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/c/c3/Python-logo-notext.svg/1024px-Python-logo-notext.svg.png"  width=135>   
   <img src="https://s3.amazonaws.com/adafruit-circuit-python/CircuitPython_Repo_header_logo.png"  width=335>   

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
	
	
A fully function Bluetooth Speaker implement most of the new ICs chip.

The design consists of four PCBs (MAIN, USB-C, FRONT, TOP) and 3 microcontrollers. I build and test all the PCBs and they work as expected so the hardware design is done. **However, the software part is still under process.**

Please refer to the shared files for more information about specific PCB.

[![🎨 📐 FUSION 360](https://d2t1xqejof9utc.cloudfront.net/screenshots/pics/17f682c999b066592231352874ba1360/large.jpg)](https://a360.co/3uLzq06)



[*🎨 📐 View on FUSION 360*](https://a360.co/3uLzq06)

Features
-------------------
* **Amplifier** - The Texas Instruments® **TPA3130D2** Which has low distrition can output 2 × 15 W Into a 8-Ω BTL Load
* **Connectivity** - The [*FSC-BT806 Feasycom*](https://github.com/Mala2/FSC-BT806) features 
 Qualcomm® **CSR8675** - **Bluetooth V5.0** Support HSP, HFP, A2DP, AVRCP, PBAP,MAP,SPP,BLE profile - Coverage up to 15m - **True Wireless Stereo** to share BT audio stream between two Speakers - **Wired** analog input
* **Power** - Accept **USB PD** Delivery **5 to 24V** - **Fast Charging** in 3 hours - **USB A** Capable of **15W-5V,3A** - **Low idle power** consumption - A**10-hour** battery life - **5000mAh** battery capacity

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


