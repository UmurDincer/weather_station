/*
 * dht11.h
 *
 *  Created on: Apr 13, 2023
 *      Author: LENOVO
 */

/*
 * dht11.h
 *
 *  Created on: 23 Kas 2022
 *      Author: LENOVO
 */

#ifndef INC_DHT11_H_
#define INC_DHT11_H_

#include "main.h"

#define milisec 0
#define microsec 1
#define INPUT 0
#define OUTPUT 1

typedef struct{
	float temperature;
	float humidity;
}DHT11_HandleTypeDef;

void set_DHT_Input_Output(uint8_t in_out);
uint8_t DHT11_Read_Value(DHT11_HandleTypeDef *hdht11);
void helper_delay_us(uint32_t us);
#endif /* INC_DHT11_H_ */
