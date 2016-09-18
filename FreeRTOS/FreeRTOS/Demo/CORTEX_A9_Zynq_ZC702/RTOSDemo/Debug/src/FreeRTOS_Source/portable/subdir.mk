################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/CY/Documents/my_program/xilinx/SecureRTOS/Repo/FreeRTOS/Source/portable/heap_1.c 

OBJS += \
./src/FreeRTOS_Source/portable/heap_1.o 

C_DEPS += \
./src/FreeRTOS_Source/portable/heap_1.d 


# Each subdirectory must supply rules for building sources it contributes
src/FreeRTOS_Source/portable/heap_1.o: C:/Users/CY/Documents/my_program/xilinx/SecureRTOS/Repo/FreeRTOS/Source/portable/heap_1.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM gcc compiler'
	arm-xilinx-eabi-gcc -Wall -O0 -g3 -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\CORTEX_A9_Zynq_ZC702\RTOSDemo\src\lwIP_Demo\lwIP_port\include" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\CORTEX_A9_Zynq_ZC702\RTOSDemo\src\lwIP_Demo\lwIP_port\netif" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Source\include" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Source\portable\GCC\ARM_CA9" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\Common\ethernet\lwip-1.4.0\src\include\ipv4" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\Common\ethernet\lwip-1.4.0\src\include" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\CORTEX_A9_Zynq_ZC702\RTOSDemo\src\Full_Demo" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS-Plus\Source\FreeRTOS-Plus-CLI" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\Common\include" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\CORTEX_A9_Zynq_ZC702\RTOSDemo\src" -c -fmessage-length=0 -Wextra -ffunction-sections -fdata-sections -I../../RTOSDemo_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


