SECTIONS {
	. = 0x200000;  
	. = ALIGN(8);
    .text : 
	{ 
		start.o(.text)
		main.o(.text)
		led.o(.text)
		*(.text) 
	}
    .rodata ALIGN(8) : {*(.rodata*)} 
    .data   ALIGN(8) : { *(.data) }
    __bss_start = .;
    .bss   ALIGN(8)  : { *(.bss)  *(COMMON) }
    __bss_end = .;
}
