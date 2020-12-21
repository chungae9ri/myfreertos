CSRC := $(wildcard *.c)
COBJ := $(patsubst %.c,$(TOPOUT)/port/%.o,$(wildcard *.c))
INC := -I$(TOPDIR)/ARM_CA9 -I$(TOPDIR)/core/include -I$(TOPDIR)/port -I$(TOPDIR)/port/include

$(TOPOUT)/port/%.o: %.c
	$(CC) $(CFLAGS) $(INC) -o $@ -c $< -Wall

port: $(COBJ)
