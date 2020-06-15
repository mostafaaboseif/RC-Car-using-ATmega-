################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../mcal/timer\ counter/timer\ counter.c 

OBJS += \
./mcal/timer\ counter/timer\ counter.o 

C_DEPS += \
./mcal/timer\ counter/timer\ counter.d 


# Each subdirectory must supply rules for building sources it contributes
mcal/timer\ counter/timer\ counter.o: ../mcal/timer\ counter/timer\ counter.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -O1 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"mcal/timer counter/timer counter.d" -MT"mcal/timer\ counter/timer\ counter.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


