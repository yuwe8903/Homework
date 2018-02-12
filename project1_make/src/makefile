#------------------------------------------------------------
# Use: make [targets][overrides]
# Targets :
#	.o - Builds object files from corresponding .c file
#	all - Builds and links all source file
#	clean - Remove all generated files
# Overrides:
#	CPU - ARM Cortex Architecture (cortex-moplus)
#	ARCH - ARM Architecture (arm, thumb)
#	SPECS - Specs file to give the linker (nosys.specs)
#
#-------------------------------------------------------------
include sources.mk
#ARCH:=$(shell arch)
#CWD:=$(shell pwd)
#OS:=(shell uname)
#Overrides
CPU = cortex-m0plus
ARCH = thumb
SPECS = nosys.specs
CSTD = c99
#Compilation
#CC = arm-none-eabi-gcc
LD = arm-none-eabi-ld
TARGET = main.out
LDFLAGS = -Wl, -MAP=$(TARGET).map
#CFLAGS = -mcpu=$(CPU) -m$(ARCH) \
	--specs=$(SPECS) -Werror -std=$(CSTD)

ifeq ($(PLATFORM),HOST)
	CC = gcc
	CFLAGS = -Werror
else 
ifeq ($(PLATFORM),BBB)
	CC = arm-linux-gnueabihf-gcc
	CFLAGS = -Werror -std=$(CSTD)
else 
ifeq ($(PLATFORM),KL25Z)
	CC = arm-none-eabi-gcc
	CFLAGS = -mcpu=$(CPU) -m$(ARCH) \
        --specs=$(SPECS) -Werror -std=$(CSTD)
endif
endif
endif

OBJS = $(SRCS:.c=.o)
%.o : %.c
	$(CC) -c $< $(CFLAGS) -o $@

.PHONY: build
build: all
.PHONY: all
all: $(TARGET)
$(TARGET): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $@
.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET) $(TARGET).map

