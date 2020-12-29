CSRC := $(wildcard *.c)
COBJ := $(patsubst %.c,$(TOPOUT)/port/%.o,$(wildcard *.c))
INC := -I$(TOPDIR)/ARM_CA9 -I$(TOPDIR)/core/include -I$(TOPDIR)/xilinx_bsp/include

$(TOPOUT)/port/%.o: %.c
	$(CC) $(CFLAGS) $(INC) -o $@ -c $< -Wall -mcpu=cortex-a9 -mfpu=vfpv3 -Wall -fno-omit-frame-pointer

port: $(COBJ)
