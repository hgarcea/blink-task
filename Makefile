################################################################################
# Automatically-generated file. Do not edit!
################################################################################


PROJECT := blink-task
BOARD := i3d_ciaa_nxp


# Board definitions
ifeq ($(BOARD),i3d_ciaa_nxp)
	ARCH := cortexM4
	CPUTYPE := lpc43xx
	CPU := lpc4337
else
	$error("Unknown BOARD")
endif

# Compiler definitions
ifeq ($(ARCH),cortexM4)
	MCPU := cortex-m4
	OUT_FILE := $(PROJECT).axf
	CC := arm-none-eabi-gcc
	AS := arm-none-eabi-as
	AR := arm-none-eabi-ar
	SZ := arm-none-eabi-size
	OC := arm-none-eabi-objcopy
else
	$error("Unknown ARCH")
endif

# Libraries definitions
LIBS := $(BOARD) rtos 
ifeq ($(CPUTYPE),lpc43xx)
LIBS += lpc_chip_18xx_43xx
else
	$error("Unknown CPUTYPE")
endif

# Includes definitions
INCLUDES :=

# Output definitions
OUT_DIR := out
OUT_LIB_DIR := $(OUT_DIR)/lib
OUT_BIN_DIR := $(OUT_DIR)/bin
OUT_GEN_DIR := $(OUT_DIR)/gen
OUT_GEN_INC_DIR := $(OUT_GEN_DIR)/inc
OUT_GEN_INC_ARCH_DIR := $(OUT_GEN_INC_DIR)/$(ARCH)
OUT_GEN_SRC_DIR := $(OUT_GEN_DIR)/src
OUT_GEN_SRC_ARCH_DIR := $(OUT_GEN_SRC_DIR)/$(ARCH)


# Add inputs and outputs from these tool invocations to the build variables 

# Tool invocations
$(PROJECT): app $(LIBS) base
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	$(CC) -L"$(OUT_LIB_DIR)" -Xlinker -Map="$(OUT_BIN_DIR)/$(PROJECT).map" -Xlinker --gc-sections -mcpu=$(MCPU) -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -mthumb -T "base/linker/$(CPU).ld" $(APP_OBJECTS)  $(BASE_OBJECTS) $(foreach TMP, $(LIBS), -l$(TMP)) -lgcc -lc -lm -lrdimon -o "$(OUT_BIN_DIR)/$(OUT_FILE)"
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Modules
include app/Makefile
include board/Makefile
include rtos/Makefile
include chip/Makefile
include base/Makefile

#
%.o : %.s
	@echo 'Building object: $@'
	$(AS) -c -ggdb3 -mcpu=$(MCPU) -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -mthumb $< -o $@ 
	@echo 'Finished building object: $@'
	@echo ' '

#
%.o : %.c
	@echo 'Building object: $@'
	$(CC) -c -Wall -ggdb3 -fdata-sections -ffunction-sections -mcpu=$(MCPU) -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -mthumb -DCORE_M4  $(foreach TMP, $(INCLUDES), -I"$(TMP)") -DARCH=$(ARCH) -DCPUTYPE=$(CPUTYPE) -DCPU=$(CPU) -DBOARD=$(BOARD) $< -o $@ 
	@echo 'Finished building object: $@'
	@echo ' '

# All Target
all: $(PROJECT)

# Install
install: all
ifeq ($(CPU),lpc4337)
	-openocd -f "tools/openocd/$(CPU).cfg" -c "init" -c "halt" -c "flash write_image erase unlock $(OUT_BIN_DIR)/$(PROJECT).bin 0x1A000000 bin" -c "reset" -c "exit"
else
	$error("Unknown CPU")
endif
	-@echo ' '

# Other Targets
clean:
	-$(RM) -r $(GPARSER_OBJECTS) 
	-$(RM) -r $(PID_OBJECTS) 
	-$(RM) -r $(POSIX_OBJECTS) 
	-$(RM) -r $(RTOS_OBJECTS) 
	-$(RM) -r $(BASE_OBJECTS) 
	-$(RM) -r $(BOARD_OBJECTS) 
	-$(RM) -r $(CHIP_OBJECTS) 
	-$(RM) -r $(APP_OBJECTS)  
	-$(RM) -r $(OUT_BIN_DIR)/*.axf $(OUT_BIN_DIR)/*.bin $(OUT_BIN_DIR)/*.map 
	-$(RM) -r $(OUT_LIB_DIR)/*.a 
	-$(RM) -r $(OUT_GEN_INC_ARCH_DIR)/*.h $(OUT_GEN_INC_ARCH_DIR)/*.h.old
	-$(RM) -d $(OUT_GEN_INC_ARCH_DIR)
	-$(RM) -r $(OUT_GEN_INC_DIR)/*.h $(OUT_GEN_INC_DIR)/*.h.old 
	-$(RM) -d $(OUT_GEN_INC_DIR)
	-$(RM) -r $(OUT_GEN_SRC_ARCH_DIR)/*.c $(OUT_GEN_SRC_ARCH_DIR)/*.c.old
	-$(RM) -d $(OUT_GEN_SRC_ARCH_DIR)
	-$(RM) -r $(OUT_GEN_SRC_DIR)/*.c $(OUT_GEN_SRC_DIR)/*.c.old 
	-$(RM) -d $(OUT_GEN_SRC_DIR)
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-$(SZ) "$(OUT_BIN_DIR)/$(OUT_FILE)"
	-$(OC) -v -O binary "$(OUT_BIN_DIR)/$(OUT_FILE)" "$(OUT_BIN_DIR)/$(PROJECT).bin"
#	-@checksum -p $(CPU) -d "$(OUT_BIN_DIR)/$(PROJECT).bin"
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

