# grep for STM32L1XX_MDP, which is for STM32L1xxCxx
STM32_MCU_CFLAGS := -DSTM32L1XX_MDP
LINKER_SCRIPT := Project/STM32L1xx_StdPeriph_Templates/TrueSTUDIO/STM32L1XX_MDP(STM32L1xxxCxx)/STM32L152ZC_FLASH.ld
STARTUP_ASM_SRC := ./Libraries/CMSIS/Device/ST/STM32L1xx/Source/Templates/TrueSTUDIO/startup_stm32l1xx_mdp.s

CFLAGS := -g3 -Os -mcpu=cortex-m3 -mthumb -fno-common

CFLAGS += $(STM32_MCU_CFLAGS) \
	-DUSE_STDPERIPH_DRIVER=1 \
	-I. \
	-ILibraries/CMSIS/RTOS \
	-ILibraries/CMSIS/Device/ST/STM32L1xx/Include \
	-ILibraries/CMSIS/Include \
	-ILibraries/STM32L1xx_StdPeriph_Driver/inc \
	'-T$(LINKER_SCRIPT)'

LIB_SRCS := $(wildcard Libraries/STM32L1xx_StdPeriph_Driver/src/*.c)
LIB_OBJS := $(LIB_SRCS:.c=.o)

PROJ_SRCS := $(wildcard *.c)
PROJ_OBJS := $(PROJ_SRCS:.c=.o) $(STARTUP_ASM_SRC:.s=.o)
OBJS := $(PROJ_OBJS) $(LIB_OBJS)

DERIVED_FILES := $(OBJS) libstm32l1xx.a

.PHONY: all clean install
all: libstm32l1xx.a
libstm32l1xx.a: $(LIB_OBJS)
	$(AR) rcs $@ $(LIB_OBJS)


clean:
	rm -f $(DERIVED_FILES)

install:
	echo FIXME: install public libstmXX.a, public headers, library source and utilities
