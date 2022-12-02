
# Main-PCB
<p align="center">

This PCB has the amplifier, and Bluetooth module BT-806 

🔴 Amplifier (TAS5825)	<a href="https://www.ti.com/product/TAS5825" alt="repo-size">
		<img src="https://img.shields.io/badge/Chip-TAS5825-yellow.svg" /></a>
-------------------
 The reason behind this choice contains a lot of factors. There was many potential Amplifiers for this design. Including:

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


 TPA3130 and TPA3129 Both have the same footprint which make it easier to populate either one. The difference is that TPA3129 has **Low idle power** consumption. Both are capable of outputing 30W , 2X15W.

	🔺 **TAS5825M OR TAS5825P** Will be the upgrade of the (TPA3130 OR TPA3129) since it has lower distortion and built in DSP (Digital Signal Processing), plus it can output 38-W stereo which is more than enough. Only draw back is it does needs uC to configure it.



🔴 Bluetooth module (BT-806)   <a href="https://www.feasycom.net/dual-mode-bluetooth-module/bluetooth-5-0-csr8675-aptx-audio-module-fsc.html
" alt="repo-size">
		<img src="https://img.shields.io/badge/Chip-BT 806-yellow.svg" /></a>
-------------------

The Bluetooth module is critical piece of the design, a lot of thoughts went into this. The [*FSC-BT806 Feasycom*](https://github.com/Mala2/FSC-BT806) has a great module which integrate the Qualcomm® CSR8675 - Bluetooth V5.0 Support HSP, HFP, A2DP, AVRCP, PBAP,MAP,SPP,BLE profile - Coverage up to 15m - True Wireless Stereo to share BT audio stream between two Speakers - Wired analog input.

This chip can output stero mode with high sound quality, plus it is easy to program which I did not get deep into. I was able to change the Bluetooth discoverable name as I wish. Through **TX/RX** pins it can communicate to other microcontrollers. I for sure haven’t used all the potential futures this Module can offer due to my luck of coding experience. Otherwise this chip is a uC and can be the master mind to control all this chips this design needs through I2C, PIOs, AIOs and LEDs for status indications (Low Battery, Bluetooth Status). Also, it supports **ANCS** The purpose of the Apple Notification Center Service (ANCS) is to give Bluetooth accessories (that connect to iOS devices through a Bluetooth low-energy link) a simple and convenient way to access many kinds of notifications that are generated on iOS devices. Finally, it can charges the battery with 200mA which wasn’t practical in this design since it has 5000mAh battery which will take up to 25 Hours for full charge. However, it would be suitable for smaller Speaker design.



To be continued ...
