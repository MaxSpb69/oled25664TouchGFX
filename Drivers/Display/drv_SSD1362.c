/*
 * drv_SSD1362.c
 *
 *  Created on: 16 авг. 2022 г.
 *      Author: maxsp
 */


#include "main.h"
#include <stdlib.h>


volatile int IsTransmittingBlock_ = 0;

extern SPI_HandleTypeDef hspi1;
extern DMA_HandleTypeDef hdma_spi1_tx;
extern TIM_HandleTypeDef htim10;

uint8_t gram[8192];

typedef struct
{
	uint8_t X_Cmd;
	uint8_t X_Start;
	uint8_t X_End;
	uint8_t Y_Cmd;
	uint8_t Y_Start;
	uint8_t Y_End;

}__fill_rect_command_t;


//-------------------------------------------------
//     SSD1362_Write_command
//-------------------------------------------------
void SSD1362_Write_command(uint8_t command)
{

	HAL_GPIO_WritePin(LCD_CS_GPIO_Port,LCD_CS_Pin, GPIO_PIN_RESET);		// CS = 0
	HAL_GPIO_WritePin(LCD_DC_GPIO_Port,LCD_DC_Pin, GPIO_PIN_RESET);		// DC = 0

	HAL_SPI_Transmit(&hspi1, &command, 1, 100);

//	HAL_GPIO_WritePin(LCD_DC_GPIO_Port,LCD_DC_Pin, GPIO_PIN_SET);		// DC = 1
	HAL_GPIO_WritePin(LCD_CS_GPIO_Port,LCD_CS_Pin, GPIO_PIN_SET);		// CS = 1

}



//==================================
//      initial SSD1362
//==================================
void SSD1362_init(void)
{
	HAL_GPIO_WritePin(LCD_RESET_GPIO_Port,LCD_RESET_Pin, GPIO_PIN_RESET);
	HAL_Delay(200);
	HAL_GPIO_WritePin(LCD_RESET_GPIO_Port,LCD_RESET_Pin, GPIO_PIN_SET);

	SSD1362_Write_command(0XFD); //Set Command Lock
	SSD1362_Write_command(0X12); //(12H=Unlock,16H=Lock)

	SSD1362_Write_command(0XAE); //Display OFF(Sleep Mode)

	SSD1362_Write_command(0X15); //Set column Address
	SSD1362_Write_command(0X00); //Start column Address
	SSD1362_Write_command(0X7F); //End column Address

	SSD1362_Write_command(0X75); //Set Row Address
	SSD1362_Write_command(0X00); //Start Row Address
	SSD1362_Write_command(0X3F); //End Row Address

	SSD1362_Write_command(0X81); //Set contrast
	SSD1362_Write_command(0x2f);

	SSD1362_Write_command(0XA0); //Set Remap
	SSD1362_Write_command(0Xc1);

	SSD1362_Write_command(0XA1); //Set Display Start Line
	SSD1362_Write_command(0X00);

	SSD1362_Write_command(0XA2); //Set Display Offset
	SSD1362_Write_command(0X00);

	SSD1362_Write_command(0XA4); //Normal Display

	SSD1362_Write_command(0XA8); //Set Multiplex Ratio
	SSD1362_Write_command(0X3F);

	SSD1362_Write_command(0XAB); //Set VDD regulator
	SSD1362_Write_command(0X01); //Regulator Enable

	SSD1362_Write_command(0XAD); //External /Internal IREF Selection
	SSD1362_Write_command(0X8E);

	SSD1362_Write_command(0XB1); //Set Phase Length
	SSD1362_Write_command(0X22);

	SSD1362_Write_command(0XB3); //Display clock Divider
	SSD1362_Write_command(0XA0);

	SSD1362_Write_command(0XB6); //Set Second precharge Period
	SSD1362_Write_command(0X04);

	SSD1362_Write_command(0XB9); //Set Linear LUT

	SSD1362_Write_command(0XBc); //Set pre-charge voltage level
	SSD1362_Write_command(0X10); //0.5*Vcc

	SSD1362_Write_command(0XBD); //Pre-charge voltage capacitor Selection
	SSD1362_Write_command(0X01);

	SSD1362_Write_command(0XBE); //Set cOM deselect voltage level
	SSD1362_Write_command(0X07); //0.82*Vcc

	SSD1362_Write_command(0XAF); //Display ON
}






void SSD1362_Set_Window(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1)
{
	__fill_rect_command_t Rect_Command;

	Rect_Command.X_Cmd = 0x15;
	Rect_Command.X_Start = x0 / 2;
	Rect_Command.X_End = x1 / 2;
	Rect_Command.Y_Cmd = 0x75;
	Rect_Command.Y_Start = y0;
	Rect_Command.Y_End = y1;

	HAL_GPIO_WritePin(LCD_DC_GPIO_Port,LCD_DC_Pin, GPIO_PIN_RESET);		// DC = 0
	HAL_GPIO_WritePin(LCD_CS_GPIO_Port,LCD_CS_Pin, GPIO_PIN_RESET);		// CS = 0
	HAL_SPI_Transmit(&hspi1, (uint8_t *)&Rect_Command, sizeof(Rect_Command), HAL_MAX_DELAY);
	HAL_GPIO_WritePin(LCD_CS_GPIO_Port,LCD_CS_Pin, GPIO_PIN_SET);		// CS = 1

}

void HAL_SPI_TxCpltCallback(SPI_HandleTypeDef *hspi)
{

	if (hspi->Instance == SPI1)
	{
		HAL_GPIO_WritePin(LCD_CS_GPIO_Port,LCD_CS_Pin, GPIO_PIN_SET);		// CS = 1
		IsTransmittingBlock_ = 0;
		DisplayDriver_TransferCompleteCallback();
	}

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_SPI_TxCpltCallback should be implemented in the user file
   */
}


void touchgfxDisplayInit(void)
{
	SSD1362_init();
	IsTransmittingBlock_ = 0;
}

int touchgfxDisplayDriverTransmitActive(void)
{
	return IsTransmittingBlock_;
}


void touchgfxDisplayDriverTransmitBlock(const uint8_t* pixels, uint16_t x, uint16_t y, uint16_t w, uint16_t h)
{

	IsTransmittingBlock_ = 1;

	SSD1362_Set_Window(x, y, x + w - 1, y + h - 1);

	HAL_GPIO_WritePin(LCD_DC_GPIO_Port,LCD_DC_Pin, GPIO_PIN_SET);		// DC = 1
    HAL_GPIO_WritePin(LCD_CS_GPIO_Port,LCD_CS_Pin, GPIO_PIN_RESET);		// CS = 0
	HAL_SPI_Transmit_DMA(&hspi1, (uint8_t *)pixels, w * h / 2);

}


