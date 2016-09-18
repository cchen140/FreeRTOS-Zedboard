################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/CY/Documents/my_program/xilinx/SecureRTOS/Repo/FreeRTOS/Demo/Common/ethernet/lwip-1.4.0/src/core/def.c \
C:/Users/CY/Documents/my_program/xilinx/SecureRTOS/Repo/FreeRTOS/Demo/Common/ethernet/lwip-1.4.0/src/core/dhcp.c \
C:/Users/CY/Documents/my_program/xilinx/SecureRTOS/Repo/FreeRTOS/Demo/Common/ethernet/lwip-1.4.0/src/core/dns.c \
C:/Users/CY/Documents/my_program/xilinx/SecureRTOS/Repo/FreeRTOS/Demo/Common/ethernet/lwip-1.4.0/src/core/init.c \
C:/Users/CY/Documents/my_program/xilinx/SecureRTOS/Repo/FreeRTOS/Demo/Common/ethernet/lwip-1.4.0/src/core/lwip_timers.c \
C:/Users/CY/Documents/my_program/xilinx/SecureRTOS/Repo/FreeRTOS/Demo/Common/ethernet/lwip-1.4.0/src/core/mem.c \
C:/Users/CY/Documents/my_program/xilinx/SecureRTOS/Repo/FreeRTOS/Demo/Common/ethernet/lwip-1.4.0/src/core/memp.c \
C:/Users/CY/Documents/my_program/xilinx/SecureRTOS/Repo/FreeRTOS/Demo/Common/ethernet/lwip-1.4.0/src/core/netif.c \
C:/Users/CY/Documents/my_program/xilinx/SecureRTOS/Repo/FreeRTOS/Demo/Common/ethernet/lwip-1.4.0/src/core/pbuf.c \
C:/Users/CY/Documents/my_program/xilinx/SecureRTOS/Repo/FreeRTOS/Demo/Common/ethernet/lwip-1.4.0/src/core/raw.c \
C:/Users/CY/Documents/my_program/xilinx/SecureRTOS/Repo/FreeRTOS/Demo/Common/ethernet/lwip-1.4.0/src/core/stats.c \
C:/Users/CY/Documents/my_program/xilinx/SecureRTOS/Repo/FreeRTOS/Demo/Common/ethernet/lwip-1.4.0/src/core/sys.c \
C:/Users/CY/Documents/my_program/xilinx/SecureRTOS/Repo/FreeRTOS/Demo/Common/ethernet/lwip-1.4.0/src/core/tcp.c \
C:/Users/CY/Documents/my_program/xilinx/SecureRTOS/Repo/FreeRTOS/Demo/Common/ethernet/lwip-1.4.0/src/core/tcp_in.c \
C:/Users/CY/Documents/my_program/xilinx/SecureRTOS/Repo/FreeRTOS/Demo/Common/ethernet/lwip-1.4.0/src/core/tcp_out.c \
C:/Users/CY/Documents/my_program/xilinx/SecureRTOS/Repo/FreeRTOS/Demo/Common/ethernet/lwip-1.4.0/src/core/udp.c 

OBJS += \
./src/lwIP_Demo/lwip-1.4.0/src/core/def.o \
./src/lwIP_Demo/lwip-1.4.0/src/core/dhcp.o \
./src/lwIP_Demo/lwip-1.4.0/src/core/dns.o \
./src/lwIP_Demo/lwip-1.4.0/src/core/init.o \
./src/lwIP_Demo/lwip-1.4.0/src/core/lwip_timers.o \
./src/lwIP_Demo/lwip-1.4.0/src/core/mem.o \
./src/lwIP_Demo/lwip-1.4.0/src/core/memp.o \
./src/lwIP_Demo/lwip-1.4.0/src/core/netif.o \
./src/lwIP_Demo/lwip-1.4.0/src/core/pbuf.o \
./src/lwIP_Demo/lwip-1.4.0/src/core/raw.o \
./src/lwIP_Demo/lwip-1.4.0/src/core/stats.o \
./src/lwIP_Demo/lwip-1.4.0/src/core/sys.o \
./src/lwIP_Demo/lwip-1.4.0/src/core/tcp.o \
./src/lwIP_Demo/lwip-1.4.0/src/core/tcp_in.o \
./src/lwIP_Demo/lwip-1.4.0/src/core/tcp_out.o \
./src/lwIP_Demo/lwip-1.4.0/src/core/udp.o 

