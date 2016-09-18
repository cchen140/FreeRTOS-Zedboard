################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/TimingAttack_Demo/BusyInterval/BusyInterval.c 

OBJS += \
./src/TimingAttack_Demo/BusyInterval/BusyInterval.o 

C_DEPS += \
./src/TimingAttack_Demo/BusyInterval/BusyInterval.d 


# Each subdirectory must supply rules for building sources it contributes
src/TimingAttack_Demo/BusyInterval/%.o: ../src/TimingAttack_Demo/BusyInterval/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM gcc compiler'
	arm-xilinx-eabi-gcc -Wall -O0 -g3 -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Source\include" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Source\portable\GCC\ARM_CA9" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\CORTEX_A9_Zynq_ZC702\RTOSDemo\src" -c -fmessage-length=0 -Wextra -ffunction-sections -fdata-sections -I../../RTOSDemo_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


