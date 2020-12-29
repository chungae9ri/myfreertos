CSRC := $(wildcard *.c)
COBJ := $(patsubst %.c,$(TOPOUT)/core/%.o,$(wildcard *.c))
ASMSRC := $(wildcard *.S)
ASMOBJ := $(patsubst %.S,$(TOPOUT)/core/%.o,$(wildcard *.S))
INC := -I$(TOPDIR)/ARM_CA9 -I$(TOPDIR)/core/include -I$(TOPDIR)/xilinx_bsp/include

$(TOPOUT)/core/%.o: %.c
	$(CC) $(CFLAGS) $(INC) -o $@ -c $< -Wall -mcpu=cortex-a9 -mfpu=vfpv3 -Wall -fno-omit-frame-pointer

$(TOPOUT)/core/%.o: %.S
	$(CC) $(INC) -o $@ -c $< -Wall -mcpu=cortex-a9 -mfpu=vfpv3 -Wall -fno-omit-frame-pointer

core: $(COBJ) $(ASMOBJ)
