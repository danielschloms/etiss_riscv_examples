#pragma once

#ifdef __cplusplus
#ifdef VERILATOR
inline void *__dso_handle = (void *)&__dso_handle;
#endif
extern "C" {
#endif

#define MATCH_BEGIN_DEF                                                        \
  int __attribute__((noinline)) address_match_start() { return 1; }
#define MATCH_END_DEF                                                          \
  int __attribute__((noinline)) address_match_end() { return 2; }
#define MATCH_BEGIN int hello = address_match_start()
#define MATCH_END int bye = address_match_end()

#ifdef VERILATOR

static inline void terminate_success() {
  __asm__ volatile(
      "jalr x0, 124(x0)"); // jump to 0x7c to signal success (Custom use
                           // interrupt, will not be called). Jumps to these
                           // addresses are handled by verilator_main.cpp
}

static inline void terminate_failure() {
  __asm__ volatile(
      "jalr x0, 120(x0)"); // jump to 0x78 to signal failure caused by
                           // mismatched test output  Other interrupts are
                           // caught by 0x74 to signal a problem
}

#define EXIT_SIM_SUCCESS                                                       \
  terminate_success();                                                         \
  return hello + bye;

#define EXIT_SIM_FAILURE                                                       \
  terminate_failure();                                                         \
  return hello + bye;

#else
#include <stdio.h>
#define EXIT_SIM_SUCCESS                                                       \
  printf("Success\n");                                                         \
  return hello + bye;

#define EXIT_SIM_FAILURE                                                       \
  printf("Fail\n");                                                            \
  return hello + bye;

#endif

#ifdef __cplusplus
}
#endif