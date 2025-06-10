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
	MATCH_START
	la            t2, data
	li            t1, 16
	addi          t3, t2, 16
	vsetvli       t0,t1,e32,m1,ta,ma
	vle32.v       v2, (t2)
	vle32.v       v3, (t3)
	vle32.v       v4, (t2)
	vle32.v       v5, (t3)
	vle32.v       v6, (t2)
	vle32.v       v7, (t3)
	vle32.v       v8, (t2)
	vle32.v       v9, (t3)
	vle32.v       v10, (t2)
	vle32.v       v11, (t3)
	vle32.v       v11, (t2)
	vle32.v       v11, (t3)
	vle32.v       v11, (t3)
	vle32.v       v12, (t2)
	vle32.v       v13, (t3)
	vle32.v       v14, (t3)
	vadd.vv       v6, v2, v4
	vadd.vv       v7, v2, v4
	vadd.vv       v8, v2, v4
	vadd.vv       v9, v2, v4
	vadd.vv       v10, v2, v4
	vadd.vv       v11, v2, v4
	vadd.vv       v12, v2, v4
	vadd.vv       v13, v2, v4
	vadd.vv       v14, v2, v4
	vadd.vv       v15, v2, v4
	vadd.vv       v16, v2, v4
	vadd.vv       v17, v2, v4
	vadd.vv       v18, v2, v4
	NOP_32
	NOP_32
	NOP_32
	NOP_32
	NOP_32
	NOP_32
	NOP_32
	NOP_32
	vse32.v       v6, (t2)
	vse32.v       v7, (t2)
	vse32.v       v8, (t2)
	vse32.v       v9, (t2)
	vse32.v       v10, (t2)
	vse32.v       v11, (t2)
	vse32.v       v11, (t2)
	vse32.v       v13, (t2)
	vse32.v       v14, (t2)
	vse32.v       v15, (t2)
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

.ident "GCC:
	()            14.2.0"
	.section      .note.GNU-stack,"",@progbits
