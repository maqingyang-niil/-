#ifndef __MPU6050_H
#define __MPU6050_H
#include "soft_iic.h"

#define MPU6050_ADDR      0xD0
#define MPU6050_WHO_I_AM  0x75











void IIC_Mpu6050_Write_byte(uint8_t address,uint8_t data);
void IIC_Mpu6050_Write_MultiByte(uint8_t address,uint8_t *data,uint8_t size);
uint8_t IIC_Mpu6050_Read_Byte(uint8_t address);
uint8_t*IIC_Mpu6050_Read_MultiByte(uint8_t address,uint8_t *data,uint8_t size);

#endif