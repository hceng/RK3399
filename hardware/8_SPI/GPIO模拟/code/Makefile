PREFIX=aarch64-linux-android-
#PREFIX=arm-linux-gnueabihf-
CC=$(PREFIX)gcc
LD=$(PREFIX)ld
AR=$(PREFIX)ar
OBJCOPY=$(PREFIX)objcopy
OBJDUMP=$(PREFIX)objdump

# Add GCC lib
PLATFORM_LIBS += -L $(shell dirname `$(CC) $(CFLAGS) -print-libgcc-file-name`) -lgcc

rk3399.bin : start.S  led.c uart.c printf.c	int.c timer.c i2c.c spi.c main.c
	$(CC) -nostdlib -fno-builtin -g -c -o start.o start.S
	$(CC) -nostdlib -fno-builtin -g -c -o led.o led.c	
	$(CC) -nostdlib -fno-builtin -g -c -o uart.o uart.c	
	$(CC) -nostdlib -fno-builtin -g -c -o printf.o printf.c		
	$(CC) -nostdlib -fno-builtin -g -c -o int.o int.c	
	$(CC) -nostdlib -fno-builtin -g -c -o timer.o timer.c
	$(CC) -nostdlib -fno-builtin -g -c -o i2c.o i2c.c
	$(CC) -nostdlib -fno-builtin -g -c -o spi.o spi.c
	$(CC) -nostdlib -fno-builtin -g -c -o main.o main.c	
	
	$(LD) -Trk3399.lds -g start.o led.o uart.o printf.o int.o timer.o i2c.o spi.o main.o -o rk3399_elf  $(PLATFORM_LIBS)
	
	$(OBJCOPY) -O binary -S rk3399_elf rk3399.bin
	$(OBJDUMP) -D  rk3399_elf > rk3399.dis	

clean:
	rm -f rk3399.dis  rk3399.bin rk3399_elf  *.o


	
