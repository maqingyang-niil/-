#include "mpu6050.h"
void IIC_Mpu6050_Write_byte(uint8_t address,uint8_t data)
{
    IIC_START();
    IIC_SendByte(MPU6050_ADDR);
    IIC_ReceiveAck();
    IIC_SendByte(address);
    IIC_ReceiveAck();
    IIC_SendByte(data);
    IIC_ReceiveAck();
    IIC_STOP();
}
void IIC_Mpu6050_Write_MultiByte(uint8_t address,uint8_t *data,uint8_t size)
{
    IIC_START();
    IIC_SendByte(MPU6050_ADDR);
    IIC_ReceiveAck();
    IIC_SendByte(address);
    IIC_ReceiveAck();
    for (uint8_t i=0;i<size;i++)
    {
        IIC_SendByte(*data);
        IIC_ReceiveAck();
        ++data;
    }
    IIC_STOP();
}
uint8_t IIC_Mpu6050_Read_Byte(uint8_t address)
{
    uint8_t data;
    IIC_START();
    IIC_SendByte(MPU6050_ADDR);
    IIC_ReceiveAck();
    IIC_SendByte(address);
    IIC_ReceiveAck();

    IIC_START();
    IIC_SendByte(MPU6050_ADDR|0x01);
    IIC_ReceiveAck();
    data=IIC_ReceiveByte();
    IIC_SendAck(1);
    IIC_STOP();
    return data;
}
uint8_t*IIC_Mpu6050_Read_MultiByte(uint8_t address,uint8_t *data,uint8_t size)
{
    IIC_START();
    IIC_SendByte(MPU6050_ADDR);
    IIC_ReceiveAck();
    IIC_SendByte(address);
    IIC_ReceiveAck();
    IIC_START();
    IIC_SendByte(MPU6050_ADDR|0x01);
    IIC_ReceiveAck();
    for (uint8_t i=0;i<size;i++)
    {
        (*data)=IIC_ReceiveByte();
        IIC_SendAck(0);
        ++data;
    }
    IIC_SendAck(1);
    IIC_STOP();
    return data;
}