C_DEPS += \
./src/lwIP_Demo/lwip-1.4.0/src/core/def.d \
./src/lwIP_Demo/lwip-1.4.0/src/core/dhcp.d \
./src/lwIP_Demo/lwip-1.4.0/src/core/dns.d \
./src/lwIP_Demo/lwip-1.4.0/src/core/init.d \
./src/lwIP_Demo/lwip-1.4.0/src/core/lwip_timers.d \
./src/lwIP_Demo/lwip-1.4.0/src/core/mem.d \
./src/lwIP_Demo/lwip-1.4.0/src/core/memp.d \
./src/lwIP_Demo/lwip-1.4.0/src/core/netif.d \
./src/lwIP_Demo/lwip-1.4.0/src/core/pbuf.d \
./src/lwIP_Demo/lwip-1.4.0/src/core/raw.d \
./src/lwIP_Demo/lwip-1.4.0/src/core/stats.d \
./src/lwIP_Demo/lwip-1.4.0/src/core/sys.d \
./src/lwIP_Demo/lwip-1.4.0/src/core/tcp.d \
./src/lwIP_Demo/lwip-1.4.0/src/core/tcp_in.d \
./src/lwIP_Demo/lwip-1.4.0/src/core/tcp_out.d \
./src/lwIP_Demo/lwip-1.4.0/src/core/udp.d 


