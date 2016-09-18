################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/MyProgram/v7_pmu/subdir.mk
-include src/MyProgram/crypto_aes/subdir.mk
-include src/MyProgram/LogUtility/subdir.mk
-include src/MyProgram/subdir.mk
-include src/FreeRTOS_Source/portable/MemMang/subdir.mk
-include src/FreeRTOS_Source/portable/GCC/ARM_CA9/subdir.mk
-include src/FreeRTOS_Source/subdir.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
ELFSIZE += \
RTOSDemo.elf.size \


# All Target
all: RTOSDemo.elf secondary-outputs

# Tool invocations
RTOSDemo.elf: $(OBJS) ../src/lscript.ld $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: ARM gcc linker'
	arm-xilinx-eabi-gcc -Xlinker --gc-sections -Wl,-T -Wl,../src/lscript.ld -L../../RTOSDemo_bsp/ps7_cortexa9_0/lib -o "RTOSDemo.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

RTOSDemo.elf.size: RTOSDemo.elf
	@echo 'Invoking: ARM Print Size'
	arm-xilinx-eabi-size RTOSDemo.elf  |tee "RTOSDemo.elf.size"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(S_UPPER_DEPS)$(C_DEPS)$(ELFSIZE) RTOSDemo.elf
	-@echo ' '

secondary-outputs: $(ELFSIZE)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
