#include "soft_iic.h"
uint8_t boolize(uint8_t n)
{
    if (n!=0)
    return 1;
    else
    return 0;
}
void delay_us(uint16_t us)
{
    uint32_t reload_value=us*(SystemCoreClock/1000000);
    SysTick->LOAD=reload_value;
    SysTick->VAL=0;
    SysTick->CTRL=SysTick_CTRL_ENABLE_Msk;
    while ((SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk) == 0);
    SysTick->CTRL=0;
}
void IIC_START()
{
    IIC_SDA(1);
    IIC_SCL(1);
    IIC_SDA(0);
    IIC_SCL(0);
}
void IIC_STOP()
{
    IIC_SDA(0);
    IIC_SCL(1);
    IIC_SDA(1);
}
//除了STOP中的SCL以高电平结束，所有模块的SCL都以低电平结束，方便拼接
void IIC_SendByte(uint8_t mes)
{
    for (uint8_t i=0;i<8;i++)
    {
        IIC_SDA(mes&(0x80>>i));
        IIC_SCL(1);
        IIC_SCL(0);
    }
}
uint8_t IIC_ReceiveByte()
{
    uint8_t byte=0x00;
    IIC_SDA(1);
    for (uint8_t i=0;i<8;i++)
    {
        IIC_SCL(1);
        if (IIC_SDA_READ)
        byte|=(0x80>>i);
        IIC_SCL(0);
    }
    return byte;
}
void IIC_SendAck(uint8_t Ack)
{
    IIC_SDA(Ack);
    IIC_SCL(1);
    IIC_SCL(0);
}
uint8_t IIC_ReceiveAck()
{
    uint8_t Ack=0x00;
    IIC_SDA(1);
    IIC_SCL(1);
    Ack=IIC_SDA_READ;
    IIC_SCL(0);
    return Ack;
}
void Bus_release()
{  
    IIC_SCL(1);
    IIC_SDA(1);
}
void IIC_GPIO_INIT()
{
    GPIO_InitTypeDef GPIO_INIT_STRUCTURE;
    IIC_GPIO_RCC_EN;
    __HAL_RCC_GPIOB_CLK_ENABLE();
    //SDA
    GPIO_INIT_STRUCTURE.Mode=GPIO_MODE_OUTPUT_OD;
    GPIO_INIT_STRUCTURE.Pin=IIC_SDA_PIN;
    GPIO_INIT_STRUCTURE.Pull=GPIO_PULLUP;
    GPIO_INIT_STRUCTURE.Speed=GPIO_SPEED_FAST;
    HAL_GPIO_Init(IIC_GPIO_SDA_PORT,&GPIO_INIT_STRUCTURE);
    //SCL
    GPIO_INIT_STRUCTURE.Mode=GPIO_MODE_OUTPUT_OD;
    GPIO_INIT_STRUCTURE.Pin=IIC_SCL_PIN;
    HAL_GPIO_Init(IIC_GPIO_SCL_PORT,&GPIO_INIT_STRUCTURE);
    Bus_release();
}


