################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/TimingAttack_Demo/crypto_aes/TI_aes_128_encr_only.c 

OBJS += \
./src/TimingAttack_Demo/crypto_aes/TI_aes_128_encr_only.o 

C_DEPS += \
./src/TimingAttack_Demo/crypto_aes/TI_aes_128_encr_only.d 


# Each subdirectory must supply rules for building sources it contributes
src/TimingAttack_Demo/crypto_aes/%.o: ../src/TimingAttack_Demo/crypto_aes/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM gcc compiler'
	arm-xilinx-eabi-gcc -Wall -O0 -g3 -I"C:\Users\dogs0\Documents\my_Program\Xilinx\FreeRTOS-Zedboard\FreeRTOS\FreeRTOS\Source\include" -I"C:\Users\dogs0\Documents\my_Program\Xilinx\FreeRTOS-Zedboard\FreeRTOS\FreeRTOS\Source\portable\GCC\ARM_CA9" -I"C:\Users\dogs0\Documents\my_Program\Xilinx\FreeRTOS-Zedboard\FreeRTOS\FreeRTOS\Demo\CORTEX_A9_Zynq_ZC702\RTOSDemo\src" -c -fmessage-length=0 -Wextra -ffunction-sections -fdata-sections -I../../RTOSDemo_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


