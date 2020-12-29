CSRC := $(wildcard *.c)
COBJ := $(patsubst %.c,$(TOPOUT)/xilinx_bsp/%.o,$(wildcard *.c))
ASMSRC := $(wildcard *.S)
ASMOBJ := $(patsubst %.S,$(TOPOUT)/xilinx_bsp/%.o,$(wildcard *.S))
INC := -I$(TOPDIR)/core/include -I$(TOPDIR)/xilinx_bsp/include -I$(TOPDIR)/xilinx_bsp/scugic_v4_1/src -I$(TOPDIR)/xilinx_bsp/scutimer_v2_1/src -I$(TOPDIR)/xilinx_bsp/uartps_v3_8/src

$(TOPOUT)/xilinx_bsp/%.o: %.c
	$(CC) $(CFLAGS) $(INC) -o $@ -c $< -Wall -mcpu=cortex-a9 -mfpu=vfpv3 -Wall -fno-omit-frame-pointer

$(TOPOUT)/xilinx_bsp/%.o: %.S
	$(CC) $(CFLAGS) $(INC) -o $@ -c $< -Wall -mcpu=cortex-a9 -mfpu=vfpv3 -Wall -fno-omit-frame-pointer

xilinx_bsp: $(COBJ) $(ASMOBJ)