# Each subdirectory must supply rules for building sources it contributes
src/lwIP_Demo/lwip-1.4.0/src/core/def.o: C:/Users/CY/Documents/my_program/xilinx/SecureRTOS/Repo/FreeRTOS/Demo/Common/ethernet/lwip-1.4.0/src/core/def.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM gcc compiler'
	arm-xilinx-eabi-gcc -Wall -O0 -g3 -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\CORTEX_A9_Zynq_ZC702\RTOSDemo\src\lwIP_Demo\lwIP_port\include" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\CORTEX_A9_Zynq_ZC702\RTOSDemo\src\lwIP_Demo\lwIP_port\netif" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Source\include" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Source\portable\GCC\ARM_CA9" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\Common\ethernet\lwip-1.4.0\src\include\ipv4" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\Common\ethernet\lwip-1.4.0\src\include" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\CORTEX_A9_Zynq_ZC702\RTOSDemo\src\Full_Demo" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS-Plus\Source\FreeRTOS-Plus-CLI" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\Common\include" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\CORTEX_A9_Zynq_ZC702\RTOSDemo\src" -c -fmessage-length=0 -Wextra -ffunction-sections -fdata-sections -I../../RTOSDemo_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/lwIP_Demo/lwip-1.4.0/src/core/dhcp.o: C:/Users/CY/Documents/my_program/xilinx/SecureRTOS/Repo/FreeRTOS/Demo/Common/ethernet/lwip-1.4.0/src/core/dhcp.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM gcc compiler'
	arm-xilinx-eabi-gcc -Wall -O0 -g3 -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\CORTEX_A9_Zynq_ZC702\RTOSDemo\src\lwIP_Demo\lwIP_port\include" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\CORTEX_A9_Zynq_ZC702\RTOSDemo\src\lwIP_Demo\lwIP_port\netif" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Source\include" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Source\portable\GCC\ARM_CA9" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\Common\ethernet\lwip-1.4.0\src\include\ipv4" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\Common\ethernet\lwip-1.4.0\src\include" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\CORTEX_A9_Zynq_ZC702\RTOSDemo\src\Full_Demo" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS-Plus\Source\FreeRTOS-Plus-CLI" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\Common\include" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\CORTEX_A9_Zynq_ZC702\RTOSDemo\src" -c -fmessage-length=0 -Wextra -ffunction-sections -fdata-sections -I../../RTOSDemo_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/lwIP_Demo/lwip-1.4.0/src/core/dns.o: C:/Users/CY/Documents/my_program/xilinx/SecureRTOS/Repo/FreeRTOS/Demo/Common/ethernet/lwip-1.4.0/src/core/dns.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM gcc compiler'
	arm-xilinx-eabi-gcc -Wall -O0 -g3 -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\CORTEX_A9_Zynq_ZC702\RTOSDemo\src\lwIP_Demo\lwIP_port\include" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\CORTEX_A9_Zynq_ZC702\RTOSDemo\src\lwIP_Demo\lwIP_port\netif" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Source\include" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Source\portable\GCC\ARM_CA9" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\Common\ethernet\lwip-1.4.0\src\include\ipv4" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\Common\ethernet\lwip-1.4.0\src\include" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\CORTEX_A9_Zynq_ZC702\RTOSDemo\src\Full_Demo" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS-Plus\Source\FreeRTOS-Plus-CLI" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\Common\include" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\CORTEX_A9_Zynq_ZC702\RTOSDemo\src" -c -fmessage-length=0 -Wextra -ffunction-sections -fdata-sections -I../../RTOSDemo_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/lwIP_Demo/lwip-1.4.0/src/core/init.o: C:/Users/CY/Documents/my_program/xilinx/SecureRTOS/Repo/FreeRTOS/Demo/Common/ethernet/lwip-1.4.0/src/core/init.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM gcc compiler'
	arm-xilinx-eabi-gcc -Wall -O0 -g3 -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\CORTEX_A9_Zynq_ZC702\RTOSDemo\src\lwIP_Demo\lwIP_port\include" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\CORTEX_A9_Zynq_ZC702\RTOSDemo\src\lwIP_Demo\lwIP_port\netif" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Source\include" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Source\portable\GCC\ARM_CA9" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\Common\ethernet\lwip-1.4.0\src\include\ipv4" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\Common\ethernet\lwip-1.4.0\src\include" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\CORTEX_A9_Zynq_ZC702\RTOSDemo\src\Full_Demo" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS-Plus\Source\FreeRTOS-Plus-CLI" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\Common\include" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\CORTEX_A9_Zynq_ZC702\RTOSDemo\src" -c -fmessage-length=0 -Wextra -ffunction-sections -fdata-sections -I../../RTOSDemo_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/lwIP_Demo/lwip-1.4.0/src/core/lwip_timers.o: C:/Users/CY/Documents/my_program/xilinx/SecureRTOS/Repo/FreeRTOS/Demo/Common/ethernet/lwip-1.4.0/src/core/lwip_timers.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM gcc compiler'
	arm-xilinx-eabi-gcc -Wall -O0 -g3 -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\CORTEX_A9_Zynq_ZC702\RTOSDemo\src\lwIP_Demo\lwIP_port\include" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\CORTEX_A9_Zynq_ZC702\RTOSDemo\src\lwIP_Demo\lwIP_port\netif" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Source\include" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Source\portable\GCC\ARM_CA9" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\Common\ethernet\lwip-1.4.0\src\include\ipv4" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\Common\ethernet\lwip-1.4.0\src\include" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\CORTEX_A9_Zynq_ZC702\RTOSDemo\src\Full_Demo" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS-Plus\Source\FreeRTOS-Plus-CLI" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\Common\include" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\CORTEX_A9_Zynq_ZC702\RTOSDemo\src" -c -fmessage-length=0 -Wextra -ffunction-sections -fdata-sections -I../../RTOSDemo_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/lwIP_Demo/lwip-1.4.0/src/core/mem.o: C:/Users/CY/Documents/my_program/xilinx/SecureRTOS/Repo/FreeRTOS/Demo/Common/ethernet/lwip-1.4.0/src/core/mem.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM gcc compiler'
	arm-xilinx-eabi-gcc -Wall -O0 -g3 -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\CORTEX_A9_Zynq_ZC702\RTOSDemo\src\lwIP_Demo\lwIP_port\include" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\CORTEX_A9_Zynq_ZC702\RTOSDemo\src\lwIP_Demo\lwIP_port\netif" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Source\include" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Source\portable\GCC\ARM_CA9" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\Common\ethernet\lwip-1.4.0\src\include\ipv4" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\Common\ethernet\lwip-1.4.0\src\include" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\CORTEX_A9_Zynq_ZC702\RTOSDemo\src\Full_Demo" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS-Plus\Source\FreeRTOS-Plus-CLI" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\Common\include" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\CORTEX_A9_Zynq_ZC702\RTOSDemo\src" -c -fmessage-length=0 -Wextra -ffunction-sections -fdata-sections -I../../RTOSDemo_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/lwIP_Demo/lwip-1.4.0/src/core/memp.o: C:/Users/CY/Documents/my_program/xilinx/SecureRTOS/Repo/FreeRTOS/Demo/Common/ethernet/lwip-1.4.0/src/core/memp.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM gcc compiler'
	arm-xilinx-eabi-gcc -Wall -O0 -g3 -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\CORTEX_A9_Zynq_ZC702\RTOSDemo\src\lwIP_Demo\lwIP_port\include" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\CORTEX_A9_Zynq_ZC702\RTOSDemo\src\lwIP_Demo\lwIP_port\netif" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Source\include" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Source\portable\GCC\ARM_CA9" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\Common\ethernet\lwip-1.4.0\src\include\ipv4" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\Common\ethernet\lwip-1.4.0\src\include" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\CORTEX_A9_Zynq_ZC702\RTOSDemo\src\Full_Demo" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS-Plus\Source\FreeRTOS-Plus-CLI" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\Common\include" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\CORTEX_A9_Zynq_ZC702\RTOSDemo\src" -c -fmessage-length=0 -Wextra -ffunction-sections -fdata-sections -I../../RTOSDemo_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/lwIP_Demo/lwip-1.4.0/src/core/netif.o: C:/Users/CY/Documents/my_program/xilinx/SecureRTOS/Repo/FreeRTOS/Demo/Common/ethernet/lwip-1.4.0/src/core/netif.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM gcc compiler'
	arm-xilinx-eabi-gcc -Wall -O0 -g3 -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\CORTEX_A9_Zynq_ZC702\RTOSDemo\src\lwIP_Demo\lwIP_port\include" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\CORTEX_A9_Zynq_ZC702\RTOSDemo\src\lwIP_Demo\lwIP_port\netif" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Source\include" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Source\portable\GCC\ARM_CA9" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\Common\ethernet\lwip-1.4.0\src\include\ipv4" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\Common\ethernet\lwip-1.4.0\src\include" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\CORTEX_A9_Zynq_ZC702\RTOSDemo\src\Full_Demo" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS-Plus\Source\FreeRTOS-Plus-CLI" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\Common\include" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\CORTEX_A9_Zynq_ZC702\RTOSDemo\src" -c -fmessage-length=0 -Wextra -ffunction-sections -fdata-sections -I../../RTOSDemo_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/lwIP_Demo/lwip-1.4.0/src/core/pbuf.o: C:/Users/CY/Documents/my_program/xilinx/SecureRTOS/Repo/FreeRTOS/Demo/Common/ethernet/lwip-1.4.0/src/core/pbuf.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM gcc compiler'
	arm-xilinx-eabi-gcc -Wall -O0 -g3 -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\CORTEX_A9_Zynq_ZC702\RTOSDemo\src\lwIP_Demo\lwIP_port\include" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\CORTEX_A9_Zynq_ZC702\RTOSDemo\src\lwIP_Demo\lwIP_port\netif" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Source\include" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Source\portable\GCC\ARM_CA9" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\Common\ethernet\lwip-1.4.0\src\include\ipv4" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\Common\ethernet\lwip-1.4.0\src\include" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\CORTEX_A9_Zynq_ZC702\RTOSDemo\src\Full_Demo" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS-Plus\Source\FreeRTOS-Plus-CLI" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\Common\include" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\CORTEX_A9_Zynq_ZC702\RTOSDemo\src" -c -fmessage-length=0 -Wextra -ffunction-sections -fdata-sections -I../../RTOSDemo_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/lwIP_Demo/lwip-1.4.0/src/core/raw.o: C:/Users/CY/Documents/my_program/xilinx/SecureRTOS/Repo/FreeRTOS/Demo/Common/ethernet/lwip-1.4.0/src/core/raw.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM gcc compiler'
	arm-xilinx-eabi-gcc -Wall -O0 -g3 -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\CORTEX_A9_Zynq_ZC702\RTOSDemo\src\lwIP_Demo\lwIP_port\include" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\CORTEX_A9_Zynq_ZC702\RTOSDemo\src\lwIP_Demo\lwIP_port\netif" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Source\include" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Source\portable\GCC\ARM_CA9" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\Common\ethernet\lwip-1.4.0\src\include\ipv4" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\Common\ethernet\lwip-1.4.0\src\include" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\CORTEX_A9_Zynq_ZC702\RTOSDemo\src\Full_Demo" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS-Plus\Source\FreeRTOS-Plus-CLI" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\Common\include" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\CORTEX_A9_Zynq_ZC702\RTOSDemo\src" -c -fmessage-length=0 -Wextra -ffunction-sections -fdata-sections -I../../RTOSDemo_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/lwIP_Demo/lwip-1.4.0/src/core/stats.o: C:/Users/CY/Documents/my_program/xilinx/SecureRTOS/Repo/FreeRTOS/Demo/Common/ethernet/lwip-1.4.0/src/core/stats.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM gcc compiler'
	arm-xilinx-eabi-gcc -Wall -O0 -g3 -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\CORTEX_A9_Zynq_ZC702\RTOSDemo\src\lwIP_Demo\lwIP_port\include" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\CORTEX_A9_Zynq_ZC702\RTOSDemo\src\lwIP_Demo\lwIP_port\netif" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Source\include" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Source\portable\GCC\ARM_CA9" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\Common\ethernet\lwip-1.4.0\src\include\ipv4" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\Common\ethernet\lwip-1.4.0\src\include" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\CORTEX_A9_Zynq_ZC702\RTOSDemo\src\Full_Demo" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS-Plus\Source\FreeRTOS-Plus-CLI" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\Common\include" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\CORTEX_A9_Zynq_ZC702\RTOSDemo\src" -c -fmessage-length=0 -Wextra -ffunction-sections -fdata-sections -I../../RTOSDemo_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/lwIP_Demo/lwip-1.4.0/src/core/sys.o: C:/Users/CY/Documents/my_program/xilinx/SecureRTOS/Repo/FreeRTOS/Demo/Common/ethernet/lwip-1.4.0/src/core/sys.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM gcc compiler'
	arm-xilinx-eabi-gcc -Wall -O0 -g3 -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\CORTEX_A9_Zynq_ZC702\RTOSDemo\src\lwIP_Demo\lwIP_port\include" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\CORTEX_A9_Zynq_ZC702\RTOSDemo\src\lwIP_Demo\lwIP_port\netif" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Source\include" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Source\portable\GCC\ARM_CA9" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\Common\ethernet\lwip-1.4.0\src\include\ipv4" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\Common\ethernet\lwip-1.4.0\src\include" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\CORTEX_A9_Zynq_ZC702\RTOSDemo\src\Full_Demo" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS-Plus\Source\FreeRTOS-Plus-CLI" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\Common\include" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\CORTEX_A9_Zynq_ZC702\RTOSDemo\src" -c -fmessage-length=0 -Wextra -ffunction-sections -fdata-sections -I../../RTOSDemo_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/lwIP_Demo/lwip-1.4.0/src/core/tcp.o: C:/Users/CY/Documents/my_program/xilinx/SecureRTOS/Repo/FreeRTOS/Demo/Common/ethernet/lwip-1.4.0/src/core/tcp.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM gcc compiler'
	arm-xilinx-eabi-gcc -Wall -O0 -g3 -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\CORTEX_A9_Zynq_ZC702\RTOSDemo\src\lwIP_Demo\lwIP_port\include" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\CORTEX_A9_Zynq_ZC702\RTOSDemo\src\lwIP_Demo\lwIP_port\netif" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Source\include" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Source\portable\GCC\ARM_CA9" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\Common\ethernet\lwip-1.4.0\src\include\ipv4" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\Common\ethernet\lwip-1.4.0\src\include" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\CORTEX_A9_Zynq_ZC702\RTOSDemo\src\Full_Demo" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS-Plus\Source\FreeRTOS-Plus-CLI" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\Common\include" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\CORTEX_A9_Zynq_ZC702\RTOSDemo\src" -c -fmessage-length=0 -Wextra -ffunction-sections -fdata-sections -I../../RTOSDemo_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/lwIP_Demo/lwip-1.4.0/src/core/tcp_in.o: C:/Users/CY/Documents/my_program/xilinx/SecureRTOS/Repo/FreeRTOS/Demo/Common/ethernet/lwip-1.4.0/src/core/tcp_in.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM gcc compiler'
	arm-xilinx-eabi-gcc -Wall -O0 -g3 -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\CORTEX_A9_Zynq_ZC702\RTOSDemo\src\lwIP_Demo\lwIP_port\include" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\CORTEX_A9_Zynq_ZC702\RTOSDemo\src\lwIP_Demo\lwIP_port\netif" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Source\include" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Source\portable\GCC\ARM_CA9" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\Common\ethernet\lwip-1.4.0\src\include\ipv4" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\Common\ethernet\lwip-1.4.0\src\include" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\CORTEX_A9_Zynq_ZC702\RTOSDemo\src\Full_Demo" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS-Plus\Source\FreeRTOS-Plus-CLI" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\Common\include" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\CORTEX_A9_Zynq_ZC702\RTOSDemo\src" -c -fmessage-length=0 -Wextra -ffunction-sections -fdata-sections -I../../RTOSDemo_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/lwIP_Demo/lwip-1.4.0/src/core/tcp_out.o: C:/Users/CY/Documents/my_program/xilinx/SecureRTOS/Repo/FreeRTOS/Demo/Common/ethernet/lwip-1.4.0/src/core/tcp_out.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM gcc compiler'
	arm-xilinx-eabi-gcc -Wall -O0 -g3 -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\CORTEX_A9_Zynq_ZC702\RTOSDemo\src\lwIP_Demo\lwIP_port\include" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\CORTEX_A9_Zynq_ZC702\RTOSDemo\src\lwIP_Demo\lwIP_port\netif" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Source\include" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Source\portable\GCC\ARM_CA9" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\Common\ethernet\lwip-1.4.0\src\include\ipv4" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\Common\ethernet\lwip-1.4.0\src\include" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\CORTEX_A9_Zynq_ZC702\RTOSDemo\src\Full_Demo" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS-Plus\Source\FreeRTOS-Plus-CLI" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\Common\include" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\CORTEX_A9_Zynq_ZC702\RTOSDemo\src" -c -fmessage-length=0 -Wextra -ffunction-sections -fdata-sections -I../../RTOSDemo_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/lwIP_Demo/lwip-1.4.0/src/core/udp.o: C:/Users/CY/Documents/my_program/xilinx/SecureRTOS/Repo/FreeRTOS/Demo/Common/ethernet/lwip-1.4.0/src/core/udp.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM gcc compiler'
	arm-xilinx-eabi-gcc -Wall -O0 -g3 -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\CORTEX_A9_Zynq_ZC702\RTOSDemo\src\lwIP_Demo\lwIP_port\include" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\CORTEX_A9_Zynq_ZC702\RTOSDemo\src\lwIP_Demo\lwIP_port\netif" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Source\include" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Source\portable\GCC\ARM_CA9" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\Common\ethernet\lwip-1.4.0\src\include\ipv4" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\Common\ethernet\lwip-1.4.0\src\include" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\CORTEX_A9_Zynq_ZC702\RTOSDemo\src\Full_Demo" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS-Plus\Source\FreeRTOS-Plus-CLI" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\Common\include" -I"C:\Users\CY\Documents\my_program\xilinx\SecureRTOS\Repo\FreeRTOS\Demo\CORTEX_A9_Zynq_ZC702\RTOSDemo\src" -c -fmessage-length=0 -Wextra -ffunction-sections -fdata-sections -I../../RTOSDemo_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


