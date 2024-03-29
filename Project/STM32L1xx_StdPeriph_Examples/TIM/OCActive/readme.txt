/**
  @page TIM_OCActive TIM OC Active example
  
  @verbatim
  ******************** (C) COPYRIGHT 2014 STMicroelectronics *******************
  * @file    TIM/OCActive/readme.txt 
  * @author  MCD Application Team
  * @version V1.2.0
  * @date    16-May-2014
  * @brief   Description of the TIM OC Active example.
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

This example shows how to configure the TIM peripheral to generate four different 
signals with four different delays.

The TIM3CLK frequency is set to SystemCoreClock , and the objective is
to get TIM3 counter clock at 1 KHz so the Prescaler is computed as following:
   - Prescaler = (TIM3CLK / TIM3 counter clock) - 1
SystemCoreClock is set to 32 MHz for Ultra Low Power Medium-Density and High-Density
Devices.

The TIM3 CCR1 register value is equal to 1000:
TIM3_CC1 delay = CCR1_Val/TIM3 counter clock  = 1000 ms
so the PA.06  is reset after a delay equal to 1000 ms.

The TIM3 CCR2 register value is equal to 500:
TIM3_CC2 delay = CCR2_Val/TIM3 counter clock = 500 ms
so the PA.07  is reset after a delay equal to 500 ms.

The TIM3 CCR3 register value is equal to 250:
TIM3_CC3 delay = CCR3_Val/TIM3 counter clock = 250 ms
so the PB.00  is reset after a delay equal to 250 ms.

The TIM3 CCR4 register value is equal to 125:
TIM3_CC4 delay = CCR4_Val/TIM2 counter clock = 125 ms
so the PBD.01  is reset after a delay equal to 125 ms.

The delay correspond to the time difference between PC.00 and 
TIM3_CHx signal rising edges in case of STM32L152-EVAL.


@par Directory contents 

  - TIM/OCActive/stm32l1xx_conf.h    Library Configuration file
  - TIM/OCActive/stm32l1xx_it.c      Interrupt handlers
  - TIM/OCActive/stm32l1xx_it.h      Interrupt handlers header file
  - TIM/OCActive/main.c              Main program
  - TIM/OCActive/system_stm32l1xx.c  STM32L1xx system source file
  
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

  - STM32L152-EVAL and STM32L152D-EVAL Set-up 
    - Connect the following pins to an oscilloscope to monitor the different 
      waveforms:
        - PC.00
        - TIM3 CH1 (PA.06) 
        - TIM3 CH2 (PA.07)
        - TIM3 CH1 (PB.00) 
        - TIM3 CH2 (PB.01) 

@par How to use it ? 

In order to make the program work, you must do the following:
 - Copy all source files from this example folder to the template folder under
   Project\STM32L1xx_StdPeriph_Templates
 - Open your preferred toolchain
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


