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
# , -MAP=$(TARGET).map,-L[DIR] -I[LIB] -T=MKL25Z128xxx4_flash.ld
#-------------------------------------------------------------
include sources.mk

#Overrides
CPU = cortex-m0plus
ARCH = thumb
SPECS = nosys.specs
CSTD = c99
#Compilation
LD = arm-none-eabi-ld
AS = arm-none-eabi-as
TARGET = project1.out
MAP = project1
ifeq ($(PLATFORM),HOST)
	CC = gcc

	CFLAGS = -Werror -std=$(CSTD)\
	-DHOST_PLATFORM -I../include/common

	LDFLAGS = -Wl,-Map=$(MAP).map
else 
ifeq ($(PLATFORM),BBB)
	CC = arm-linux-gnueabihf-gcc

	CFLAGS = -Werror -std=$(CSTD)\
	-DBBB_PLATFORM
	-I../include/common

	LDFLAGS = -Wl,-Map=$(TARGET).map
else 
ifeq ($(PLATFORM),KL25Z)
	CC = arm-none-eabi-gcc

	CFLAGS = -mcpu=$(CPU) -m$(ARCH) \
        --specs=$(SPECS) -Werror -std=$(CSTD) \
	-DKL25Z_PLATFORM \
	-I../include/common

	LDFLAGS = -Wl, -Map=$(TARGET).map, \
	-T=MKL25Z128xxx4_flash.ld
endif
endif
endif
OBJS = $(SRCS:.c=.o)
ABC = $(SRCS:.c)
%.o : %.c
	$(CC) -o $@ $(CFLAGS) -c $<

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
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -DPROJECT1 -o $@
.PHONY: clean
clean:
	rm -f *.asm *.i *.o $(TARGET) $(TARGET).map



