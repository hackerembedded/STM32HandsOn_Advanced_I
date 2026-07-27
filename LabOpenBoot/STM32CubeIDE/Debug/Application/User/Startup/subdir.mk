################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Application/User/Startup/startup_stm32f401retx.s 

OBJS += \
./Application/User/Startup/startup_stm32f401retx.o 

S_DEPS += \
./Application/User/Startup/startup_stm32f401retx.d 


# Each subdirectory must supply rules for building sources it contributes
Application/User/Startup/%.o: ../Application/User/Startup/%.s Application/User/Startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -I"C:/Users/montanab/Inpser/LabOpenBoot/STM32CubeIDE/Drivers/Modules/USART" -I"C:/Users/montanab/Inpser/LabOpenBoot/STM32CubeIDE/Drivers/Modules/Mem" -I"C:/Users/montanab/Inpser/LabOpenBoot/STM32CubeIDE/Drivers/Interfaces/Patterns" -I"C:/Users/montanab/Inpser/LabOpenBoot/STM32CubeIDE/Drivers/Interfaces/Patterns/COMMON" -I"C:/Users/montanab/Inpser/LabOpenBoot/STM32CubeIDE/Drivers/Interfaces/Patterns/FLASH" -I"C:/Users/montanab/Inpser/LabOpenBoot/STM32CubeIDE/Drivers/Interfaces/Patterns/IWDG" -I"C:/Users/montanab/Inpser/LabOpenBoot/STM32CubeIDE/Drivers/Interfaces/Patterns/OPTION BYTES" -I"C:/Users/montanab/Inpser/LabOpenBoot/STM32CubeIDE/Drivers/Interfaces/Patterns/USART" -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-Application-2f-User-2f-Startup

clean-Application-2f-User-2f-Startup:
	-$(RM) ./Application/User/Startup/startup_stm32f401retx.d ./Application/User/Startup/startup_stm32f401retx.o

.PHONY: clean-Application-2f-User-2f-Startup

