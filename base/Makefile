# base
BASE_DIR := base
BASE_INC_DIR := $(BASE_DIR)/inc
BASE_INC_ARCH_DIR := $(BASE_INC_DIR)/$(ARCH)
BASE_SRC_DIR := $(BASE_DIR)/src
BASE_SRC_ARCH_DIR := $(BASE_SRC_DIR)/$(ARCH)

BASE_SOURCES := $(wildcard $(BASE_SRC_DIR)/*.c) $(wildcard $(BASE_SRC_ARCH_INC)/*.c)
BASE_OBJECTS := $(patsubst %.c,%.o,$(BASE_SOURCES))

INCLUDES += $(BASE_INC_DIR)

base: $(BASE_OBJECTS)

