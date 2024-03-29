/**
  @page TIM_Input_Capture TIM Input Capture example 
  
  @verbatim
  ******************** (C) COPYRIGHT 2014 STMicroelectronics *******************
  * @file    TIM/InputCapture/readme.txt 
  * @author  MCD Application Team
  * @version V1.2.0
  * @date    16-May-2014
  * @brief   Description of the TIM Input Capture example.
  ******************************************************************************
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
   @endverbatim

@par Example Description 

This example shows how to use the TIM peripheral to measure the frequency of an 
external signal, The meausred Frequency is desplayed on the LCD Glass.

The TIMxCLK frequency is set to SystemCoreClock (Hz), the Prescaler is 0 so the 
TIM4 counter clock is SystemCoreClock (Hz).

SystemCoreClock is set to 32 MHz for Ultra Low Power Medium-Density and High-Density 
Devices.

TIM4 is configured in Input Capture Mode: the external signal is connected to 
TIM4 Channel2 used as input pin.
To measure the frequency we use the TIM4 CC2 interrupt request,
so in the TIM4_IRQHandler routine, the frequency of the external signal is computed.
The "TIM4Freq" variable contains the external signal frequency:
TIM4Freq = TIM4 counter clock / Capture in Hz,
where the Capture is the difference between two consecutive TIM4 captures.

For Ultra Low Power Medium-Density and High-Density Devices,the minimum frequency 
value to measure is 488 Hz. 


@par Directory contents 

  - TIM/InputCapture/stm32l1xx_conf.h    Library Configuration file
  - TIM/InputCapture/stm32l1xx_it.c      Interrupt handlers
  - TIM/InputCapture/stm32l1xx_it.h      Interrupt handlers header file
  - TIM/InputCapture/main.c              Main program 
  - TIM/InputCapture/system_stm32l1xx.c  STM32L1xx system source file
  
@note The "system_stm32l1xx.c" is generated by an automatic clock configuration 
      system and can be easily customized to your own configuration. 
      To select different clock setup, use the "STM32L1xx_Clock_Configuration_V1.1.0.xls" 
      provided with the AN3309 package available on <a href="http://www.st.com/internet/mcu/family/141.jsp">  ST Microcontrollers </a>


@par Hardware and Software environment

  - This example runs on STM32L1xx Ultra Low Power High-, Medium-Density and Medium-Density Plus Devices.
  
  - This example has been tested with STMicroelectronics STM32L152D-EVAL (STM32L1xx 
    Ultra Low Power High-Density) and STM32L152-EVAL (STM32L1xx Ultra Low 
    Power Medium-Density) evaluation board and can be easily tailored to any 
    other supported device and development board.

  - STM32L152-EVAL Set-up 
    - Connect the external signal to measure to the TIM4 CH2 pin (PB.07).
    - LCD Glass pins is shared with USART3 via jumpers, so make sure that
      Jumper 7 (JP7) is in position 1<-->2.
      Jumper 8 (JP8) is in position 1<-->2.

  - STM32L152D-EVAL Set-up 
    - Connect the external signal to measure to the TIM4 CH2 pin (PB.07).
	  - LCD Glass pins is shared with some IO, so make sure that the LCD Glass is 
      in LCD position


@par How to use it ? 

In order to make the program work, you must do the following:
 - Copy all source files from this example folder to the template folder under
   Project\STM32L1xx_StdPeriph_Templates
 - Open your preferred toolchain
 - If the used device is STM32L1XX_MD choose "STM32L1XX_MD(STM32L1xxxBxx)" workspace
    - Add the following files to the project source list
       - Utilities\STM32_EVAL\STM32L152_EVAL\stm32l152_eval.c     
       - Utilities\STM32_EVAL\STM32L152_EVAL\stm32l152_eval_glass_lcd.c
 - If the used device is STM32L1XX_HD choose "STM32L1XX_HD(STM32L1xxxDxx)" workspace
    - Add the following files to the project source list
       - Utilities\STM32_EVAL\STM32L152D_EVAL\stm32l152d_eval.c   
       - Utilities\STM32_EVAL\STM32L152D_EVAL\stm32l152d_eval_glass_lcd.c
 - Rebuild all files and load your image into target memory
 - Run the example

@note
- Ultra Low Power Medium-density devices: - STM32L151x6xx, STM32L151x8xx, STM32L151xBxx, STM32L152x6xx,
                                            STM32L152x8xx, STM32L152xBxx, STM32L151x6xxA, STM32L151x8xxA,
                                            STM32L151xBxxA, STM32L152x6xxA, STM32L152x8xxA and STM32L152xBxxA
                                          - STM32L100x6xx, STM32L100x8xx and STM32L100xBxx
- Ultra Low Power Medium-density Plus devices: - STM32L151xCxx, STM32L152xCxx and STM32L162xCxx 
                                               - STM32L100xCxx
- Ultra Low Power High-density devices: STM32L151xDxx, STM32L152xDxx and STM32L162xDxx
- Ultra Low Power XL-density devices: STM32L151xExx, STM32L152xExx and STM32L162xExx  
   
 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */


