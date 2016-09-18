################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/dogs0/Documents/my_Program/Xilinx/FreeRTOS-Zedboard/FreeRTOS/FreeRTOS/Source/portable/GCC/ARM_CA9/port.c 

S_UPPER_SRCS += \
C:/Users/dogs0/Documents/my_Program/Xilinx/FreeRTOS-Zedboard/FreeRTOS/FreeRTOS/Source/portable/GCC/ARM_CA9/portASM.S 

OBJS += \
./src/FreeRTOS_Source/portable/GCC/ARM_CA9/port.o \
./src/FreeRTOS_Source/portable/GCC/ARM_CA9/portASM.o 

S_UPPER_DEPS += \
./src/FreeRTOS_Source/portable/GCC/ARM_CA9/portASM.d 

C_DEPS += \
./src/FreeRTOS_Source/portable/GCC/ARM_CA9/port.d 


# Each subdirectory must supply rules for building sources it contributes
src/FreeRTOS_Source/portable/GCC/ARM_CA9/port.o: C:/Users/dogs0/Documents/my_Program/Xilinx/FreeRTOS-Zedboard/FreeRTOS/FreeRTOS/Source/portable/GCC/ARM_CA9/port.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM gcc compiler'
	arm-xilinx-eabi-gcc -Wall -O0 -g3 -I"C:\Users\dogs0\Documents\my_Program\Xilinx\FreeRTOS-Zedboard\FreeRTOS\FreeRTOS\Source\include" -I"C:\Users\dogs0\Documents\my_Program\Xilinx\FreeRTOS-Zedboard\FreeRTOS\FreeRTOS\Source\portable\GCC\ARM_CA9" -I"C:\Users\dogs0\Documents\my_Program\Xilinx\FreeRTOS-Zedboard\FreeRTOS\FreeRTOS\Demo\CORTEX_A9_Zynq_ZC702\RTOSDemo\src" -c -fmessage-length=0 -Wextra -ffunction-sections -fdata-sections -I../../RTOSDemo_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/FreeRTOS_Source/portable/GCC/ARM_CA9/portASM.o: C:/Users/dogs0/Documents/my_Program/Xilinx/FreeRTOS-Zedboard/FreeRTOS/FreeRTOS/Source/portable/GCC/ARM_CA9/portASM.S
	@echo 'Building file: $<'
	@echo 'Invoking: ARM gcc compiler'
	arm-xilinx-eabi-gcc -Wall -O0 -g3 -I"C:\Users\dogs0\Documents\my_Program\Xilinx\FreeRTOS-Zedboard\FreeRTOS\FreeRTOS\Source\include" -I"C:\Users\dogs0\Documents\my_Program\Xilinx\FreeRTOS-Zedboard\FreeRTOS\FreeRTOS\Source\portable\GCC\ARM_CA9" -I"C:\Users\dogs0\Documents\my_Program\Xilinx\FreeRTOS-Zedboard\FreeRTOS\FreeRTOS\Demo\CORTEX_A9_Zynq_ZC702\RTOSDemo\src" -c -fmessage-length=0 -Wextra -ffunction-sections -fdata-sections -I../../RTOSDemo_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


