/**
  @page RCC_Example RCC example
  
  @verbatim
  ******************** (C) COPYRIGHT 2014 STMicroelectronics *******************
  * @file    RCC/RCC_Example/readme.txt 
  * @author  MCD Application Team
  * @version V1.2.0
  * @date    16-May-2014
  * @brief   Description of the RCC example.
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

This example shows how to use, for debug purpose, the RCC_GetClocksFreq function 
to retrieve the current status and frequencies of different on chip clocks. 
You can see the RCC_ClockFreq structure content, which hold the frequencies of 
different on chip clocks, using your toolchain debugger.

This example handles also the High Speed External clock (HSE) failure detection:
when the HSE clock disappears (broken or disconnected external Quartz); HSE, PLL
are disabled (but no change on PLL config), MSI selected as system clock source
and an interrupt (NMI) is generated. In the NMI ISR, the HSE, HSE ready interrupt
are enabled and once HSE clock recover, the HSERDY interrupt is generated and in
the RCC ISR routine the system clock is reconfigured to its previous state (before
HSE clock failure). You can monitor the HSE clock on the MCO pin (PA.08).

Four LEDs are toggled with a timing defined by the Delay function.

@note To adjust the External High Speed oscillator (HSE) Startup Timeout value,
use HSESTARTUP_TIMEOUT variable defined in the stm32l1xx.h file.


@par Directory contents 

  - RCC/RCC_Example/stm32l1xx_conf.h    Library Configuration file
  - RCC/RCC_Example/stm32l1xx_it.c      Interrupt handlers
  - RCC/RCC_Example/stm32l1xx_it.h      Interrupt handlers header file
  - RCC/RCC_Example/main.c              Main program
  - RCC/RCC_Example/system_stm32l1xx.c  STM32L1xx system source file
  
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
    - Use LD1, LD2, LD3 and LD4 led connected respectively to PD.00 , PD.01, PD.02
      and PC.12 pins.
    - Make Sure That The Jumpers JP18 and JP19 is closed.

  - STM32L152-EVAL Set-up
    - Use LD1, LD2, LD3 and LD4 led connected respectively to PD.03, PD.07, PG.14
      and PG.15 pins.


@par How to use it ? 

In order to make the program work, you must do the following:
 - Copy all source files from this example folder to the template folder under
   Project\STM32L1xx_StdPeriph_Templates
 - Open your preferred toolchain
 - If the used device is STM32L1XX_MD choose "STM32L1XX_MD(STM32L1xxxBxx)" workspace
    - Add the following files to the project source list
       - Utilities\STM32_EVAL\STM32L152_EVAL\stm32l152_eval.c
 - If the used device is STM32L1XX_HD choose "STM32L1XX_HD(STM32L1xxxDxx)" workspace
    - Add the following files to the project source list
       - Utilities\STM32_EVAL\STM32L152D_EVAL\stm32l152d_eval.c 
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


