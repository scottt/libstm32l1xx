/**
  ******************************************************************************
  * @file    RTC/Calendar/stm32l1xx_it.c 
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
#include "main.h"
#ifdef USE_STM32L152D_EVAL 
  #include "stm32l152d_eval.h"
#elif defined USE_STM32L152_EVAL 
  #include "stm32l152_eval.h"
#endif 

/** @addtogroup STM32L1xx_StdPeriph_Examples
  * @{
  */

/** @addtogroup RTC_Calendar
  * @{
  */ 

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
extern __IO uint32_t DisplayTimeDate;

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
 
/******************************************************************************/
/*                 STM32F2xx Peripherals Interrupt Handlers                   */
/******************************************************************************/
#ifdef USE_STM32L152D_EVAL 

/**
  * @brief  This function handles External lines 15 to 10 interrupt request.
  * @param  None
  * @retval None
  */

void EXTI15_10_IRQHandler(void)
{
  if(EXTI_GetITStatus(UP_BUTTON_EXTI_LINE) != RESET)
  {  
    /* Display the current alarm on the Hyperterminal */
    RTC_AlarmShow();
     
    /* Clear the UP Button EXTI line pending bit */
    EXTI_ClearITPendingBit(UP_BUTTON_EXTI_LINE);
  } 
  
  if(EXTI_GetITStatus(SEL_BUTTON_EXTI_LINE) != RESET)
  {
    /* Set the new RTC configuration */
     RTC_TimeRegulate();

    /* Clear the SEL Button EXTI line pending bit */
    EXTI_ClearITPendingBit(SEL_BUTTON_EXTI_LINE);
  } 
}

#elif defined USE_STM32L152_EVAL 

/**
  * @brief  This function handles External lines 9 to 5 interrupt request.
  * @param  None
  * @retval None
  */
void EXTI9_5_IRQHandler(void)
{
  if(EXTI_GetITStatus(UP_BUTTON_EXTI_LINE) != RESET)
  {  
    /* Display the current alarm on the Hyperterminal */
    RTC_AlarmShow();
     
    /* Clear the UP Button EXTI line pending bit */
    EXTI_ClearITPendingBit(UP_BUTTON_EXTI_LINE);
  } 
  
  if(EXTI_GetITStatus(SEL_BUTTON_EXTI_LINE) != RESET)
  {
    /* Set the new RTC configuration */
     RTC_TimeRegulate();

    /* Clear the SEL Button EXTI line pending bit */
    EXTI_ClearITPendingBit(SEL_BUTTON_EXTI_LINE);
  } 
}
#endif

/**
  * @brief  This function handles External line 0 interrupt request.
  * @param  None
  * @retval None
  */
void EXTI0_IRQHandler(void)
{
  if(EXTI_GetITStatus(KEY_BUTTON_EXTI_LINE) != RESET)
  {  
    /* Display the current time on the Hyperterminal */
    RTC_TimeShow();
     
    /* Clear the Key Button EXTI line pending bit */
    EXTI_ClearITPendingBit(KEY_BUTTON_EXTI_LINE);
  }
}

/**
  * @brief  This function handles RTC Alarms interrupt request.
  * @param  None
  * @retval None
  */
void RTC_Alarm_IRQHandler(void)
{
  if(RTC_GetITStatus(RTC_IT_ALRA) != RESET)
  {
    STM_EVAL_LEDToggle(LED1);
    RTC_ClearITPendingBit(RTC_IT_ALRA);
    EXTI_ClearITPendingBit(EXTI_Line17);
  } 
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
