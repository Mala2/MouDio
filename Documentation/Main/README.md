
# Main-PCB
<p align="center">
**⚠  This PCB is currently still under development. ⚠️**
  
This PCB has the amplifier, boost converters and Bluetooth module BT-806 and Atmega328 uC.
  
Amplifier (TPA3130 OR TPA3129)
-------------------
  The reason behind this choice contains a lot of factors. There was many potential Amplifiers for this design. Including:
- 🔹Texas instruments- TPA3130, TPA3116, TPA3129
- Analog Devices- SSM2306
- Diodes Incorporated- PAM8403
- Maxim Integrated- MAX98306, MAX9736,

 
To choose the suitable one I considered the key measurements are:
  
- SNR
- PSRR
- Efficiency
- CMRR
- Quiescent current
- THD+NOISE
- Output noise
- Crosstalk

For the SNR (Signal-to-noise ratio):
  
1. 🔹TPA3116, TPA3130 **102db**
2. MAX98306 ➡️ **99db**
3. SSM2302 ➡️ **98db**
4. MAX9736 ➡️ **97db**
5. PAM8403 ➡️ **80db**
  
**Clearly the winer here is TPA3130, TPA3116**
  
  
For the PSRR (Power supply rejection ratio):
  
**TPA3130 along with MAX98306 has the best performance**
  
For the Efficiency:
1. MAX98306 ➡️ **92\%**
2. 🔹TPA3130 ➡️ **90\%**
3. MAX9736 ➡️ **88\%**
4. PAM8403 ➡️ **87\%**
5. SSM2301 ➡️ **85\%**

**Again TPA3130 along with MAX98306 has the best performance**
  
For the CMRR (Common-mode rejection ratio):
1. MAX98306 ➡️ **79db**
  
No available data for the rest
  
 For the  Quiescent current:

1. MAX98306 ➡️ **2 mA**
2. 🔹TPA3130 ➡️ **4 mA**
3. PAM8403 ➡️ **16 mA**
4. MAX9736 ➡️ **30 mA**
5. TPA3116 ➡️ **32 mA**
  
For the THD+NOISE:
  
**Most of the amplifiers has approximately the same results.**

For the Output noise:

1. MAX98306 ➡️ **29uV**
2. SSM2302 ➡️ **35uV**
3. 🔹TPA3130 ➡️ **65uV**
4. MAX9736, PAM8403 ➡️ **100uV**
  
  
**We can see how **MAX98306** has a good performance**
  
Lastly the Crosstalk:  
1. MAX98306 
2. 🔹TPA3130 
3. SSM2302 
4. MAX9736 
5. PAM8403 
  
**Again TPA3130 along with MAX98306 has the best performance**

Final Decision  
-------------------
  
**MAX98306 and (TPA3130 OR TPA3129) has the best results even though MAX98306 is better I would rather choose (TPA3130 OR TPA3129) for the output power reaching 30W in Mono setup and 2X15W in Stereo setup while MAX98306 can only output 3.7W which wasn’t enough for this Design.**
	<a href="https://www.ti.com/product/TPA3130D2" alt="repo-size">
		<img src="https://img.shields.io/badge/Winner-TPA3130 OR TPA3129-yellow.svg" /></a>
  
 TPA3130 and TPA3129 Both have the same footprint which make it easier to populate either one. The difference is that TPA3129 has **Low idle power** consumption. Both are capable of outputing 30W , 2X15W. 
