################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
LD_SRCS += \
../src/lscript.ld 

C_SRCS += \
../src/FreeRTOS_tick_config.c \
../src/main.c \
../src/platform.c \
../src/printf-stdarg.c 

S_UPPER_SRCS += \
../src/FreeRTOS_asm_vectors.S 

OBJS += \
./src/FreeRTOS_asm_vectors.o \
./src/FreeRTOS_tick_config.o \
./src/main.o \
./src/platform.o \
./src/printf-stdarg.o 

S_UPPER_DEPS += \
./src/FreeRTOS_asm_vectors.d 

C_DEPS += \
./src/FreeRTOS_tick_config.d \
./src/main.d \
./src/platform.d \
./src/printf-stdarg.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.S
	@echo 'Building file: $<'
	@echo 'Invoking: ARM gcc compiler'
	arm-xilinx-eabi-gcc -Wall -O0 -g3 -I"C:\Users\dogs0\Documents\my_Program\Xilinx\FreeRTOS-Zedboard\FreeRTOS\FreeRTOS\Source\include" -I"C:\Users\dogs0\Documents\my_Program\Xilinx\FreeRTOS-Zedboard\FreeRTOS\FreeRTOS\Source\portable\GCC\ARM_CA9" -I"C:\Users\dogs0\Documents\my_Program\Xilinx\FreeRTOS-Zedboard\FreeRTOS\FreeRTOS\Demo\CORTEX_A9_Zynq_ZC702\RTOSDemo\src" -c -fmessage-length=0 -Wextra -ffunction-sections -fdata-sections -I../../RTOSDemo_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM gcc compiler'
	arm-xilinx-eabi-gcc -Wall -O0 -g3 -I"C:\Users\dogs0\Documents\my_Program\Xilinx\FreeRTOS-Zedboard\FreeRTOS\FreeRTOS\Source\include" -I"C:\Users\dogs0\Documents\my_Program\Xilinx\FreeRTOS-Zedboard\FreeRTOS\FreeRTOS\Source\portable\GCC\ARM_CA9" -I"C:\Users\dogs0\Documents\my_Program\Xilinx\FreeRTOS-Zedboard\FreeRTOS\FreeRTOS\Demo\CORTEX_A9_Zynq_ZC702\RTOSDemo\src" -c -fmessage-length=0 -Wextra -ffunction-sections -fdata-sections -I../../RTOSDemo_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


