################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/myProgram/Zedboard/FreeRTOS-Zedboard/FreeRTOS/FreeRTOS/Source/portable/MemMang/heap_4.c 

OBJS += \
./src/FreeRTOS_Source/portable/MemMang/heap_4.o 

C_DEPS += \
./src/FreeRTOS_Source/portable/MemMang/heap_4.d 


# Each subdirectory must supply rules for building sources it contributes
src/FreeRTOS_Source/portable/MemMang/heap_4.o: D:/myProgram/Zedboard/FreeRTOS-Zedboard/FreeRTOS/FreeRTOS/Source/portable/MemMang/heap_4.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM gcc compiler'
	arm-xilinx-eabi-gcc -Wall -O0 -g3 -I"D:\myProgram\Zedboard\FreeRTOS-Zedboard\FreeRTOS\FreeRTOS\Source\include" -I"D:\myProgram\Zedboard\FreeRTOS-Zedboard\FreeRTOS\FreeRTOS\Source\portable\GCC\ARM_CA9" -I"D:\myProgram\Zedboard\FreeRTOS-Zedboard\FreeRTOS\FreeRTOS\Demo\CORTEX_A9_Zynq_ZC702\RTOSDemo\src" -c -fmessage-length=0 -Wextra -ffunction-sections -fdata-sections -I../../RTOSDemo_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


