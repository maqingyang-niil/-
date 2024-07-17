#ifndef __W25Q64_H_
#define __W25Q64_H_
#include "main.h"

#define W25Q64_WHO_AM_I             0X9F
#define DUMMY_BYTE                  0XFF
#define WRITE_ENABLE                0X06
#define STATUS_REGISTER             0X05
#define PAGE_PROGRAM                0X02
#define SECTOR_ERASE                0X20
#define BLOCK_ERASE                 0XD8
#define READ_DATA                   0X03

void W25Q64_INIT();
void W25Q64_ReadID(uint8_t*MID,uint16_t*DID);
void W25Q64_PageWrite(uint32_t addr,uint8_t*data,uint16_t count);
void W25Q64_SectorErase(uint32_t addr);
void W25Q64_Read(uint32_t addr,uint8_t*data,uint32_t count);










#endif