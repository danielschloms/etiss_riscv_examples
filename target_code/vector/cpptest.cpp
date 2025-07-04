#include "perfsim.h"
#include <array>
#include <cstdint>
#include <rvv.h>

extern "C" {
MATCH_BEGIN_DEF
MATCH_END_DEF
}

int main() {
  MATCH_BEGIN;
  auto a = std::array<int32_t, 10>({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
  auto b = std::array<int32_t, 10>({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
  auto result = std::array<int32_t, a.size()>{0};
  vadd_vv_i32m1(a.data(), b.data(), result.data(), a.size());
  MATCH_END;
  EXIT_SIM_SUCCESS;
}
