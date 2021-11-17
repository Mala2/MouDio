# PCM1820

It is an **ADC** with resolution of 32-bit I2S/TDM

The [*FSC-BT806 Feasycom*](https://github.com/Mala2/FSC-BT806) can output analog which can be fed to the ADC **PCM1820** PCB to output 32-bits, 2-channel I2S/TDM then that can be fed to the amplifier **[TAS5825M](/Prototype/AMP_TAS5825M/)** PCB

I added there diffrent PCBs design for the input capacitor to test diffrent values and Cap materials


Input capacitors
-------------------

•  **Film SMT Caps** P/N: 4.7uF [35MU475KC44532](https://www.digikey.com/en/products/detail/rubycon/35MU475KC44532/9951738) 

•  **CER SMD Caps** P/N: 1uF [C1608X7R1C105K080AC](https://www.digikey.com/en/products/detail/tdk-corporation/C1608X7R1C105K080AC/634395) - 4.7uF [CGA4J3X7R1C475K125AB](https://www.digikey.com/en/products/detail/tdk-corporation/CGA4J3X7R1C475K125AB/2672862) - 10uF [CC0805KKX7R5BB106](https://www.digikey.com/en/products/detail/yageo/CC0805KKX7R5BB106/5195283)
 
•  **Film TH Caps** P/N: 4.7uF [R75PW447050H3J](https://www.digikey.com/en/products/detail/kemet/R75PW447050H3J/12144250) 

I added a dot • to indicate the right corresponding position to the main PCB

Those little PCBs can also be mounted as an **Input capacitors** on the **[TAS5825M](/Prototype/AMP_TAS5825M/)** PCB

Power Supply 
-------------------
Voltage: 5V choose to populate either **BL9198-33** or **LP5912-3.3** LDO. I prefare the **LP5912-3.3** as it has LOW IQ and LOW Noise





