//------------------- INCLUDES --------------------------
#include "AXP192.h"

//------------------- FUNCTIONS --------------------------
AXP192::AXP192(TwoWire &i2cPort)
{
	_i2cPort = &i2cPort;
}

//-------------------------------------------------------------
AXP192::~AXP192()
{
}

//-------------------------------------------------------------
uint8_t AXP192::read8bit(const uint8_t addr)
{
	read( addr, 1 );
    return (uint8_t)_i2cPort->read();
}

//-------------------------------------------------------------
uint16_t AXP192::read12Bit(const uint8_t addr)
{
	uint16_t val = 0;
	uint8_t buf[2];
    read( addr, 2, buf );
	val = ((buf[0] << 4) + buf[1]);
	return val;
}

//-------------------------------------------------------------
uint16_t AXP192::read13Bit(const uint8_t addr)
{
	uint16_t val = 0;
	uint8_t buf[2];
    read( addr, 2, buf );
	val = ( ( buf[0] << 5 ) + buf[1] );
	return val;
}

//-------------------------------------------------------------
void AXP192::read(const uint8_t addr, uint8_t length)
{
	_i2cPort->beginTransmission( AXP192_ADDRESS );
	_i2cPort->write( addr );
	_i2cPort->endTransmission();
	_i2cPort->requestFrom( AXP192_ADDRESS, length);
}

//-------------------------------------------------------------
void AXP192::read(const uint8_t addr, uint8_t length, uint8_t *data)
{
	read( addr, length );
    for( uint8_t i = 0; i < length; i++ ){
		data[ i ] = (uint8_t)_i2cPort->read();
    }
}

//-------------------------------------------------------------
void AXP192::send(const uint8_t addr, uint8_t data)
{
	_i2cPort->beginTransmission( AXP192_ADDRESS );
	_i2cPort->write( addr );
	_i2cPort->write( data );
	_i2cPort->endTransmission();
}

//-------------------------------------------------------------
void AXP192::getBatVoltage(float &variable)
{
	variable = 1.1 / 1000.0;
	uint16_t ReData = read12Bit( AXP192_BATTERY_VOLTAGE );
	variable = ReData * variable;
}

//-------------------------------------------------------------
void AXP192::getBatCharge(uint8_t &variable)
{
	variable = read8bit( AXP192_CHARGE_STATUS );
}

//-------------------------------------------------------------
void AXP192::getLDO2Voltage(uint8_t &variable)
{
	variable = read8bit( AXP192_LDO23_VOLTAGE ) >> 4;
}

//-------------------------------------------------------------
void AXP192::getLDO3Voltage(uint8_t &variable)
{
	variable = ( read8bit( AXP192_LDO23_VOLTAGE ) << 4 ) >> 4;
}

//-------------------------------------------------------------
void AXP192::offLDO3Voltage(void)
{
	this->send( AXP192_DCDC13_LDO23_CONTROL );
}

//-------------------------------------------------------------
//-------------------------------------------------------------
//-------------------------------------------------------------
//-------------------------------------------------------------
//-------------------------------------------------------------
//-------------------------------------------------------------
//-------------------------------------------------------------
//-------------------------------------------------------------
//-------------------------------------------------------------
//-------------------------------------------------------------
