################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../src/TimingAttack_Demo/v7_pmu/v7_pmu.s 

OBJS += \
./src/TimingAttack_Demo/v7_pmu/v7_pmu.o 


# Each subdirectory must supply rules for building sources it contributes
src/TimingAttack_Demo/v7_pmu/%.o: ../src/TimingAttack_Demo/v7_pmu/%.s
	@echo 'Building file: $<'
	@echo 'Invoking: ARM gcc assembler'
	arm-xilinx-eabi-gcc -c  -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


