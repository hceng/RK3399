	
.text
.global  _start
_start: 				


	ldr  x29,=0x80000000	

	bl main        

halt:
	b  halt 

	


