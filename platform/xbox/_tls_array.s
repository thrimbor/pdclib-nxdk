// This creates a special symbol with the least significant bit set.
// It signals to the linker that this code is SafeSEH-compatible.
.text
.def @feat.00;
.scl  3; // IMAGE_SYM_CLASS_STATIC
.type 0; // IMAGE_SYM_TYPE_NULL
.endef
.globl @feat.00
.set @feat.00, 1

.data
// _tls_array is a constant describing the offset of StackBase inside the NT TEB
.globl __tls_array
.equ __tls_array, 0x04
