#include "asm.h"
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
  la            a0, data
  addi          a1, a0, 256
  li            t5, 15
  
  li        t1, 512
  vadd_vv_e32_m1_512:
  mv        t0, t1
  vsetvli   t1, t0, e32, m1, ta, ma
  vle32.v   v1,(a0)
  vle32.v   v2,(a1)
  vadd.vv   v0, v1, v2
  vse32.v   v0, (a0)
  sub       t1, t0, t1
  bnez      t1, vadd_vv_e32_m1_512

  
  li        t1, 512
  vsub_vv_e32_m1_512:
  mv        t0, t1
  vsetvli   t1, t0, e32, m1, ta, ma
  vle32.v   v1,(a0)
  vle32.v   v2,(a1)
  vsub.vv   v0, v1, v2
  vse32.v   v0, (a0)
  sub       t1, t0, t1
  bnez      t1, vsub_vv_e32_m1_512

  
  li        t1, 512
  vmadc_vv_e32_m1_512:
  mv        t0, t1
  vsetvli   t1, t0, e32, m1, ta, ma
  vle32.v   v1,(a0)
  vle32.v   v2,(a1)
  vmadc.vv   v0, v1, v2
  vse32.v   v0, (a0)
  sub       t1, t0, t1
  bnez      t1, vmadc_vv_e32_m1_512

  
  li        t1, 512
  vmsbc_vv_e32_m1_512:
  mv        t0, t1
  vsetvli   t1, t0, e32, m1, ta, ma
  vle32.v   v1,(a0)
  vle32.v   v2,(a1)
  vmsbc.vv   v0, v1, v2
  vse32.v   v0, (a0)
  sub       t1, t0, t1
  bnez      t1, vmsbc_vv_e32_m1_512

  
  li        t1, 512
  vand_vv_e32_m1_512:
  mv        t0, t1
  vsetvli   t1, t0, e32, m1, ta, ma
  vle32.v   v1,(a0)
  vle32.v   v2,(a1)
  vand.vv   v0, v1, v2
  vse32.v   v0, (a0)
  sub       t1, t0, t1
  bnez      t1, vand_vv_e32_m1_512

  
  li        t1, 512
  vor_vv_e32_m1_512:
  mv        t0, t1
  vsetvli   t1, t0, e32, m1, ta, ma
  vle32.v   v1,(a0)
  vle32.v   v2,(a1)
  vor.vv   v0, v1, v2
  vse32.v   v0, (a0)
  sub       t1, t0, t1
  bnez      t1, vor_vv_e32_m1_512

  
  li        t1, 512
  vxor_vv_e32_m1_512:
  mv        t0, t1
  vsetvli   t1, t0, e32, m1, ta, ma
  vle32.v   v1,(a0)
  vle32.v   v2,(a1)
  vxor.vv   v0, v1, v2
  vse32.v   v0, (a0)
  sub       t1, t0, t1
  bnez      t1, vxor_vv_e32_m1_512

  
  li        t1, 512
  vsll_vv_e32_m1_512:
  mv        t0, t1
  vsetvli   t1, t0, e32, m1, ta, ma
  vle32.v   v1,(a0)
  vle32.v   v2,(a1)
  vsll.vv   v0, v1, v2
  vse32.v   v0, (a0)
  sub       t1, t0, t1
  bnez      t1, vsll_vv_e32_m1_512

  
  li        t1, 512
  vsrl_vv_e32_m1_512:
  mv        t0, t1
  vsetvli   t1, t0, e32, m1, ta, ma
  vle32.v   v1,(a0)
  vle32.v   v2,(a1)
  vsrl.vv   v0, v1, v2
  vse32.v   v0, (a0)
  sub       t1, t0, t1
  bnez      t1, vsrl_vv_e32_m1_512

  
  li        t1, 512
  vsra_vv_e32_m1_512:
  mv        t0, t1
  vsetvli   t1, t0, e32, m1, ta, ma
  vle32.v   v1,(a0)
  vle32.v   v2,(a1)
  vsra.vv   v0, v1, v2
  vse32.v   v0, (a0)
  sub       t1, t0, t1
  bnez      t1, vsra_vv_e32_m1_512

  
  li        t1, 512
  vmseq_vv_e32_m1_512:
  mv        t0, t1
  vsetvli   t1, t0, e32, m1, ta, ma
  vle32.v   v1,(a0)
  vle32.v   v2,(a1)
  vmseq.vv   v0, v1, v2
  vse32.v   v0, (a0)
  sub       t1, t0, t1
  bnez      t1, vmseq_vv_e32_m1_512

  
  li        t1, 512
  vmsne_vv_e32_m1_512:
  mv        t0, t1
  vsetvli   t1, t0, e32, m1, ta, ma
  vle32.v   v1,(a0)
  vle32.v   v2,(a1)
  vmsne.vv   v0, v1, v2
  vse32.v   v0, (a0)
  sub       t1, t0, t1
  bnez      t1, vmsne_vv_e32_m1_512

  
  li        t1, 512
  vmsltu_vv_e32_m1_512:
  mv        t0, t1
  vsetvli   t1, t0, e32, m1, ta, ma
  vle32.v   v1,(a0)
  vle32.v   v2,(a1)
  vmsltu.vv   v0, v1, v2
  vse32.v   v0, (a0)
  sub       t1, t0, t1
  bnez      t1, vmsltu_vv_e32_m1_512

  
  li        t1, 512
  vmslt_vv_e32_m1_512:
  mv        t0, t1
  vsetvli   t1, t0, e32, m1, ta, ma
  vle32.v   v1,(a0)
  vle32.v   v2,(a1)
  vmslt.vv   v0, v1, v2
  vse32.v   v0, (a0)
  sub       t1, t0, t1
  bnez      t1, vmslt_vv_e32_m1_512

  
  li        t1, 512
  vmsleu_vv_e32_m1_512:
  mv        t0, t1
  vsetvli   t1, t0, e32, m1, ta, ma
  vle32.v   v1,(a0)
  vle32.v   v2,(a1)
  vmsleu.vv   v0, v1, v2
  vse32.v   v0, (a0)
  sub       t1, t0, t1
  bnez      t1, vmsleu_vv_e32_m1_512

  
  li        t1, 512
  vmsle_vv_e32_m1_512:
  mv        t0, t1
  vsetvli   t1, t0, e32, m1, ta, ma
  vle32.v   v1,(a0)
  vle32.v   v2,(a1)
  vmsle.vv   v0, v1, v2
  vse32.v   v0, (a0)
  sub       t1, t0, t1
  bnez      t1, vmsle_vv_e32_m1_512

  
  li        t1, 512
  vminu_vv_e32_m1_512:
  mv        t0, t1
  vsetvli   t1, t0, e32, m1, ta, ma
  vle32.v   v1,(a0)
  vle32.v   v2,(a1)
  vminu.vv   v0, v1, v2
  vse32.v   v0, (a0)
  sub       t1, t0, t1
  bnez      t1, vminu_vv_e32_m1_512

  
  li        t1, 512
  vmin_vv_e32_m1_512:
  mv        t0, t1
  vsetvli   t1, t0, e32, m1, ta, ma
  vle32.v   v1,(a0)
  vle32.v   v2,(a1)
  vmin.vv   v0, v1, v2
  vse32.v   v0, (a0)
  sub       t1, t0, t1
  bnez      t1, vmin_vv_e32_m1_512

  
  li        t1, 512
  vmaxu_vv_e32_m1_512:
  mv        t0, t1
  vsetvli   t1, t0, e32, m1, ta, ma
  vle32.v   v1,(a0)
  vle32.v   v2,(a1)
  vmaxu.vv   v0, v1, v2
  vse32.v   v0, (a0)
  sub       t1, t0, t1
  bnez      t1, vmaxu_vv_e32_m1_512

  
  li        t1, 512
  vmax_vv_e32_m1_512:
  mv        t0, t1
  vsetvli   t1, t0, e32, m1, ta, ma
  vle32.v   v1,(a0)
  vle32.v   v2,(a1)
  vmax.vv   v0, v1, v2
  vse32.v   v0, (a0)
  sub       t1, t0, t1
  bnez      t1, vmax_vv_e32_m1_512

  
  li        t1, 512
  vmul_vv_e32_m1_512:
  mv        t0, t1
  vsetvli   t1, t0, e32, m1, ta, ma
  vle32.v   v1,(a0)
  vle32.v   v2,(a1)
  vmul.vv   v0, v1, v2
  vse32.v   v0, (a0)
  sub       t1, t0, t1
  bnez      t1, vmul_vv_e32_m1_512

  
  li        t1, 512
  vmulh_vv_e32_m1_512:
  mv        t0, t1
  vsetvli   t1, t0, e32, m1, ta, ma
  vle32.v   v1,(a0)
  vle32.v   v2,(a1)
  vmulh.vv   v0, v1, v2
  vse32.v   v0, (a0)
  sub       t1, t0, t1
  bnez      t1, vmulh_vv_e32_m1_512

  
  li        t1, 512
  vmulhu_vv_e32_m1_512:
  mv        t0, t1
  vsetvli   t1, t0, e32, m1, ta, ma
  vle32.v   v1,(a0)
  vle32.v   v2,(a1)
  vmulhu.vv   v0, v1, v2
  vse32.v   v0, (a0)
  sub       t1, t0, t1
  bnez      t1, vmulhu_vv_e32_m1_512

  
  li        t1, 512
  vmulhsu_vv_e32_m1_512:
  mv        t0, t1
  vsetvli   t1, t0, e32, m1, ta, ma
  vle32.v   v1,(a0)
  vle32.v   v2,(a1)
  vmulhsu.vv   v0, v1, v2
  vse32.v   v0, (a0)
  sub       t1, t0, t1
  bnez      t1, vmulhsu_vv_e32_m1_512

  
  li        t1, 512
  vmacc_vv_e32_m1_512:
  mv        t0, t1
  vsetvli   t1, t0, e32, m1, ta, ma
  vle32.v   v1,(a0)
  vle32.v   v2,(a1)
  vmacc.vv   v0, v1, v2
  vse32.v   v0, (a0)
  sub       t1, t0, t1
  bnez      t1, vmacc_vv_e32_m1_512

  
  li        t1, 512
  vnmsac_vv_e32_m1_512:
  mv        t0, t1
  vsetvli   t1, t0, e32, m1, ta, ma
  vle32.v   v1,(a0)
  vle32.v   v2,(a1)
  vnmsac.vv   v0, v1, v2
  vse32.v   v0, (a0)
  sub       t1, t0, t1
  bnez      t1, vnmsac_vv_e32_m1_512

  
  li        t1, 512
  vmadd_vv_e32_m1_512:
  mv        t0, t1
  vsetvli   t1, t0, e32, m1, ta, ma
  vle32.v   v1,(a0)
  vle32.v   v2,(a1)
  vmadd.vv   v0, v1, v2
  vse32.v   v0, (a0)
  sub       t1, t0, t1
  bnez      t1, vmadd_vv_e32_m1_512

  
  li        t1, 512
  vnmsub_vv_e32_m1_512:
  mv        t0, t1
  vsetvli   t1, t0, e32, m1, ta, ma
  vle32.v   v1,(a0)
  vle32.v   v2,(a1)
  vnmsub.vv   v0, v1, v2
  vse32.v   v0, (a0)
  sub       t1, t0, t1
  bnez      t1, vnmsub_vv_e32_m1_512

  
  li        t1, 512
  vsaddu_vv_e32_m1_512:
  mv        t0, t1
  vsetvli   t1, t0, e32, m1, ta, ma
  vle32.v   v1,(a0)
  vle32.v   v2,(a1)
  vsaddu.vv   v0, v1, v2
  vse32.v   v0, (a0)
  sub       t1, t0, t1
  bnez      t1, vsaddu_vv_e32_m1_512

  
  li        t1, 512
  vsadd_vv_e32_m1_512:
  mv        t0, t1
  vsetvli   t1, t0, e32, m1, ta, ma
  vle32.v   v1,(a0)
  vle32.v   v2,(a1)
  vsadd.vv   v0, v1, v2
  vse32.v   v0, (a0)
  sub       t1, t0, t1
  bnez      t1, vsadd_vv_e32_m1_512

  
  li        t1, 512
  vssubu_vv_e32_m1_512:
  mv        t0, t1
  vsetvli   t1, t0, e32, m1, ta, ma
  vle32.v   v1,(a0)
  vle32.v   v2,(a1)
  vssubu.vv   v0, v1, v2
  vse32.v   v0, (a0)
  sub       t1, t0, t1
  bnez      t1, vssubu_vv_e32_m1_512

  
  li        t1, 512
  vssub_vv_e32_m1_512:
  mv        t0, t1
  vsetvli   t1, t0, e32, m1, ta, ma
  vle32.v   v1,(a0)
  vle32.v   v2,(a1)
  vssub.vv   v0, v1, v2
  vse32.v   v0, (a0)
  sub       t1, t0, t1
  bnez      t1, vssub_vv_e32_m1_512

  
  li        t1, 512
  vaaddu_vv_e32_m1_512:
  mv        t0, t1
  vsetvli   t1, t0, e32, m1, ta, ma
  vle32.v   v1,(a0)
  vle32.v   v2,(a1)
  vaaddu.vv   v0, v1, v2
  vse32.v   v0, (a0)
  sub       t1, t0, t1
  bnez      t1, vaaddu_vv_e32_m1_512

  
  li        t1, 512
  vaadd_vv_e32_m1_512:
  mv        t0, t1
  vsetvli   t1, t0, e32, m1, ta, ma
  vle32.v   v1,(a0)
  vle32.v   v2,(a1)
  vaadd.vv   v0, v1, v2
  vse32.v   v0, (a0)
  sub       t1, t0, t1
  bnez      t1, vaadd_vv_e32_m1_512

  
  li        t1, 512
  vasubu_vv_e32_m1_512:
  mv        t0, t1
  vsetvli   t1, t0, e32, m1, ta, ma
  vle32.v   v1,(a0)
  vle32.v   v2,(a1)
  vasubu.vv   v0, v1, v2
  vse32.v   v0, (a0)
  sub       t1, t0, t1
  bnez      t1, vasubu_vv_e32_m1_512

  
  li        t1, 512
  vasub_vv_e32_m1_512:
  mv        t0, t1
  vsetvli   t1, t0, e32, m1, ta, ma
  vle32.v   v1,(a0)
  vle32.v   v2,(a1)
  vasub.vv   v0, v1, v2
  vse32.v   v0, (a0)
  sub       t1, t0, t1
  bnez      t1, vasub_vv_e32_m1_512

  
  li        t1, 512
  vsmul_vv_e32_m1_512:
  mv        t0, t1
  vsetvli   t1, t0, e32, m1, ta, ma
  vle32.v   v1,(a0)
  vle32.v   v2,(a1)
  vsmul.vv   v0, v1, v2
  vse32.v   v0, (a0)
  sub       t1, t0, t1
  bnez      t1, vsmul_vv_e32_m1_512

  
  li        t1, 512
  vssrl_vv_e32_m1_512:
  mv        t0, t1
  vsetvli   t1, t0, e32, m1, ta, ma
  vle32.v   v1,(a0)
  vle32.v   v2,(a1)
  vssrl.vv   v0, v1, v2
  vse32.v   v0, (a0)
  sub       t1, t0, t1
  bnez      t1, vssrl_vv_e32_m1_512

  
  li        t1, 512
  vssra_vv_e32_m1_512:
  mv        t0, t1
  vsetvli   t1, t0, e32, m1, ta, ma
  vle32.v   v1,(a0)
  vle32.v   v2,(a1)
  vssra.vv   v0, v1, v2
  vse32.v   v0, (a0)
  sub       t1, t0, t1
  bnez      t1, vssra_vv_e32_m1_512

  MATCH_END
  lw            ra,28(sp)
  lw            s0,24(sp)
  addi          sp,sp,32
  RET_INSTR
  .size         main, .-main

  .data
data:
  MEM_WORDS_256
  MEM_WORDS_256
  MEM_WORDS_256
  MEM_WORDS_256

.ident "GCC:
	()            14.2.0"
	.section      .note.GNU-stack,"",@progbits
