#include <array>
extern "C" {
#include "perfsim.h"
// #include <riscv_vector.h>
#ifndef VERILATOR
#include <stdio.h>
#endif

MATCH_BEGIN_DEF
MATCH_END_DEF

int main() {
  MATCH_BEGIN;
  auto arr = std::to_array({1, 2, 3, 4, 5});
  int a = 10;
  for (auto &&el : arr) {
    a += el;
  }
  int b = 20;
  int c = a + b;
#ifndef VERILATOR
  printf("%i bye\n", c);
#endif
  MATCH_END;
  EXIT_SIM_SUCCESS;
}
}