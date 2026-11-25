#include "perfsim/asm.h"
	.option       nopic
	.attribute    unaligned_access, 0
	.attribute    stack_align, 16
	.text
	.align        2
	.globl        main
	.type         main, @function

#define DATA_1 a0
#define DATA_2 a1

main:
	la            DATA_1, data
	addi          DATA_2, DATA_1, 128
	MATCH_START
	NOP_32

# --- CASE 1 ---
# vsetivli zero,4,e32,m1,ta,ma
# vmv.v.i v8,0
# vse32.v v8,(DATA_1)
# lw t0,0(DATA_2)

# --- CASE 2 ---
	li            t0, 4
	li            t1, 1
	vsetvli       zero, zero, e32, m2, ta, ma
	NOP_4
loop:
	vle8.v        v10,(DATA_1)
	vle8.v        v11,(DATA_2)
	vsext.vf4     v12,v10
	vsext.vf4     v14,v11
	vadd.vx       v10,v14,s10
	vadd.vx       v12,v12,s9
	vmacc.vv      v8,v10,v12
	add           zero, zero, zero
	sub           t0, t0, t1
	add           zero, zero, zero
	bnez          t0, loop

# --- CASE 3 ---
# vmv.s.x v10,zero
# vredsum.vs v8,v8,v10
# vmv.x.s a2,v8
# beq zero, zero, btgt
# btgt:
# slli a4,s4,0x2
# lw a3,28(sp)
# add DATA_1,a3,DATA_1

	NOP_4
	MATCH_END
	RET_INSTR
	.size         main, .-main
	.data
data:
	MEM_WORDS_256
	MEM_WORDS_256

	.size         main, .-data
.ident "GCC:
	14.2.0"
	.section      .note.GNU-stack,"",@progbits

