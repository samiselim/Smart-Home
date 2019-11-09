################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/Buzzer.c \
../HAL/Keypad.c \
../HAL/LCD.c \
../HAL/RTC.c \
../HAL/Temperature.c \
../HAL/ULTRASONIC.c 

OBJS += \
./HAL/Buzzer.o \
./HAL/Keypad.o \
./HAL/LCD.o \
./HAL/RTC.o \
./HAL/Temperature.o \
./HAL/ULTRASONIC.o 

C_DEPS += \
./HAL/Buzzer.d \
./HAL/Keypad.d \
./HAL/LCD.d \
./HAL/RTC.d \
./HAL/Temperature.d \
./HAL/ULTRASONIC.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/%.o: ../HAL/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


