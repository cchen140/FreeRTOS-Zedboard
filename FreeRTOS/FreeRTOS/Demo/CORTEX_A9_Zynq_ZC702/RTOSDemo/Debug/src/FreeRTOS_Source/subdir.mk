################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/myProgram/Zedboard/FreeRTOS-Zedboard/FreeRTOS/FreeRTOS/Source/croutine.c \
D:/myProgram/Zedboard/FreeRTOS-Zedboard/FreeRTOS/FreeRTOS/Source/event_groups.c \
D:/myProgram/Zedboard/FreeRTOS-Zedboard/FreeRTOS/FreeRTOS/Source/list.c \
D:/myProgram/Zedboard/FreeRTOS-Zedboard/FreeRTOS/FreeRTOS/Source/queue.c \
D:/myProgram/Zedboard/FreeRTOS-Zedboard/FreeRTOS/FreeRTOS/Source/tasks.c \
D:/myProgram/Zedboard/FreeRTOS-Zedboard/FreeRTOS/FreeRTOS/Source/timers.c 

OBJS += \
./src/FreeRTOS_Source/croutine.o \
./src/FreeRTOS_Source/event_groups.o \
./src/FreeRTOS_Source/list.o \
./src/FreeRTOS_Source/queue.o \
./src/FreeRTOS_Source/tasks.o \
./src/FreeRTOS_Source/timers.o 

C_DEPS += \
./src/FreeRTOS_Source/croutine.d \
./src/FreeRTOS_Source/event_groups.d \
./src/FreeRTOS_Source/list.d \
./src/FreeRTOS_Source/queue.d \
./src/FreeRTOS_Source/tasks.d \
./src/FreeRTOS_Source/timers.d 


# Each subdirectory must supply rules for building sources it contributes
src/FreeRTOS_Source/croutine.o: D:/myProgram/Zedboard/FreeRTOS-Zedboard/FreeRTOS/FreeRTOS/Source/croutine.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM gcc compiler'
	arm-xilinx-eabi-gcc -Wall -O0 -g3 -I"D:\myProgram\Zedboard\FreeRTOS-Zedboard\FreeRTOS\FreeRTOS\Source\include" -I"D:\myProgram\Zedboard\FreeRTOS-Zedboard\FreeRTOS\FreeRTOS\Source\portable\GCC\ARM_CA9" -I"D:\myProgram\Zedboard\FreeRTOS-Zedboard\FreeRTOS\FreeRTOS\Demo\CORTEX_A9_Zynq_ZC702\RTOSDemo\src" -c -fmessage-length=0 -Wextra -ffunction-sections -fdata-sections -I../../RTOSDemo_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/FreeRTOS_Source/event_groups.o: D:/myProgram/Zedboard/FreeRTOS-Zedboard/FreeRTOS/FreeRTOS/Source/event_groups.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM gcc compiler'
	arm-xilinx-eabi-gcc -Wall -O0 -g3 -I"D:\myProgram\Zedboard\FreeRTOS-Zedboard\FreeRTOS\FreeRTOS\Source\include" -I"D:\myProgram\Zedboard\FreeRTOS-Zedboard\FreeRTOS\FreeRTOS\Source\portable\GCC\ARM_CA9" -I"D:\myProgram\Zedboard\FreeRTOS-Zedboard\FreeRTOS\FreeRTOS\Demo\CORTEX_A9_Zynq_ZC702\RTOSDemo\src" -c -fmessage-length=0 -Wextra -ffunction-sections -fdata-sections -I../../RTOSDemo_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/FreeRTOS_Source/list.o: D:/myProgram/Zedboard/FreeRTOS-Zedboard/FreeRTOS/FreeRTOS/Source/list.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM gcc compiler'
	arm-xilinx-eabi-gcc -Wall -O0 -g3 -I"D:\myProgram\Zedboard\FreeRTOS-Zedboard\FreeRTOS\FreeRTOS\Source\include" -I"D:\myProgram\Zedboard\FreeRTOS-Zedboard\FreeRTOS\FreeRTOS\Source\portable\GCC\ARM_CA9" -I"D:\myProgram\Zedboard\FreeRTOS-Zedboard\FreeRTOS\FreeRTOS\Demo\CORTEX_A9_Zynq_ZC702\RTOSDemo\src" -c -fmessage-length=0 -Wextra -ffunction-sections -fdata-sections -I../../RTOSDemo_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/FreeRTOS_Source/queue.o: D:/myProgram/Zedboard/FreeRTOS-Zedboard/FreeRTOS/FreeRTOS/Source/queue.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM gcc compiler'
	arm-xilinx-eabi-gcc -Wall -O0 -g3 -I"D:\myProgram\Zedboard\FreeRTOS-Zedboard\FreeRTOS\FreeRTOS\Source\include" -I"D:\myProgram\Zedboard\FreeRTOS-Zedboard\FreeRTOS\FreeRTOS\Source\portable\GCC\ARM_CA9" -I"D:\myProgram\Zedboard\FreeRTOS-Zedboard\FreeRTOS\FreeRTOS\Demo\CORTEX_A9_Zynq_ZC702\RTOSDemo\src" -c -fmessage-length=0 -Wextra -ffunction-sections -fdata-sections -I../../RTOSDemo_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/FreeRTOS_Source/tasks.o: D:/myProgram/Zedboard/FreeRTOS-Zedboard/FreeRTOS/FreeRTOS/Source/tasks.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM gcc compiler'
	arm-xilinx-eabi-gcc -Wall -O0 -g3 -I"D:\myProgram\Zedboard\FreeRTOS-Zedboard\FreeRTOS\FreeRTOS\Source\include" -I"D:\myProgram\Zedboard\FreeRTOS-Zedboard\FreeRTOS\FreeRTOS\Source\portable\GCC\ARM_CA9" -I"D:\myProgram\Zedboard\FreeRTOS-Zedboard\FreeRTOS\FreeRTOS\Demo\CORTEX_A9_Zynq_ZC702\RTOSDemo\src" -c -fmessage-length=0 -Wextra -ffunction-sections -fdata-sections -I../../RTOSDemo_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/FreeRTOS_Source/timers.o: D:/myProgram/Zedboard/FreeRTOS-Zedboard/FreeRTOS/FreeRTOS/Source/timers.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM gcc compiler'
	arm-xilinx-eabi-gcc -Wall -O0 -g3 -I"D:\myProgram\Zedboard\FreeRTOS-Zedboard\FreeRTOS\FreeRTOS\Source\include" -I"D:\myProgram\Zedboard\FreeRTOS-Zedboard\FreeRTOS\FreeRTOS\Source\portable\GCC\ARM_CA9" -I"D:\myProgram\Zedboard\FreeRTOS-Zedboard\FreeRTOS\FreeRTOS\Demo\CORTEX_A9_Zynq_ZC702\RTOSDemo\src" -c -fmessage-length=0 -Wextra -ffunction-sections -fdata-sections -I../../RTOSDemo_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


