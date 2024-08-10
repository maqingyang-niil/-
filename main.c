#include "main.h"

FATFS fs;
FRESULT res_flash;
FIL fnew;
BYTE writeBuffer[]="01010011";
UINT fnum;
BYTE readBuffer[10];

int main(void)
{
  res_flash=f_mount(&fs,"1:",1);
  if (res_flash==FR_NO_FILESYSTEM)
  {
    res_flash=f_mkfs("1:",0,0,0);
    if (res_flash==FR_OK)
    {
      res_flash=f_mount(NULL,"1:",1);
      res_flash=f_mount(&fs,"1:",1);
    }
    else
    {
      //格式化失败
    }
  } 
  else if (res_flash!=FR_OK)
  {
    //挂载失败
  }
  else
  {
    //挂载成功
  }
  res_flash=f_open(&fnew,"1:storage.txt",FA_CREATE_ALWAYS|FA_WRITE);
  if (res_flash==FR_OK)
  {
    res_flash=f_write(&fnew,writeBuffer,sizeof(writeBuffer),&fnum);
    if (res_flash==FR_OK)
    {
      //写入成功
    }
    else
    {
      //写入失败
    }
    f_close(&fnew);
  }
  else
  {
    //打开文件失败
  }
  res_flash=f_open(&fnew,"1:storage.txt",FA_CREATE_ALWAYS|FA_READ);
  if (res_flash==FR_OK)
  {
    res_flash=f_read(&fnew,readBuffer,sizeof(readBuffer),&fnum);
    if (res_flash==FR_OK)
    {
      //读文件成功
    }
    else
    {
      //读文件失败
    }
    f_close(&fnew);
  }
  else
  {
    //打开文件失败
  }
  f_mount(NULL,"1:",1);
}
