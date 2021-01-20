CSRC := $(wildcard *.c)
COBJ := $(patsubst %.c,$(TOPOUT)/xilinx_bsp/scugic_v4_1/src/%.o,$(wildcard *.c))
ASMSRC := $(wildcard *.S)
ASMOBJ := $(patsubst %.S,$(TOPOUT)/xilinx_bsp/scugic_v4_1/src/%.o,$(wildcard *.S))
INC := -I$(TOPDIR)/ARM_CA9 -I$(TOPDIR)/core/include -I$(TOPDIR)/xilinx_bsp/include

$(TOPOUT)/xilinx_bsp/scugic_v4_1/src/%.o: %.c
	$(CC) $(CFLAGS) $(INC) -o $@ -c $< -Wall -mcpu=cortex-a9 -mfpu=vfpv3 -Wall -fno-omit-frame-pointer -g

$(TOPOUT)/xilinx_bsp/scugic_v4_1/src/%.o: %.S
	$(CC) $(CFLAGS) $(INC) -o $@ -c $< -Wall -mcpu=cortex-a9 -mfpu=vfpv3 -Wall -fno-omit-frame-pointer -g

xilinx_bsp/scugic_v4_1/src/: $(COBJ) $(ASMOBJ)
