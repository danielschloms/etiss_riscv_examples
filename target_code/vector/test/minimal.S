#include "asm.h"
# .file "basic.c"
	.option       nopic
	.attribute    arch, "rv32i2p1_m2p0_f2p2_zicsr2p0_zve32f1p0_zve32x1p0_zvl32b1p0"
	.attribute    unaligned_access, 0
	.attribute    stack_align, 16
	.text
	.align        2
	.globl        main
	.type         main, @function
main:
	addi          sp,sp,-32
	sw            ra,28(sp)
	sw            s0,24(sp)
	addi          s0,sp,32
	la            a0, data
	addi          a1, a0, 128
	addi          a2, a1, 128
	li            a3, 10
	li            a4, 128
	MATCH_START
	vsetivli      zero,2,e32,mf2,ta,ma
	vmv.v.i       v0,0
	MATCH_END
	andi          a0,a0,0
	lw            ra,28(sp)
	lw            s0,24(sp)
	addi          sp,sp,32
	RET_INSTR
	.size         main, .-main

	.data
data:
	MEM_WORDS_256
	MEM_WORDS_256

.ident "GCC:
	()            14.2.0"
	.section      .note.GNU-stack,"",@progbits
