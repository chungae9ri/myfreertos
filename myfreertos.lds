OUTPUT_ARCH(arm)
ENTRY(_vector_table) 

SECTIONS
{
	. = 0x100000;
	.text : {
		*(.freertos_vectors)
		*(.vectors)
		*(.boot)
		*(.text)
	}
	.data : { 
		*(.data);
	} 
	.bss : { 
		*(.bss); 
	}
}
