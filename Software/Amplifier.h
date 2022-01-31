/* My comments */

#ifndef amplifier

#define amplifier

#if (ARDUINO >=100)
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include <Wire.h>


#define toLowByte(w)              ((uint8_t) ((w) & 0xff))
#define toHighByte(w)             ((uint8_t) ((w) >> 8))
#define toUint16(highB, lowB)     ((uint16_t)((uint8_t)highB << 8) + (uint8_t)lowB)
#define BV(bit)                   (1 <<(bit))
#define setBit(byte, bit)         (byte |= BV(bit))
#define clearBit(byte, bit)       (byte &= ~BV(bit))
#define toggleBit(byte, bit)      (byte ^= BV(bit))


#define TAS5825M_ADDRESS                  0x4e // Please check datasheet ti find the correct ADDRS, Try 0x4c in case
#define TAS5825M_ADDRESS_2                0x4c // Please check datasheet ti find the correct ADDRS, Try 0x4c in case
#define IS31_ADDRESS                      0x54 // IS31FL3195 LED Driver https://www.lumissil.com/assets/pdf/core/IS31FL3195_EB.pdf
#define DRV2605_ADDRESS                   0x5A // DRV2605 LRA Driver
#define MAX77962_READ_ADDRESS             0x69 // MAX77962 READ
#define MAX77962_WRITE_ADDRESS            0x68 // MAX77962 WRITE
#define MAX17320                          0x36 // MAX17320

//https://pdfserv.maximintegrated.com/en/an/ug7161-max17320-software-p3.pdf
/////////////////////MAX17320//////////////////////
#define            RepSOC                      0x06 //the final state-of-charge percentage
#define            PCKP                        0xDb //The PCKP register contains the voltage between PACK+ and GND
#define            AvgVCell                    0x19 //average of the VCell register readings
#define            RepCap                      0x05 //average of the VCell register readings
#define            Temp                        0x1B //average of the VCell register readings


/////////////////////MAX77962//////////////////////

//Top
#define            SWRST                      0x2 //Software Reset write 0xA5 *Write, Read
#define            TOP_INT                    0x3 //Top Interrupt *Read Clears All
#define            TOP_INT_MASK               0x4 //Top Interrupt Mask *Write, Read
#define            TOP_INT_OK                 0x5 //Top Status Indicator *Read

//Configurations
#define            CHG_INT                    0x10 //Charger Interrupts *Read Clears All
#define            CHG_INT_MASK               0x11 //Charger Interrupts Mask *Read Clears All
#define            CHG_INT_OK                 0x12 //Charger Status *Read
#define            CHG_DETAILS_00             0x13 //Charger Details 0, QBAT, OTG, CHGIN Status *Read
#define            CHG_DETAILS_01             0x14 //Charger Details 1, Battery, OTG, Temp Status *Read
#define            CHG_DETAILS_02             0x15 //Charger Details 2, #Cells, Swetching Frequency, Application Mode, Therm Status *Read

#define            CHG_CNFG_00                0x16 //Charger configuration 0 Smart Power Selector *Write, Read
#define            CHG_CNFG_01                0x17 //Charger configuration 1 Fast Charge Timer *Write, Read
#define            CHG_CNFG_02                0x18 //Charger configuration 2 Fast Charge Current *Write, Read
#define            CHG_CNFG_03                0x19 //Charger configuration 3 *Write, Read
#define            CHG_CNFG_04                0x1A //Charger configuration 4 Charge Termenatin Voltage *Write, Read
#define            CHG_CNFG_05                0x1B //Charger configuration 5 BATT to SYS current limit, Trickle Charge Current *Write, Read
#define            CHG_CNFG_06                0x1C //Charger configuration 6 Charge Setting Protection *Write, Read
#define            CHG_CNFG_07                0x1D //Charger configuration 7 JEITA battery temperature monitoring *Write, Read
#define            CHG_CNFG_08                0x1E //Charger configuration 8 CHGIN Input Current *Write, Read
#define            CHG_CNFG_09                0x1F //Min SYS requlation, OTG Current Limit *Write, Read
#define            CHG_CNFG_10                0x20 //Min CHGIN Input Voltage *Write, Read




//////////////////////////////////////////////////


