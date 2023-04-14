/*
 * bmp180.h
 *
 *  Created on: Apr 13, 2023
 *      Author: LENOVO
 */

#ifndef INC_BMP180_H_
#define INC_BMP180_H_

#include "stm32f4xx_hal.h"
#include <math.h>

typedef struct{
	int16_t ac1;
	int16_t ac2;
	int16_t ac3;
	uint16_t ac4;
	uint16_t ac5;
	uint16_t ac6;
	int16_t b1;
	int16_t b2;
	int16_t mb;
	int16_t mc;
	int16_t md;

}BMP180_Calibration_Data;

enum oversampling{
	ultra_low_power = 5,
	standard = 8,
	high_resolution = 14,
	ultra_high_resolution = 26,
	advanced_resolution = 77
};

// BMP180 register addresses
#define BMP180_REG_CALIB_START      0xAA
#define BMP180_REG_CTRL_MEAS        0xF4

// BMP180 commands
#define BMP180_CMD_READ_TEMP        0x2E
#define BMP180_CMD_READ_PRESSURE    0x34

// BMP180 oversampling settings
#define BMP180_OSS                  0 // Oversampling setting (0-3)

// BMP180 device addresses
#define BMP180_ADDR_WRITE           0xEE // Device address for write mode
#define BMP180_ADDR_READ            0xEF // Device address for read mode

//atmospheric pressure
#define ATM_PRESSURE				101325

void bmp180_init(void);
float bmp180_read_temperature(void);
float bmp180_read_pressure(uint8_t oss);
float bmp180_read_altitude(int oss);


#endif /* INC_BMP180_H_ */
