################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Interfaces/Patterns/FLASH/flash_interface.c 

OBJS += \
./Drivers/Interfaces/Patterns/FLASH/flash_interface.o 

C_DEPS += \
./Drivers/Interfaces/Patterns/FLASH/flash_interface.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Interfaces/Patterns/FLASH/%.o Drivers/Interfaces/Patterns/FLASH/%.su Drivers/Interfaces/Patterns/FLASH/%.cyclo: ../Drivers/Interfaces/Patterns/FLASH/%.c Drivers/Interfaces/Patterns/FLASH/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -DUSE_FULL_LL_DRIVER -c -I../../Core/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -I"C:/Users/montanab/Inpser/LabOpenBoot/STM32CubeIDE/Drivers/Modules/USART" -I"C:/Users/montanab/Inpser/LabOpenBoot/STM32CubeIDE/Drivers/Modules/Mem" -I"C:/Users/montanab/Inpser/LabOpenBoot/STM32CubeIDE/Drivers/Interfaces/Patterns" -I"C:/Users/montanab/Inpser/LabOpenBoot/STM32CubeIDE/Drivers/Interfaces/Patterns/COMMON" -I"C:/Users/montanab/Inpser/LabOpenBoot/STM32CubeIDE/Drivers/Interfaces/Patterns/FLASH" -I"C:/Users/montanab/Inpser/LabOpenBoot/STM32CubeIDE/Drivers/Interfaces/Patterns/IWDG" -I"C:/Users/montanab/Inpser/LabOpenBoot/STM32CubeIDE/Drivers/Interfaces/Patterns/OPTION BYTES" -I"C:/Users/montanab/Inpser/LabOpenBoot/STM32CubeIDE/Drivers/Interfaces/Patterns/USART" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-Interfaces-2f-Patterns-2f-FLASH

clean-Drivers-2f-Interfaces-2f-Patterns-2f-FLASH:
	-$(RM) ./Drivers/Interfaces/Patterns/FLASH/flash_interface.cyclo ./Drivers/Interfaces/Patterns/FLASH/flash_interface.d ./Drivers/Interfaces/Patterns/FLASH/flash_interface.o ./Drivers/Interfaces/Patterns/FLASH/flash_interface.su

.PHONY: clean-Drivers-2f-Interfaces-2f-Patterns-2f-FLASH

