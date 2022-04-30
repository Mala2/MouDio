To Do List
-------------------
	
🔴 **Need help with software part.**

1- ✅ Turns the bt806 after turning the 3v3. Sending a high signal to Vreg for > 2s Upon waking up then remain Low. (OR MOSFET NETWORK)

2- ✅ if the battery < 15% shut down the speaker. 

3- ✅ if the battery <35% set the MAX volume to be less than 70%. In other words reduces the volume to not consume more power. TAS5825 has register 0x4c and 0x54 (AGAIN or DIGITAL_VOL) to set that.

4- (after checking the vol range of bt806), send a command AT+SPKVOL and check the volume range of bt806 sent. After that set the TAS5825 accordingly. That can be done with two registers either  0x4c and 0x54 (AGAIN or DIGITAL_VOL).

5- ✅ For example once the user swap to right (Next Song). The leds should indicate that. From left to right emotions ->.

6- If no sounds or connection established for 30 min turn off the speaker. Either by checking the current flow from the fuel gauge or the BT-806 is not in play status for more than 30 min. Also, it can be done through GPIO1 of TAS5825 as it will set HIGH/LOW once no sound signal is coming. 

7- ✅ If charger inserted activate the haptic driver as a feedback.

9- If the charger is inserted increase the volume range to be even higher as more power will be provided. 
	
10- add resetFunc() after touching the middle TAP more than 10s. 
	
11- get the header file for the TAS5825M to act as  Dual stereo 2.2.  
	
🔴 **To be continued
