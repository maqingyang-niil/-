#include "soft_spi.h"
void SPI_GPIO_INIT()
{
    SS_RCC;
    SCK_RCC;
    MOSI_RCC;
    MISO_RCC;
    GPIO_InitTypeDef GPIO_INIT_STRUCTURE;
    //SS
    GPIO_INIT_STRUCTURE.Mode=GPIO_MODE_OUTPUT_PP;
    GPIO_INIT_STRUCTURE.Pin=SPI_SS_PIN;
    GPIO_INIT_STRUCTURE.Speed=GPIO_SPEED_FAST;
    HAL_GPIO_Init(SPI_SS_PORT,&GPIO_INIT_STRUCTURE);
    //SCK
    GPIO_INIT_STRUCTURE.Mode=GPIO_MODE_OUTPUT_PP;
    GPIO_INIT_STRUCTURE.Pin=SPI_SCK_PIN;
    GPIO_INIT_STRUCTURE.Speed=GPIO_SPEED_FAST;
    HAL_GPIO_Init(SPI_SCK_PORT,&GPIO_INIT_STRUCTURE);
    //MOSI
    GPIO_INIT_STRUCTURE.Mode=GPIO_MODE_OUTPUT_PP;
    GPIO_INIT_STRUCTURE.Pin=SPI_MOSI_PIN;
    GPIO_INIT_STRUCTURE.Speed=GPIO_SPEED_FAST;
    HAL_GPIO_Init(SPI_MOSI_PORT,&GPIO_INIT_STRUCTURE);
    //MISO
    GPIO_INIT_STRUCTURE.Mode=GPIO_MODE_INPUT;
    GPIO_INIT_STRUCTURE.Pin=SPI_SS_PIN;
    GPIO_INIT_STRUCTURE.Speed=GPIO_SPEED_FAST;
    GPIO_INIT_STRUCTURE.Pull=GPIO_PULLUP;
    HAL_GPIO_Init(SPI_MISO_PORT,&GPIO_INIT_STRUCTURE);
    SPI_SS(1);
    SPI_SCK(0);
}
void SPI_START()
{
    SPI_SS(0);
}
void SPI_STOP()
{
    SPI_SS(1);
}
/*

uint8_t SPI_SwapByte(uint8_t ByteSend)
{
    uint8_t i,ByteReceive=0x00;
    for (i=0;i<8;i++)
    {
        SPI_MOSI(ByteSend&(0x80>>i));
        SPI_SCK(1);
        if (SPI_MISO_READ)
        {
            ByteReceive|=(0x80>>i);
        }
        SPI_SCK(1);
    }
    
    return ByteReceive;
}
*/
uint8_t SPI_SwapByte(uint8_t ByteSend)
{
    for (uint8_t i=0;i<8;i++)
    {
        SPI_MOSI(ByteSend&0x80);
        ByteSend<<1;
        SPI_SCK(1);
        if (SPI_MISO_READ)
        {
            ByteSend|=0x01;
        }
        SPI_SCK(0);
    }
    return ByteSend;
}
