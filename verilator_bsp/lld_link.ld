/* Copyright TU Wien                                                               */
/* Licensed under the Solderpad Hardware License v2.1, see LICENSE.txt for details */
/* SPDX-License-Identifier: Apache-2.0 WITH SHL-2.1                                */


OUTPUT_ARCH(riscv)
ENTRY(_start)

SEARCH_DIR(.)
__DYNAMIC = 0;

MEMORY
{

    /* 
    MEM_ROM_ORIGIN = 0x10000000
    MEM_ROM_LENGTH = 0x00400000
    MEM_RAM_ORIGIN = 0x20000000
    MEM_RAM_LENGTH = 0x00200000
    MIN_STACK_SIZE = 0x1000
    MIN_HEAP_SIZE  = 0x1000 
    */
    
    BOOT : ORIGIN = 0x00000000, LENGTH = 0x00002000
    ROM  : ORIGIN = 0x10000000, LENGTH = 0x00400000
    RAM  : ORIGIN = 0x20000000, LENGTH = 0x00200000
}

STACK_LEN = 0x1000; /* 4 kB */
/* STACK_LEN = 0x4000; /* 16 kB */

__stack_size     = 0x1000;
__heap_size      = 0x1000;

SECTIONS
{

    /* --- BOOT --- */
    .vectors 0 : {
        *(.vectors)
    } > BOOT

  /* ================ ROM ================ */

  .text : {
    *(.text .text.* )
  }  > ROM

  .rodata : {
    *(.rodata .rodata.*)
  } > ROM
  .srodata : {
    *(.srodata .srodata.*)
  } > ROM



  /* ================ RAM ================ */

  .init_array : {
    PROVIDE_HIDDEN (__init_array_start = .);
    KEEP (*(.init_array .init_array.*))
    PROVIDE_HIDDEN (__init_array_end = .);
  } > RAM
  .fini_array : {
    PROVIDE_HIDDEN (__fini_array_start = .);
    KEEP (*(.fini_array .fini_array.*))
    PROVIDE_HIDDEN (__fini_array_end = .);
  } > RAM

  .gcc_except_table : {
    *(.gcc_except_table .gcc_except_table.*)
  } > RAM

  .eh_frame : {
    KEEP (*(.eh_frame))
  } > RAM

  __data_start = .;
  .data : {
      *(.data .data.*)
  } > RAM
  __sdata_start = .;
  .sdata : {
      *(.sdata .sdata.*)
  } > RAM

  _bss_start = .;
  .sbss : {
      *(.sbss .sbss.*)
  } > RAM
  .bss : {
      *(.bss .bss.*)
  } > RAM
  _bss_end = .;

  /* do not place anything after this address, because the heap starts here! */

  /* point the global pointer so it can access sdata, sbss, data and bss */
  __global_pointer$ = MIN(__sdata_start + 0x800, MAX(__data_start + 0x800, _bss_end - 0x800));

  /* stack pointer starts at the top of the ram */
  _stack = ORIGIN(RAM) + LENGTH(RAM);
  .stack : {
    ASSERT ((_stack > (_bss_end + __heap_size + __stack_size)), "Error: RAM too small for heap and stack");
  } > RAM
}
