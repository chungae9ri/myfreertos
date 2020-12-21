CSRC := $(wildcard *.c)
COBJ := $(patsubst %.c,$(TOPOUT)/core/%.o,$(wildcard *.c))
ASMSRC := $(wildcard *.S)
ASMOBJ := $(patsubst %.S,$(TOPOUT)/core/%.o,$(wildcard *.S))
INC := -I$(TOPDIR)/ARM_CA9 -I$(TOPDIR)/core/include -I$(TOPDIR)/port -I$(TOPDIR)/port/include

$(TOPOUT)/core/%.o: %.c
	$(CC) $(CFLAGS) $(INC) -o $@ -c $< -Wall

$(TOPOUT)/core/%.o: %.S
	$(CC) $(INC) -o $@ -c $< -Wall

core: $(COBJ) $(ASMOBJ)
