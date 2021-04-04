// This creates a special symbol with the least significant bit set.
// It signals to the linker that this code is SafeSEH-compatible.
.text
.def @feat.00;
.scl  3; // IMAGE_SYM_CLASS_STATIC
.type 0; // IMAGE_SYM_TYPE_NULL
.endef
.globl @feat.00
.set @feat.00, 1


.text

/*
Buffer layout:
     0: unsigned long ebp
     4: unsigned long ebx
     8: unsigned long edi
    12: unsigned long esi
    16: unsigned long esp
    20: unsigned long eip
*/

.globl _longjmp
_longjmp:
    movl 4(%esp), %ecx
    movl 8(%esp), %eax

    movl (%ecx), %ebp
    movl 4(%ecx), %ebx
    movl 8(%ecx), %edi
    movl 12(%ecx), %esi
    movl 16(%ecx), %esp
    movl 20(%ecx), %edx
    testl %eax, %eax
    jnz .r
    incl %eax
.r: jmp *%edx
