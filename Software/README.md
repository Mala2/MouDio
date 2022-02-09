To Do List
-------------------
	
1- Turns the bt806 after turning the 3v3. Sending a high signal to Vreg for > 2. Upon waking up. (OR MOSFET NETWORK)

2- if the battery < 15% shut down the speaker. 

3-  if the battery <35% set the MAX volume to be less than 70%. In other words reduces the volume to not consume more power. 

4- (after checking the vol range of bt806), send a command AT+SPKVOL and check the volume range of bt806 sent. After that set the TAS5825 accordingly. That can be done with two registers either AGAIN or DIGITAL_VOL. 

5-For example once the right left happens (Next Song). The leds should indicate that. From left to right emotions. ->

6-if no sounds or connection established for 30 min turn off the speaker

7- if charger inserted activate the haptic driver as a feedback 
