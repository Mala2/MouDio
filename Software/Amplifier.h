/* My comments */

#ifndef amplifier

#define amplifier

#if (ARDUINO >=100)
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#define MUTEPIN                            11

#define CCPIN                             A0


#define BQ25895_ADDRESS                   0x6a
#define TAS5825M_ADDRESS                  0x4e // Please check datasheet ti find the correct ADDRS, Try 0x4c in case 

#define BQ25895_REG_INP_LIM               0x00
#define BQ25895_REG_ADC_DATALINE_CONFIG   0x02
#define BQ25895_REG_WD_CE_SYSVOLT_CONFIG  0x03
#define BQ25895_REG_CHRG_CURRENT_CONFIG   0x04
#define BQ25895_REG_BATFET_CONFIG         0x09
#define BQ25895_REG_VBUS_CHRG_STAT        0x0b
#define BQ25895_REG_ADC_SYS_VOLT          0x0f
#define BQ25895_REG_ADC_VBUS_VOLT         0x11
#define BQ25895_REG_ADC_CHRG_CURRENT      0x12
#define BQ25895_REG_RESET                 0x14


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
#define            AGAIN                      0x54
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

class Amplifier  {
  
  public:
    Amplifier();

    ///////////////////////
    void init(unsigned int digital_volume, unsigned int analog_gain, unsigned int Select_Fsw, unsigned int I2S_Format);
    void VOL_DOWN();
    
    void sleepBtnWake();    
    boolean btnPressed();

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
    void sleep_on(void);
    
    //////////////////////
    
   

  private:
    byte readReg8(int deviceAddress, int regAddress);
    void writeReg16(int deviceAddress, int regAddress, word data);
    void writeReg8(int deviceAddress, int regAddress, byte data);
    
}; // End class in semi-colon...


#endif
