# lpc_chip_18xx_43xx

CHIP_INC_DIR := $(CHIP_DIR)/lpc_chip_18xx_43xx/inc
CHIP_SRC_DIR := $(CHIP_DIR)/lpc_chip_18xx_43xx/src

CHIP_SOURCES := $(wildcard $(CHIP_SRC_DIR)/*.c) $(wildcard $(CHIP_SRC_DIR)/$(ARCH)/*.c)
CHIP_OBJECTS := $(patsubst %.c,%.o,$(CHIP_SOURCES))

INCLUDES += $(CHIP_INC_DIR)

lpc_chip_18xx_43xx: $(CHIP_OBJECTS)
	@echo 'Building library: lib$@.a'
	$(AR) -crs "$(OUT_LIB_DIR)/lib$@.a" $(CHIP_OBJECTS)
	@echo 'Finished building target: lib$@.a'
	@echo ' '