/////////////////////TAS5825M//////////////////////
#define            RESET_CHANGE_PAGE          0x00
#define            RESET_CTRL                 0x01
#define            Book                       0x7f
#define            DEVICE_CTRL_1              0x02//
#define            DEVICE_CTRL_2              0x03
#define            I2C_PAGE_AUTO_INC          0x0F
#define            SIG_CH_CTRL                0x28
#define            CLOCK_DET_CTRL             0x29
#define            SDOUT_SEL                  0x30
#define            I2S_CTRL                   0x31
#define            SAP_CTRL1                  0x33
#define            SAP_CTRL2                  0x34
#define            SAP_CTRL3                  0x35
#define            FS_MON                     0x37
#define            BCK                        0x38
#define            CLKDET_STATUS              0x39
#define            DSP_PGM_MODE               0x40
#define            DSP_CTRL                   0x46
#define            DIG_VOL                    0x4C
#define            DIG_VOL_CTRL1              0x4E
#define            DIG_VOL_CTRL2              0x4F
#define            AUTO_MUTE_CTRL             0x50
#define            AUTO_MUTE_TIME             0x51
#define            ANA_CTRL                   0x53
#define            AGAIN                      0x54//
#define            SPI_CLK                    0x55
#define            EEPROM_CTRL0               0x56
#define            EEPROM_RD_CMD              0x57
#define            EEPROM_ADDR_STAR           0x58
#define            EEPROM_ADDR_START1         0x59
#define            EEPROM_ADDR_START2         0x5A
#define            EEPROM_BOOT_STATUS         0x5B
#define            BQ_WR_CTRL1                0x5C
#define            PVDD_ADC                   0x5E
#define            GPIO_CTRL                  0x60
#define            GPIO0_SEL                  0x61
#define            GPIO1_SEL                  0x62
#define            GPIO2_SEL                  0x63
#define            GPIO_INPUT_SEL             0x64
#define            GPIO_OUT                   0x65
#define            GPIO_OUT_INV               0x66
#define            DIE_ID                     0x67
#define            POWER_STATE                0x68
#define            AUTOMUTE_STATE             0x69
#define            PHASE_CTRL                 0x6A
#define            SS_CTRL0                   0x6B
#define            SS_CTRL1                   0x6C
#define            SS_CTRL2                   0x6D
#define            SS_CTRL3                   0x6E
#define            SS_CTRL4                   0x6F
#define            CHAN_FAULT                 0x70
#define            GLOBAL_FAULT1              0x71
#define            GLOBAL_FAULT2              0x72
#define            WARNING                    0x73
#define            PIN_CONTROL1               0x74
#define            PIN_CONTROL2               0x75
#define            MISC_CONTROL               0x76
#define            CBC_CONTROL                0x77
#define            FAULT_CLEAR                0x78
///////////////////////////////////////////////////

class Amplifier  {

  public:
    Amplifier();

/////////////////////TAS5825M//////////////////////
    void init();
    void Vol_Down (void);
    void wake_AMP (void);
    void sleep_AMP (void);
    int getRESET_CHANGE_PAGE();
    int getBook();
    int getDIG_VOL();
    int getRESET_CTRL();
    int getDIE_ID();
    int getDEVICE_CTRL_1();
    int getDEVICE_CTRL_2();
    int getSIG_CH_CTRL();
    int getSAP_CTRL1();
    int getBCK();
    int getAGAIN();
    int getFAULT_CLEAR();
    int getCLKDET_STATUS();
    int getPOWER_STATE();
    int getAUTOMUTE_STATE();
    int getCHAN_FAULT();
    int getGLOBAL_FAULT1();
    int getGLOBAL_FAULT2();
    int getWARNING();
    int getFS_MON();
    int getPVDD_ADC();
    int getGPIO0_SEL();

////////////////////IS31FL3195////////////////////
    void init_IS31FL3195();
    void Mode_IS31FL3195();
    void show_LED(void);
    void sleep_led(void);
    void show_led_0(void);
    void show_led_25(void);
    void show_led_50(void);
    void show_led_75(void);
    void show_led_100(void);
    void show_led_0_flash(void);
    void show_led_25_solid(void);
    void show_led_50_solid(void);
    void show_led_75_solid(void);
    void show_led_100_solid(void);
    void show_led_Next(void);
    void show_led_Back(void);


////////////////////MAX77962//////////////////////
    int get_bat_stat(void);
    put_bat_voltage(void); // why not void
    void otg_on(void);
    void otg_off(void);

    int getCHG_DETAILS_00();
    int getCHG_DETAILS_01();
    int getCHG_DETAILS_02();
    int getCHG_CNFG_00();
    int getCHG_CNFG_01();
    int getCHG_CNFG_02();
    int getCHG_CNFG_03();
    int getCHG_CNFG_04();
    int getCHG_CNFG_05();
    int getCHG_CNFG_06();
    int getCHG_CNFG_07();
    int getCHG_CNFG_08();
    int getCHG_CNFG_09();
    int getCHG_CNFG_10();

/////////////////////MAX77962//////////////////////
    float getPCKP();
    float BATpercent();
    float getAvgVCell();
    float getRepCap();
    float getTemp();

    Amplifier(float);
    bool begin();
    bool begin(bool);
    bool begin(bool, uint8_t);
    bool begin(TwoWire*);
    bool begin(TwoWire*, uint8_t);
    bool begin(TwoWire*, bool, uint8_t);
    uint8_t address();

    uint16_t adc2();
    float voltage();
    float voltage2();
    uint16_t version1();
    uint8_t compensation();
    void compensation(uint8_t);
    bool sleep();
    bool isSleeping();
    bool wake();
    void reset();
    void quickstart();
    bool alertIsActive();
    void clearAlert();
    uint8_t getThreshold();
    void setThreshold(uint8_t);
    bool deviceFound();
    void readRegister_16_N(byte reg, uint16_t *value);



  private:
// General function to read I2c registers
    byte readReg8(int deviceAddress, int regAddress);
    word readReg16(int deviceAddress, int regAddress);
    void writeReg16(int deviceAddress, int regAddress, word data);
    void writeReg8(int deviceAddress, int regAddress, byte data);

  protected:

   TwoWire *_wire;
    uint8_t _address;
    uint16_t readRegister16(uint8_t);
    void writeRegisterId(uint8_t);
    void writeRegister16(uint8_t, uint16_t);



}; // End class in semi-colon...


#endif
