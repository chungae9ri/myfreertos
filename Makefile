export PATH:=$(HOME)/bin/arm-2017q1/bin:$(PATH)
export LIB := $(HOME)/bin/arm-2017q1/arm-none-eabi/lib
export LIB2 :=$(HOME)/bin/arm-2017q1/lib/gcc/arm-none-eabi/6.3.1

export CC := arm-none-eabi-gcc
export ASM := arm-none-eabi-as
export LD := arm-none-eabi-ld

export TOPDIR := $(shell pwd)
export TOPOUT := $(TOPDIR)/out

#MAKEFILES = $(shell find . -maxdepth 2 -type f -name Makefile)
#SUBDIRS   = $(filter-out ./,$(dir $(MAKEFILES)))
SUBDIRS := core ARM_CA9 port xilinx_bsp
MODULES := $(addprefix $(TOPDIR)/, $(SUBDIRS))
#MODULES := $(TOPDIR)/core $(TOPDIR)/port $(TOPDIR)/ARM_CA9
OUTCSRCS := $(foreach sdir, $(MODULES), $(wildcard $(sdir)/*.c))
OUTCOBJS := $(patsubst $(TOPDIR)/%.c, $(TOPOUT)/%.o,$(OUTCSRCS))
OUTASMSRCS := $(foreach sdir, $(MODULES), $(wildcard $(sdir)/*.S))
OUTASMOBJS := $(patsubst $(TOPDIR)/%.S, $(TOPOUT)/%.o,$(OUTASMSRCS))

all:
	mkdir -p $(TOPOUT)
	for dir in $(SUBDIRS); do \
		mkdir -p $(TOPOUT)/$$dir;\
		$(MAKE) -C $$dir $$dir; \
	done
	$(LD) -T myfreertos.ld -o $(TOPOUT)/a.elf $(OUTCOBJS) $(OUTASMOBJS) -L$(LIB) -L$(LIB2) -lc -lgcc

clean :
	@echo clean
	rm -rf out
