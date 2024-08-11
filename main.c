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

static FRESULT miscellaneous()
{
  DIR* dir;
  FATFS* pfs;
  FIL* fnew;
  DWORD fre_clust,fre_sector,tot_sector;
  FRESULT res_flash;
  BYTE readBuffer[20];
  UINT* fnum;
  res_flash=f_getfree("1:",&fre_clust,&pfs);
  /*总扇区数和空扇区数，用来计算使用率*/
  tot_sector=(pfs->n_fatent-2)*pfs->csize;
  fre_sector=pfs->free_clst*pfs->csize;
  res_flash=f_open(fnew,"1:old",FA_CREATE_ALWAYS|FA_READ|FA_WRITE);
  res_flash=f_write(fnew,"101100010",20,fnum);
  if (res_flash==FR_OK)
  {
    res_flash=f_lseek(fnew,f_size(fnew)-1);
    if (res_flash==FR_OK)
    {
      f_printf(fnew,"101100010");
      res_flash=f_lseek(fnew,0);
      res_flash=f_read(fnew,readBuffer,f_size(fnew),fnum);
      if (res_flash==FR_OK)
      {
        //读取到的数据
      }
    }
    f_close(fnew);
    res_flash=f_opendir(dir,"1:testDir");
    if (res_flash!=FR_OK)
    {
      res_flash=f_mkdir("1:testDir");

    }
    else
    {
      res_flash=f_closedir(&dir);
      f_unlink("1:testDir/testdir.txt");
    }
    if (res_flash==FR_OK)
    {
      res_flash=f_rename("1:old","1:testDir/testdir.txt");
      if (res_flash==FR_OK)
      {

      }
      else
      {

      }
    }
  }
  else
  {

  }
  return res_flash;
}



