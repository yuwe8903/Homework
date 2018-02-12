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

#Overrides
CPU = cortex-m0plus
ARCH = thumb
SPECS = nosys.specs
CSTD = c99
#Compilation
#CC = arm-none-eabi-gcc
LD = arm-none-eabi-ld
TARGET = project1.elf
LDFLAGS = -Wl, -T, -MAP=$(TARGET).map, MKL25Z128xxx4_flash.ld

ifeq ($(PLATFORM),HOST)
	CC = gcc
	CFLAGS = -Werror\
	-DHOST_PLATFORM
else 
ifeq ($(PLATFORM),BBB)
	CC = arm-linux-gnueabihf-gcc
	CFLAGS = -Werror -std=$(CSTD)\
	-DBBB_PLATFORM
else 
ifeq ($(PLATFORM),KL25Z)
	CC = arm-none-eabi-gcc
	CFLAGS = -mcpu=$(CPU) -m$(ARCH) \
        --specs=$(SPECS) -Werror -std=$(CSTD) \
	-DKL25Z_PLATFORM
endif
endif
endif
OBJS = $(SRCS:.c=.o)

%.o : %.c
	$(CC) -c $< $(CFLAGS) -o $@

%.i : %.c
	$(CC) -E $< $(CFLAGS) -o $@

%.asm : %.c
	$(CC) -S $< $(CFLAGS) -o $@

.PHONY: compile-all
compile-all: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $@
.PHONY: build
build: all
.PHONY: all
all: $(TARGET)
$(TARGET): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $@
.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET) $(TARGET).map



