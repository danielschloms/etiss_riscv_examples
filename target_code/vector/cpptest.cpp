#include "perfsim.h"
#include "rvv.h"
#include <array>
#include <cstdint>
#include <cstddef>

extern "C" {
MATCH_BEGIN_DEF
MATCH_END_DEF
}

int main() {
  MATCH_BEGIN;
  volatile int a = 10;
  MATCH_END;
  EXIT_SIM_SUCCESS;
}
