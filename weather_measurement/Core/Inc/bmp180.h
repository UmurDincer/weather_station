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


enum oversampling{
	ultra_low_power,
	standard ,
	high_resolution,
	ultra_high_resolution,
	advanced_resolution
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
uint16_t uncompensated_temperature(void);
float bmp180_read_temperature(void);
uint32_t uncompensated_pressure(int oversampling);
float bmp180_read_pressure(uint8_t oss);
float bmp180_read_altitude(int oss);


#endif /* INC_BMP180_H_ */
