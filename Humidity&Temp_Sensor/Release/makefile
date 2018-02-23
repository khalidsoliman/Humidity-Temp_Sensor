################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include LCD/subdir.mk
-include DHT11/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Humidity_Sensor.lss \

FLASH_IMAGE += \
Humidity_Sensor.hex \

EEPROM_IMAGE += \
Humidity_Sensor.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: Humidity_Sensor.elf secondary-outputs

# Tool invocations
Humidity_Sensor.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Humidity_Sensor.map -mmcu=atmega32 -o "Humidity_Sensor.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Humidity_Sensor.lss: Humidity_Sensor.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Humidity_Sensor.elf  >"Humidity_Sensor.lss"
	@echo 'Finished building: $@'
	@echo ' '

Humidity_Sensor.hex: Humidity_Sensor.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Humidity_Sensor.elf  "Humidity_Sensor.hex"
	@echo 'Finished building: $@'
	@echo ' '

Humidity_Sensor.eep: Humidity_Sensor.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex Humidity_Sensor.elf  "Humidity_Sensor.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Humidity_Sensor.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Humidity_Sensor.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Humidity_Sensor.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
