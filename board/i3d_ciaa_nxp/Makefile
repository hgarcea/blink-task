# i3d_ciaa

BOARD_INC_DIR := $(BOARD_DIR)/inc
BOARD_INC_BRD_DIR := $(BOARD_DIR)/$(BOARD)/inc
BOARD_SRC_DIR := $(BOARD_DIR)/src
BOARD_SRC_BRD_DIR := $(BOARD_DIR)/$(BOARD)/src

BOARD_SOURCES := $(wildcard $(BOARD_SRC_BRD_DIR)/*.c)
BOARD_OBJECTS := $(patsubst %.c,%.o,$(BOARD_SOURCES))

INCLUDES += $(BOARD_INC_BRD_DIR)

i3d_ciaa_nxp: $(BOARD_OBJECTS)
	@echo 'Building library: lib$@.a'
	$(AR) -crs "$(OUT_LIB_DIR)/lib$@.a" $(BOARD_OBJECTS)
	@echo 'Finished building target: lib$@.a'
	@echo ' '

