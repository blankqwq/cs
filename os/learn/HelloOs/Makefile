MKDIR = mkdir
RM = rm
RMDIR = rmdir


CC = gcc
ASM = nasm
LD = ld
OBJCOPY=objcopy

CFLANGS = -c -Os -std=c99 -m32 -Wall -Wshadow -W -Wconversion -Wno-sign-conversion  -fno-stack-protector -fomit-frame-pointer -fno-builtin -fno-common  -ffreestanding  -Wno-unused-parameter -Wunused-variable# 去除elf格式
ASMBFLAGS = -f elf -w-orphan-labels
OJCYFLAGS	= -S -O binary
LDFLAGS = -s -static -T hello.lds -n -Map HelloOS.map 

HELLOOS_OBJS :=
HELLOOS_OBJS += entry.o main.o vgastr.o
HELLOOS_ELF = HelloOS.elf
HELLOOS_BIN = HelloOS.bin

.PYTHON: all build clean link bin

all:clean build all link bin 

clean:
	$(RM) -f *.o *.elf *.bin

build:$(HELLOOS_OBJS)

link: $(HELLOOS_ELF)

$(HELLOOS_ELF): $(HELLOOS_OBJS)
	$(LD) $(LDFLAGS) -o $@ $(HELLOOS_OBJS)

bin: $(HELLOOS_BIN)

$(HELLOOS_BIN): $(HELLOOS_ELF)
	$(OBJCOPY) $(OJCYFLAGS) $< $@

%.o:%.asm
	$(ASM) $(ASMBFLAGS) -o $@ $^

%.o:%.c
	$(CC) $(CFLANGS) -o $@ $^

