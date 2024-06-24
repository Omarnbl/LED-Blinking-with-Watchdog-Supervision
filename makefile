################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include WDGM/subdir.mk
-include WDGDRV/subdir.mk
-include TimerDriver/subdir.mk
-include LEDM/subdir.mk
-include GPIO/subdir.mk
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

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := ES_Project
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
ES_Project.lss \
ES_Project.lss \
ES_Project.lss \
ES_Project.lss \
ES_Project.lss \

FLASH_IMAGE += \
ES_Project.hex \
ES_Project.hex \
ES_Project.hex \
ES_Project.hex \
ES_Project.hex \

EEPROM_IMAGE += \
ES_Project.eep \
ES_Project.eep \
ES_Project.eep \
ES_Project.eep \
ES_Project.eep \

SIZEDUMMY += \
sizedummy \
sizedummy \
sizedummy \
sizedummy \
sizedummy \


# All Target
all: main-build

# Main-build Target
main-build: ES_Project.elf secondary-outputs

# Tool invocations
ES_Project.elf: $(OBJS) $(USER_OBJS) makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,ES_Project.map -mmcu=atmega328p -o "ES_Project.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

ES_Project.lss: ES_Project.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S ES_Project.elf  >"ES_Project.lss"
	@echo 'Finished building: $@'
	@echo ' '

ES_Project.hex: ES_Project.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex ES_Project.elf  "ES_Project.hex"
	@echo 'Finished building: $@'
	@echo ' '

ES_Project.eep: ES_Project.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex ES_Project.elf  "ES_Project.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: ES_Project.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega328p ES_Project.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) ES_Project.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents main-build

-include ../makefile.targets
