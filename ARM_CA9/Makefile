CSRC := $(wildcard *.c)
COBJ := $(patsubst %.c,$(TOPOUT)/ARM_CA9/%.o,$(wildcard *.c))
ASMSRC := $(wildcard *.S)
ASMOBJ := $(patsubst %.S,$(TOPOUT)/ARM_CA9/%.o,$(wildcard *.S))
INC := -I$(TOPDIR)/ARM_CA9 -I$(TOPDIR)/core/include -I$(TOPDIR)/port -I$(TOPDIR)/port/include

$(TOPOUT)/ARM_CA9/%.o: %.c
	$(CC) $(CFLAGS) $(INC) -o $@ -c $< -Wall -g -mcpu=cortex-a9 -mfpu=vfpv3 -Wall -fno-omit-frame-pointer

$(TOPOUT)/ARM_CA9/%.o: %.S
	$(CC) $(INC) -o $@ -c $< -Wall -g -mcpu=cortex-a9 -mfpu=vfpv3 -Wall -fno-omit-frame-pointer

ARM_CA9: $(COBJ) $(ASMOBJ)
