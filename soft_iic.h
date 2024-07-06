/*
软件模拟IIC
Qingyang Ma
修改时间：2024-7-2
*/
#ifndef __SOFT_IIC_H
#define __SOFT_IIC_H
#include "stm32f4xx_hal.h"
//bool值返回函数
uint8_t boolize(uint8_t n);
//systick延时函数
void delay_us(uint16_t us);
//IIC端口封装
#define IIC_GPIO_SDA_PORT       GPIOB
#define IIC_GPIO_SCL_PORT       GPIOB
#define IIC_SCL_PIN             GPIO_PIN_6
#define IIC_SDA_PIN             GPIO_PIN_7
#define IIC_GPIO_RCC_EN         __HAL_RCC_GPIOB_CLK_ENABLE()
#define IIC_SDA(n)          {HAL_GPIO_WritePin(IIC_GPIO_SDA_PORT,IIC_SDA_PIN,boolize(n));delay_us(20);}
#define IIC_SCL(n)          {HAL_GPIO_WritePin(IIC_GPIO_SCL_PORT,IIC_SCL_PIN,boolize(n));delay_us(20);}
#define IIC_SDA_READ        HAL_GPIO_ReadPin(IIC_GPIO_SDA_PORT,IIC_SDA_PIN)


void IIC_GPIO_INIT();
uint8_t IIC_ReceiveAck();
void IIC_SendAck(uint8_t Ack);
uint8_t IIC_ReceiveByte();
void IIC_SendByte(uint8_t mes);
void IIC_STOP();
void IIC_START();

#endif