/*
 * sct.c
 *
 *  Created on: Oct 9, 2024
 *      Author: honzo
 *
 *      This is source file of my SCT library
 */
#include "sct.h"

#define MAX 32

void sct_init(){

	sct_led(0);
}


void sct_value(uint16_t value){


}


void sct_led(uint32_t value){

	for (uint8_t i = 0; i < MAX; ++i) {

		HAL_GPIO_WritePin(SCT_SDI_GPIO_Port, SCT_SDI_Pin, (value >> i)&1);
		//value >>=1;
		HAL_GPIO_WritePin(SCT_CLK_GPIO_Port, SCT_CLK_Pin, 1);
		HAL_GPIO_WritePin(SCT_CLK_GPIO_Port, SCT_CLK_Pin, 0);
	}
	HAL_GPIO_WritePin(SCT_NLA_GPIO_Port, SCT_NLA_Pin,1);
	HAL_GPIO_WritePin(SCT_NLA_GPIO_Port, SCT_NLA_Pin,0);
}
