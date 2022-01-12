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
	




[![image](https://user-images.githubusercontent.com/63622787/149161019-443c6ed5-2b7f-4a77-8a0c-c58f14e8bd33.png)](https://a360.co/3340jVi)
[![image](https://user-images.githubusercontent.com/63622787/149161185-76ba31c0-4a93-4759-8a88-698c24c4fad2.png)](https://a360.co/3340jVi)


[*🎨 View on FUSION 360*](https://a360.co/3340jVi)

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

🎲 **[Prototype](Prototype)** • Evaluation board, Cases, etc...

	
	
Schematic
-------------------
🟢This is the ****[Main](Documentation/Main/)**** PCB it contain the **Amplifier** - 2x  Texas Instruments® **TAS5825M** and The **FSC-BT806 Feasycom**
	
![image](https://user-images.githubusercontent.com/63622787/149163751-7493e482-d3c2-45de-859b-50efd5079e94.png)
![image](https://github.com/Mala2/Bluetooth-Speaker/blob/main/STL-Files/Pics/USB-C%20pcb.png?raw=true)

[📐 *View on FUSION 360*](https://a360.co/3FjaXoa)

	
🟢This is the ****[USB-C](Documentation/USB-C/)**** PCB it contain the **MP2639** - 2S charging IC and The **Atmega328**
	
![image](https://user-images.githubusercontent.com/63622787/149164263-51866652-72fa-4304-86ee-b4834d0e1bf9.png)
![image](https://github.com/Mala2/Bluetooth-Speaker/blob/main/STL-Files/Pics/Main%20pcb1.png?raw=true)
	
[📐 *View on FUSION 360*](https://a360.co/3fcBBV4)

	
Components
-------------------

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

		
	
To Do List
-------------------

🔴 **Minimize the use of microcontrollers as the esp32 can handle much of the work done by atmegas.**
	
🔴 **Battery efficiency is critical here so using every possible way to reduce the consumption is needed.**
	
🔴 **The front PCB can only display time. I wanted to display weather temperature too with the help of ESP32.**


