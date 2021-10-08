
# Main-PCB
<p align="center">
**⚠  This PCB is currently still under development. ⚠️**
  
This PCB has the amplifier, boost converters and Bluetooth module BT-806 and Atmega328 uC.
  
Amplifier (TPA3130 OR TPA3129)
-------------------
  The reason behind this choice contains a lot of factors. There was many potential Amplifiers for this design. Including:
- Texas instruments- TPA3130, TPA3116, TPA3129
- Analog Devices- SSM2306
- Diodes Incorporated- PAM8403
- Maxim Integrated- MAX98306, MAX9736,

 
To choose the suitable one I considered the key measurements are:
  
- SNR
- PSRR
- Efficiency
- CMRR
- Quiescent current
- THD+NOISE(half power)
- Output noise
- Crosstalk

For the SNR 
  
1. TPA3116, TPA3130 **102db**
2. MAX98306 **99db**
3. SSM2302  **98db**
4. MAX9736  **97db**
5. PAM8403  **80db**
  
**Clearly the winer here is TPA3130, TPA3116**
  
  
For the PSRR 
  
  
  Both have the same footprint which make it easier to populate either one. The difference is that TPA3129 has **Low idle power** consumption. Both are capable of outputing 30W , 2X15W. 
