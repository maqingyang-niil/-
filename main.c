#include "main.h"

FATFS fs;
FRESULT res_flash;
FIL fnew;
BYTE writeBuffer[]="01010011";
UINT fnum;
BYTE readBuffer[10];














void SystemClock_Config(void);
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
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 16;
  RCC_OscInitStruct.PLL.PLLN = 192;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
  {
    Error_Handler();
  }
}
/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
