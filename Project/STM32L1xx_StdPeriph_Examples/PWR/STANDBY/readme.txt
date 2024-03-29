/**
  @page PWR_STANDBY PWR STANDBY mode example
  
  @verbatim
  ******************** (C) COPYRIGHT 2014 STMicroelectronics *******************
  * @file    PWR/STANDBY/readme.txt 
  * @author  MCD Application Team
  * @version V1.2.0
  * @date    16-May-2014
  * @brief   Description of the PWR STANDBY example.
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

This example shows how to enters the system to STANDBY mode and wake-up from this
mode using: external RESET, RTC Alarm A or WKUP pin 1.

In the associated software, the system clock is set to 32 MHz, an EXTI line
is configured to generate an interrupt on falling edge and the SysTick is programmed
to generate an interrupt each 250 ms. In the SysTick interrupt handler, the LED1 is
toggled, this is used to indicate whether the MCU is in STANDBY or RUN mode.

When a falling edge is detected on the EXTI line an interrupt is generated. In the 
EXTI handler routine the RTC is configured to generate an Alarm event in 5 second
then the system enters STANDBY mode causing the LED1 to stop toggling. 
A rising edge on WKUP pin 1 or an external RESET will wake-up the system from
STANDBY. If within 5 second neither rising edge on WKUP pin 1 nor external RESET
are generated, the RTC Alarm A will wake-up the system. 

After wake-up from STANDBY mode, program execution restarts in the same way as after
a RESET, the LED1 restarts toggling, LED2 is turned on and the RTC configuration
(clock source, enable, prescaler,...) is kept.
As result there is no need to configure the RTC.

Two leds LED1 and LED2 are used to monitor the system state as following:
 - LED1 toggling: system in RUN mode
 - LED1 off / LED2 off: system in STANDBY mode
 - LED2 on: system resumed from STANDBY mode

These Steps are repeated in infinity loop.

@note To measure the current consumption in STANDBY mode, please refer to 
      @subpage PWR_CurrentConsumption example.


@par Directory contents 

  - PWR/STANDBY/stm32l1xx_conf.h     Library Configuration file
  - PWR/STANDBY/stm32l1xx_it.c       Interrupt handlers
  - PWR/STANDBY/stm32l1xx_it.h       Header for stm32l1xx_it.c
  - PWR/STANDBY/main.c               Main program
  - PWR/STANDBY/system_stm32l1xx.c   STM32L1xx system source file
  
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
    - Use LED1, LED2, LED3 and LED4 connected respectively to PD.00, PD.01, PD.04
      and PD.05 pins
    - LCD Glass pins is shared with USART3 via jumpers, so make sure that
         Jumper 7 (JP7) is in position 1<-->2.
         Jumper 8 (JP8) is in position 1<-->2.
    - Use the SEL push-button connected to pin PE.08 (EXTI Line8).
    - Use the KEY push-button connected to WKUP Pin 1 (PA.00) pin.

  - STM32L152D-EVAL Set-up
    - Use LED1, LED2, LED3 and LED4 connected respectively to PD.03, PD.07, PG.14
      and PG.15 pins
    - LCD Glass pins is shared with IOs, so make sure that the LCD Glass is in LCD 
      position
    - Use the SEL push-button connected to pin PG.13 (EXTI Line13).
    - Use the KEY push-button connected to WKUP Pin 1 (PA.00) pin.


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


