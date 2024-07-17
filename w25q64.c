#include "w25q64.h"

void W25Q64_INIT()
{
    SPI_GPIO_INIT();
}
void W25Q64_ReadID(uint8_t*MID,uint16_t*DID)
{
    SPI_START();
    SPI_SwapByte(W25Q64_WHO_AM_I);
    *DID=0;
    *MID=SPI_SwapByte(DUMMY_BYTE);
    *DID=SPI_SwapByte(DUMMY_BYTE);
    *DID<<8;
    *DID|=SPI_SwapByte(DUMMY_BYTE);
    SPI_STOP();
}
void W25Q64_WriteEnable()
{
    SPI_START();
    SPI_SwapByte(WRITE_ENABLE);
    SPI_STOP();
}
void W25Q64_WaitBusy()
{
    SPI_START();
    SPI_SwapByte(STATUS_REGISTER);
    while(SPI_SwapByte(DUMMY_BYTE)&0X01==0X01);
    SPI_STOP();
}
void W25Q64_PageWrite(uint32_t addr,uint8_t*data,uint16_t count)
{
    W25Q64_WaitBusy();
    W25Q64_WriteEnable();
    SPI_START();
    SPI_SwapByte(PAGE_PROGRAM);
    SPI_SwapByte(addr>>16);
    SPI_SwapByte(addr>>8);
    SPI_SwapByte(addr);
    for (uint16_t i=0;i<count;++i)
    {
        SPI_SwapByte(data[i]);
    }
    SPI_STOP();
}
void W25Q64_SectorErase(uint32_t addr)
{
    W25Q64_WaitBusy();
    W25Q64_WriteEnable();
    SPI_START();
    SPI_SwapByte(SECTOR_ERASE);
    SPI_SwapByte(addr>>16);
    SPI_SwapByte(addr>>8);
    SPI_SwapByte(addr);
    SPI_STOP();
}
void W25Q64_Read(uint32_t addr,uint8_t*data,uint32_t count)
{
    W25Q64_WaitBusy();
    SPI_START();
    SPI_SwapByte(READ_DATA);
    SPI_SwapByte(addr>>16);
    SPI_SwapByte(addr>>8);
    SPI_SwapByte(addr);
    for (uint32_t i=0;i<count;++i)
    {
        data[i]=SPI_SwapByte(DUMMY_BYTE);
    }
    SPI_STOP();
}