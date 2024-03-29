/**
  ******************************************************************************
  * @file    EXTI/EXTI_Example/stm32l1xx_it.c 
  * @author  MCD Application Team
  * @version V1.2.0
  * @date    16-May-2014
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and peripherals
  *          interrupt service routine.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2014 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32l1xx_it.h"

#ifdef USE_STM32L152D_EVAL 
  #include "stm32l152d_eval.h"
#elif defined USE_STM32L152_EVAL 
  #include "stm32l152_eval.h"
#endif 
/** @addtogroup STM32L1xx_StdPeriph_Examples
  * @{
  */

/** @addtogroup EXTI_Example
  * @{
  */ 

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M3 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief  This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval None
  */
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval None
  */
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval None
  */
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
void SVC_Handler(void)
{
}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval None
  */
void DebugMon_Handler(void)
{
}

/**
  * @brief  This function handles PendSV_Handler exception.
  * @param  None
  * @retval None
  */
void PendSV_Handler(void)
{
}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{
}

/******************************************************************************/
/*            STM32L1xx Peripherals Interrupt Handlers                        */
/******************************************************************************/
 
/**
  * @brief  This function handles External line 0 interrupt request.
  * @param  None
  * @retval None
  */
void EXTI0_IRQHandler(void)
{
  if(EXTI_GetITStatus(EXTI_Line0) != RESET)
  {
    /* Toggle LED1 */
    STM_EVAL_LEDToggle(LED1);
    
    /* Clear the EXTI line 0 pending bit */
    EXTI_ClearITPendingBit(EXTI_Line0);
  }
}

/**
  * @brief  This function handles External lines 9 to 5 interrupt request.
  * @param  None
  * @retval None
  */
void EXTI9_5_IRQHandler(void)
{
#if defined USE_STM32L152_EVAL
  if(EXTI_GetITStatus(EXTI_Line8) != RESET)
  {
    /* Toggle LED2 */
    STM_EVAL_LEDToggle(LED2);

    /* Clear the EXTI line 8 pending bit */
    EXTI_ClearITPendingBit(EXTI_Line8);
  }

  if(EXTI_GetITStatus(EXTI_Line9) != RESET)
  {
    /* Toggle LED3 */
    STM_EVAL_LEDToggle(LED3);

    /* Clear the EXTI line 9 pending bit */
    EXTI_ClearITPendingBit(EXTI_Line9);
  }
#elif defined USE_STM32L152D_EVAL
  if(EXTI_GetITStatus(EXTI_Line8) != RESET)
  {
    /* Toggle LED4 */
    STM_EVAL_LEDToggle(LED4);
    
    /* Clear the EXTI line 8 pending bit */
    EXTI_ClearITPendingBit(EXTI_Line8);
  }
#endif 
}  

/**
  * @brief  This function handles External lines 15 to 10 interrupt request.
  * @param  None
  * @retval None
  */
void EXTI15_10_IRQHandler(void)
{
#if defined USE_STM32L152_EVAL
  if(EXTI_GetITStatus(EXTI_Line10) != RESET)
  {
    /* Toggle LED4 */
    STM_EVAL_LEDToggle(LED4);
    
    /* Clear the EXTI line 10 pending bit */
    EXTI_ClearITPendingBit(EXTI_Line10);
  }
#elif defined USE_STM32L152D_EVAL
  if(EXTI_GetITStatus(EXTI_Line13) != RESET)
  {
    /* Toggle LED2 */
    STM_EVAL_LEDToggle(LED2);

    /* Clear the EXTI line 13 pending bit */
    EXTI_ClearITPendingBit(EXTI_Line13);
  }

  if(EXTI_GetITStatus(EXTI_Line11) != RESET)
  {
    /* Toggle LED3 */
    STM_EVAL_LEDToggle(LED3);

    /* Clear the EXTI line 11 pending bit */
    EXTI_ClearITPendingBit(EXTI_Line11);
  }
#endif 
}

/******************************************************************************/
/*                 STM32L1xx Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32l1xx_xx.s).                                            */
/******************************************************************************/

/**
  * @brief  This function handles PPP interrupt request.
  * @param  None
  * @retval None
  */
/*void PPP_IRQHandler(void)
{
}*/

/**
  * @}
  */ 

/**
  * @}
  */ 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
