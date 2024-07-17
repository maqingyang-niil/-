/*
软件模拟SPI
Qingyang Ma
修改时间：2024-7-17
*/
#ifndef __SOFT_SPI_H_
#define __SOFT_SPI_H_
#include "stm32f4xx_hal.h"
#include "utility.h"
#define SPI_SS_PORT     GPIOA
#define SPI_SCK_PORT    GPIOC
#define SPI_MOSI_PORT   GPIOC
#define SPI_MISO_PORT   GPIOA
#define SPI_SS_PIN      GPIO_PIN_3
#define SPI_SCK_PIN     GPIO_PIN_5
#define SPI_MOSI_PIN    GPIO_PIN_4
#define SPI_MISO_PIN    GPIO_PIN_7
#define SS_RCC          __HAL_RCC_GPIOA_CLK_ENABLE()
#define SCK_RCC         __HAL_RCC_GPIOC_CLK_ENABLE()
#define MOSI_RCC        __HAL_RCC_GPIOC_CLK_ENABLE()
#define MISO_RCC        __HAL_RCC_GPIOA_CLK_ENABLE()

#define SPI_SS(n)       {HAL_GPIO_WritePin(SPI_SS_PORT,SPI_SS_PIN,boolize(n));}
#define SPI_SCK(n)      {HAL_GPIO_WritePin(SPI_SCK_PORT,SPI_SCK_PIN,boolize(n));}
#define SPI_MOSI(n)     {HAL_GPIO_WritePin(SPI_MOSI_PORT,SPI_MOSI_PIN,boolize(n));}
#define SPI_MISO(n)     {HAL_GPIO_WritePin(SPI_MISO_PORT,SPI_MISO_PIN,boolize(n));}

#define SPI_MISO_READ   HAL_GPIO_ReadPin(SPI_MISO_PORT,SPI_MISO_PIN)

void SPI_GPIO_INIT();
uint8_t SPI_SwapByte(uint8_t ByteSend);
void SPI_STOP();
void SPI_START();




#endif