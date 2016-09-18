################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/TimingAttack_Demo/Hack/BusyInterval.c \
../src/TimingAttack_Demo/Hack/Composition.c \
../src/TimingAttack_Demo/Hack/Decomp.c \
../src/TimingAttack_Demo/Hack/Interval.c \
../src/TimingAttack_Demo/Hack/Task.c 

OBJS += \
./src/TimingAttack_Demo/Hack/BusyInterval.o \
./src/TimingAttack_Demo/Hack/Composition.o \
./src/TimingAttack_Demo/Hack/Decomp.o \
./src/TimingAttack_Demo/Hack/Interval.o \
./src/TimingAttack_Demo/Hack/Task.o 

C_DEPS += \
./src/TimingAttack_Demo/Hack/BusyInterval.d \
./src/TimingAttack_Demo/Hack/Composition.d \
./src/TimingAttack_Demo/Hack/Decomp.d \
./src/TimingAttack_Demo/Hack/Interval.d \
./src/TimingAttack_Demo/Hack/Task.d 


# Each subdirectory must supply rules for building sources it contributes
src/TimingAttack_Demo/Hack/%.o: ../src/TimingAttack_Demo/Hack/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM gcc compiler'
	arm-xilinx-eabi-gcc -Wall -O0 -g3 -I"C:\Users\dogs0\Documents\my_Program\Xilinx\FreeRTOS-Zedboard\FreeRTOS\FreeRTOS\Source\include" -I"C:\Users\dogs0\Documents\my_Program\Xilinx\FreeRTOS-Zedboard\FreeRTOS\FreeRTOS\Source\portable\GCC\ARM_CA9" -I"C:\Users\dogs0\Documents\my_Program\Xilinx\FreeRTOS-Zedboard\FreeRTOS\FreeRTOS\Demo\CORTEX_A9_Zynq_ZC702\RTOSDemo\src" -c -fmessage-length=0 -Wextra -ffunction-sections -fdata-sections -I../../RTOSDemo_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


