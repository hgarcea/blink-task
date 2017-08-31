# RTOS
RTOS_DIR := rtos
RTOS_INC_DIR := $(RTOS_DIR)/inc
RTOS_INC_ARCH_DIR := $(RTOS_INC_DIR)/$(ARCH)
RTOS_SRC_DIR := $(RTOS_DIR)/src
RTOS_SRC_ARCH_DIR := $(RTOS_SRC_DIR)/$(ARCH)
RTOS_GEN_DIR := $(RTOS_DIR)/gen
RTOS_GEN_INC_DIR := $(RTOS_GEN_DIR)/inc
RTOS_GEN_INC_ARCH_DIR := $(RTOS_GEN_INC_DIR)/$(ARCH)
RTOS_GEN_SRC_DIR := $(RTOS_GEN_DIR)/src
RTOS_GEN_SRC_ARCH_DIR := $(RTOS_GEN_SRC_DIR)/$(ARCH)

rtos_GEN_FILES := $(RTOS_GEN_INC_DIR)/Os_Internal_Cfg.h.php
rtos_GEN_FILES += $(RTOS_GEN_INC_DIR)/Os_Cfg.h.php
rtos_GEN_FILES += $(RTOS_GEN_SRC_DIR)/Os_Cfg.c.php
rtos_GEN_FILES += $(RTOS_GEN_SRC_DIR)/Os_Internal_Cfg.c.php
rtos_GEN_FILES += $(RTOS_GEN_INC_ARCH_DIR)/Os_Internal_Arch_Cfg.h.php
rtos_GEN_FILES += $(RTOS_GEN_SRC_ARCH_DIR)/Os_Internal_Arch_Cfg.c.php

RTOS_SOURCES := $(wildcard $(OUT_GEN_SRC_DIR)/*.c) $(wildcard $(OUT_GEN_SRC_ARCH_DIR)/*.c) $(wildcard $(RTOS_SRC_DIR)/*.c) $(wildcard $(RTOS_SRC_ARCH_DIR)/*.c)
RTOS_ASM_SOURCES := $(wildcard $(RTOS_SRC_ARCH_DIR)/*.s)

RTOS_OBJECTS := $(patsubst %.c,%.o,$(RTOS_SOURCES)) $(patsubst %.s,%.o,$(RTOS_ASM_SOURCES))

INCLUDES += $(RTOS_INC_DIR) $(RTOS_INC_ARCH_DIR) $(RTOS_INC_ARCH_DIR)/$(CPUTYPE) $(RTOS_GEN_INC_DIR) $(RTOS_GEN_INC_ARCH_DIR) $(OUT_GEN_INC_DIR) $(OUT_GEN_INC_ARCH_DIR)

rtos: generate $(RTOS_OBJECTS)
	@echo 'Building library: lib$@.a'
	$(AR) -crs "$(OUT_LIB_DIR)/lib$@.a" $(RTOS_OBJECTS)
	@echo 'Finished building target: lib$@.a'
	@echo ' '

# rtos OSEK generation
generate: app/etc/config.oil $(rtos_GEN_FILES)
	@echo 'Generate config: $<'
	php "rtos/generator/generator.php" --cmdline -l -v -DARCH=$(ARCH) -DCPUTYPE=$(CPUTYPE) -DCPU=$(CPU) -c "app/etc/config.oil" -f $(foreach TMP, $(rtos_GEN_FILES), $(TMP)) -o $(OUT_GEN_DIR)

