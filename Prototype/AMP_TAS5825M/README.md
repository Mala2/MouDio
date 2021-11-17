# TAS5825M OR TAS5825P

It is a class D amplifier with 90 mΩ RDS. It can output 2 × 30 W, at 24V on 8Ω driver load.

I initially intended to use **TAS5825M** but I found out that **TAS5825P** has Hybrid Pro algorithm to extend the battery life by more than 50% and it is pin-pin compatible with **TAS5825M**.


The [*FSC-BT806 Feasycom*](https://github.com/Mala2/FSC-BT806) can output analog which can be fed to the ADC **PCM1820** PCB to output 32-bits, 2-channel I2S/TDM then that can be fed to amplifier **[TAS5825M](/Prototype/AMP_TAS5825M/)** PCB. Also,The [*FSC-BT806 Feasycom*](https://github.com/Mala2/FSC-BT806) can output 2-channel I2S to directly connect to **[TAS5825M](/Prototype/AMP_TAS5825M/)** PCB if that desirable.

I added there diffrent PCBs design on the **[PCM1820](/Prototype/ADC_PCM1820/)** PCB for the input capacitor to test diffrent values and Cap materials.


Input capacitors
-------------------

•  **Film SMT Caps** P/N: 4.7uF [35MU475KC44532](https://www.digikey.com/en/products/detail/rubycon/35MU475KC44532/9951738) 

•  **CER SMD Caps** P/N: 1uF [C1608X7R1C105K080AC](https://www.digikey.com/en/products/detail/tdk-corporation/C1608X7R1C105K080AC/634395) - 4.7uF [CGA4J3X7R1C475K125AB](https://www.digikey.com/en/products/detail/tdk-corporation/CGA4J3X7R1C475K125AB/2672862) - 10uF [CC0805KKX7R5BB106](https://www.digikey.com/en/products/detail/yageo/CC0805KKX7R5BB106/5195283)
 
•  **Film TH Caps** P/N: 4.7uF [R75PW447050H3J](https://www.digikey.com/en/products/detail/kemet/R75PW447050H3J/12144250) 

I added a dot • to indicate the right corresponding position to the main PCB

Those little PCBs can also be mounted as an **Input capacitors** on the **[PCM1820](/Prototype/ADC_PCM1820/)** PCB

Power Supply 
-------------------
Voltage: 4.5-26V, recommended 12-24V




