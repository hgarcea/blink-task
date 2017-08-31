# chip

CHIP_DIR := chip
ifeq ($(CPUTYPE),lpc43xx)
	include chip/lpc_chip_18xx_43xx/Makefile
else
	$error("Unknown CPUTYPE")
endif

