PREFIX=aarch64-linux-android-
#PREFIX=arm-linux-gnueabihf-
CC=$(PREFIX)gcc
LD=$(PREFIX)ld
AR=$(PREFIX)ar
OBJCOPY=$(PREFIX)objcopy
OBJDUMP=$(PREFIX)objdump

# Add GCC lib
PLATFORM_LIBS += -L $(shell dirname `$(CC) $(CFLAGS) -print-libgcc-file-name`) -lgcc

rk3399.bin : start.S  led.c  main.c
	$(CC) -nostdlib -g -c -o start.o start.S
	$(CC) -nostdlib -g -c -o led.o led.c			
	$(CC) -nostdlib -g -c -o main.o main.c	
	
	$(LD) -Trk3399.lds -g start.o led.o  main.o -o rk3399_elf  $(PLATFORM_LIBS)
	
	$(OBJCOPY) -O binary -S rk3399_elf rk3399.bin
	$(OBJDUMP) -D -m arm  rk3399_elf > rk3399.dis	

clean:
	rm -f rk3399.dis  rk3399.bin rk3399_elf  *.o


	
