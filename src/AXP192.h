#ifndef __AXP192_H_
#define __AXP192_H_



//------------------- DEFINES -----------------------------
#define	AXP192_ADDRESS	                (0x34)

/* Power control registers */
#define AXP192_POWER_STATUS             (0x00)
#define AXP192_CHARGE_STATUS            (0x01)
#define AXP192_OTG_VBUS_STATUS          (0x04)
#define AXP192_DATA_BUFFER0             (0x06)
#define AXP192_DATA_BUFFER1             (0x07)
#define AXP192_DATA_BUFFER2             (0x08)
#define AXP192_DATA_BUFFER3             (0x09)
#define AXP192_DATA_BUFFER4             (0x0a)
#define AXP192_DATA_BUFFER5             (0x0b)
/* Output control: 2 EXTEN, 0 DCDC2 */
#define AXP192_EXTEN_DCDC2_CONTROL      (0x10)
/* Power output control: 6 EXTEN, 4 DCDC2, 3 LDO3, 2 LDO2, 1 DCDC3, 0 DCDC1 */
#define AXP192_DCDC13_LDO23_CONTROL     (0x12)
#define AXP192_DCDC2_VOLTAGE            (0x23)
#define AXP192_DCDC2_SLOPE              (0x25)
#define AXP192_DCDC1_VOLTAGE            (0x26)
#define AXP192_DCDC3_VOLTAGE            (0x27)
/* Output voltage control: 7-4 LDO2, 3-0 LDO3 */
#define AXP192_LDO23_VOLTAGE            (0x28)
#define AXP192_VBUS_IPSOUT_CHANNEL      (0x30)
#define AXP192_SHUTDOWN_VOLTAGE         (0x31)
#define AXP192_SHUTDOWN_BATTERY_CHGLED_CONTROL (0x32)
#define AXP192_CHARGE_CONTROL_1         (0x33)
#define AXP192_CHARGE_CONTROL_2         (0x34)
#define AXP192_BATTERY_CHARGE_CONTROL   (0x35)
#define AXP192_PEK                      (0x36)
#define AXP192_DCDC_FREQUENCY           (0x37)
#define AXP192_BATTERY_CHARGE_LOW_TEMP  (0x38)
#define AXP192_BATTERY_CHARGE_HIGH_TEMP (0x39)
#define AXP192_APS_LOW_POWER1           (0x3A)
#define AXP192_APS_LOW_POWER2           (0x3B)
#define AXP192_BATTERY_DISCHARGE_LOW_TEMP  (0x3c)
#define AXP192_BATTERY_DISCHARGE_HIGH_TEMP (0x3d)
#define AXP192_DCDC_MODE                (0x80)
#define AXP192_ADC_ENABLE_1             (0x82)
#define AXP192_ADC_ENABLE_2             (0x83)
#define AXP192_ADC_RATE_TS_PIN          (0x84)
#define AXP192_GPIO30_INPUT_RANGE       (0x85)
#define AXP192_GPIO0_ADC_IRQ_RISING     (0x86)
#define AXP192_GPIO0_ADC_IRQ_FALLING    (0x87)
#define AXP192_TIMER_CONTROL            (0x8a)
#define AXP192_VBUS_MONITOR             (0x8b)
#define AXP192_TEMP_SHUTDOWN_CONTROL    (0x8f)

/* GPIO control registers */
#define AXP192_GPIO0_CONTROL            (0x90)
#define AXP192_GPIO0_LDOIO0_VOLTAGE     (0x91)
#define AXP192_GPIO1_CONTROL            (0x92)
#define AXP192_GPIO2_CONTROL            (0x93)
#define AXP192_GPIO20_SIGNAL_STATUS     (0x94)
#define AXP192_GPIO43_FUNCTION_CONTROL  (0x95)
#define AXP192_GPIO43_SIGNAL_STATUS     (0x96)
#define AXP192_GPIO20_PULLDOWN_CONTROL  (0x97)
#define AXP192_PWM1_FREQUENCY           (0x98)
#define AXP192_PWM1_DUTY_CYCLE_1        (0x99)
#define AXP192_PWM1_DUTY_CYCLE_2        (0x9a)
#define AXP192_PWM2_FREQUENCY           (0x9b)
#define AXP192_PWM2_DUTY_CYCLE_1        (0x9c)
#define AXP192_PWM2_DUTY_CYCLE_2        (0x9d)
#define AXP192_N_RSTO_GPIO5_CONTROL     (0x9e)

/* Interrupt control registers */
#define AXP192_ENABLE_CONTROL_1         (0x40)
#define AXP192_ENABLE_CONTROL_2         (0x41)
#define AXP192_ENABLE_CONTROL_3         (0x42)
#define AXP192_ENABLE_CONTROL_4         (0x43)
#define AXP192_ENABLE_CONTROL_5         (0x4a)
#define AXP192_IRQ_STATUS_1             (0x44)
#define AXP192_IRQ_STATUS_2             (0x45)
#define AXP192_IRQ_STATUS_3             (0x46)
#define AXP192_IRQ_STATUS_4             (0x47)
#define AXP192_IRQ_STATUS_5             (0x4d)

/* ADC data registers */
#define AXP192_ACIN_VOLTAGE             (0x56)
#define AXP192_ACIN_CURRENT             (0x58)
#define AXP192_VBUS_VOLTAGE             (0x5a)
#define AXP192_VBUS_CURRENT             (0x5c)
#define AXP192_TEMP                     (0x5e)
#define AXP192_TS_INPUT                 (0x62)
#define AXP192_GPIO0_VOLTAGE            (0x64)
#define AXP192_GPIO1_VOLTAGE            (0x66)
#define AXP192_GPIO2_VOLTAGE            (0x68)
#define AXP192_GPIO3_VOLTAGE            (0x6a)
#define AXP192_BATTERY_POWER            (0x70)
#define AXP192_BATTERY_VOLTAGE          (0x78)
#define AXP192_CHARGE_CURRENT           (0x7a)
#define AXP192_DISCHARGE_CURRENT        (0x7c)
#define AXP192_APS_VOLTAGE              (0x7e)
#define AXP192_CHARGE_COULOMB           (0xb0)
#define AXP192_DISCHARGE_COULOMB        (0xb4)
#define AXP192_COULOMB_COUNTER_CONTROL  (0xb8)

/* Computed ADC */
#define AXP192_COULOMB_COUNTER          (0xff)

//------------------- STRUCTURES --------------------------



//------------------- VARIABLES ---------------------------


//------------------- INCLUDES --------------------------
#include <stdint.h>
#include <Wire.h>

//------------------- FUNCTIONS --------------------------
class AXP192
{
public:
	AXP192(TwoWire &i2cPort);
	~AXP192();
	uint8_t read8bit(const uint8_t addr);
	uint16_t read12Bit(const uint8_t addr);
	uint16_t read13Bit(const uint8_t addr);
	void read(const uint8_t addr, uint8_t length);
	void read(const uint8_t addr, uint8_t length, uint8_t *data);
	void send(const uint8_t addr, uint8_t data);
	void getBatVoltage(float &variable);
	void getBatCharge(uint8_t &variable);
	void getLDO2Voltage(uint8_t &variable);
	void getLDO3Voltage(uint8_t &variable);
	void offLDO3Voltage(void);
private:
	TwoWire* _i2cPort;
};





#endif //__AXP192_H_
