#!/usr/bin/env python3

import pathlib
import math

from test_config import TEST_FUNCS


def clamp(val: int, min_val: int, max_val: int) -> int:
    return max(min_val, min(val, max_val))


def double_lmul(lmul: str) -> str:
    match lmul:
        case "mf8":
            return "mf4"
        case "mf4":
            return "mf2"
        case "mf2":
            return "m1"
        case "m1":
            return "m2"
        case "m2":
            return "m4"
        case "m4":
            return "m8"
        case "m8":
            print("Illegal LMUL doubling (m8)")
            exit(1)
        case _:
            print(f"Invalid LMUl value {lmul}")
            exit(1)


SCRIPT_DIR = pathlib.Path(__file__).parent
HEADER_NAME = "rvv"

TEST_DIR = pathlib.Path(f"{SCRIPT_DIR.parent}/vector")
TEST_NAME = "rvvbench"
TEST_PATH = pathlib.Path(f"{TEST_DIR}/{TEST_NAME}.cpp")

USE_TEST_FUNCS = TEST_FUNCS.keys()

TEST_CONFIG = {
    "modes": ["vv", "vx", "vi"],#, "wvv", "wwv", "wvx", "wwx"],
    "signs": ["i", "u"],
    "lmuls": ["m1", "m2", "m4", "m8"],
    "widths": [8, 16, 32],
    "n_elements": [64],
}

FUNCS = {
    "vadd": {"modes": ["vv", "vi", "vx"], "signs": ["i", "u"]},
    "vsub": {"modes": ["vv", "vx"], "signs": ["i", "u"]},
    "vrsub": {"modes": ["vi", "vx"], "signs": ["i", "u"]},
    "vand": {"modes": ["vv", "vi", "vx"], "signs": ["i", "u"]},
    "vor": {"modes": ["vv", "vi", "vx"], "signs": ["i", "u"]},
    "vxor": {"modes": ["vv", "vi", "vx"], "signs": ["i", "u"]},
    "vmul": {"modes": ["vv", "vx"], "signs": ["i", "u"]},
    "vmulh": {"modes": ["vv", "vx"], "signs": ["i"]},
    "vmulhu": {"modes": ["vv", "vx"], "signs": ["u"]},
}

LEGAL_FRAC_LMULS = {
    8: ["mf8", "mf4", "mf2"],
    16: ["mf4", "mf2"],
    32: ["mf2"],
    64: [],
}


# Mode vv
def int_func_regular_vv_signature(func: str, width: int, lmul: str, sign: str) -> str:
    ctype = "int" if sign == "i" else "uint"
    return f"void {func}_vv_{sign}{width}{lmul}({ctype}{width}_t *a, {ctype}{width}_t *b, {ctype}{width}_t *result, size_t length)"


# Mode wvv
def int_func_widening_vv_signature(func: str, width: int, lmul: str, sign: str) -> str:
    ctype = "int" if sign == "i" else "uint"
    return f"void {func}_vv_{sign}{2 * width}{double_lmul(lmul)}({ctype}{width}_t *a, {ctype}{width}_t *b, {ctype}{2 * width}_t *result, size_t length)"


# Mode wwv
def int_func_widening_wv_signature(func: str, width: int, lmul: str, sign: str) -> str:
    ctype = "int" if sign == "i" else "uint"
    return f"void {func}_wv_{sign}{2 * width}{double_lmul(lmul)}({ctype}{2 * width}_t *a, {ctype}{width}_t *b, {ctype}{2 * width}_t *result, size_t length)"


# Mode vx
def int_func_regular_vx_signature(func: str, width: int, lmul: str, sign: str) -> str:
    ctype = "int" if sign == "i" else "uint"
    return f"void {func}_vx_{sign}{width}{lmul}({ctype}{width}_t *a, {ctype}{width}_t b, {ctype}{width}_t *result, size_t length)"


# Mode wvx
def int_func_widening_vx_signature(func: str, width: int, lmul: str, sign: str) -> str:
    ctype = "int" if sign == "i" else "uint"
    return f"void {func}_vx_{sign}{2 * width}{double_lmul(lmul)}({ctype}{width}_t *a, {ctype}{width}_t b, {ctype}{2 * width}_t *result, size_t length)"


# Mode wwx
def int_func_widening_wx_signature(func: str, width: int, lmul: str, sign: str) -> str:
    ctype = "int" if sign == "i" else "uint"
    return f"void {func}_wx_{sign}{2 * width}{double_lmul(lmul)}({ctype}{2 * width}_t *a, {ctype}{width}_t b, {ctype}{2 * width}_t *result, size_t length)"


# Mode vi
def int_func_regular_vi_signature(func: str, width: int, lmul: str, sign: str) -> str:
    ctype = "int" if sign == "i" else "uint"
    return f"void {func}_vi_{sign}{width}{lmul}({ctype}{width}_t *a, {ctype}{width}_t *result, size_t length)"


def int_func_regular_vv_call(
    func: str, width: int, lmul: str, sign: str, n_elements: int
) -> str:
    return f"{func}_vv_{sign}{width}{lmul}(a_{sign}{width}_{n_elements}.data(), b_{sign}{width}_{n_elements}.data(), result_{sign}{width}_{n_elements}.data(), {n_elements})"


def int_func_widening_vv_call(
    func: str, width: int, lmul: str, sign: str, n_elements: int
) -> str:
    return f"{func}_vv_{sign}{2 * width}{double_lmul(lmul)}(a_{sign}{width}_{n_elements}.data(), b_{sign}{width}_{n_elements}.data(), result_{sign}{2 * width}_{n_elements}.data(), {n_elements})"


def int_func_widening_wv_call(
    func: str, width: int, lmul: str, sign: str, n_elements: int
) -> str:
    return f"{func}_wv_{sign}{2 * width}{double_lmul(lmul)}(a_{sign}{2 * width}_{n_elements}.data(), b_{sign}{width}_{n_elements}.data(), result_{sign}{2 * width}_{n_elements}.data(), {n_elements})"


def int_func_regular_vx_call(
    func: str, width: int, lmul: str, sign: str, n_elements: int
) -> str:
    regval = -5 if sign == "i" else 5
    return f"{func}_vx_{sign}{width}{lmul}(a_{sign}{width}_{n_elements}.data(), {regval}, result_{sign}{width}_{n_elements}.data(), {n_elements})"


def int_func_widening_vx_call(
    func: str, width: int, lmul: str, sign: str, n_elements: int
) -> str:
    regval = -5 if sign == "i" else 5
    return f"{func}_vx_{sign}{2 * width}{double_lmul(lmul)}(a_{sign}{width}_{n_elements}.data(), {regval}, result_{sign}{2 * width}_{n_elements}.data(), {n_elements})"


def int_func_widening_wx_call(
    func: str, width: int, lmul: str, sign: str, n_elements: int
) -> str:
    regval = -5 if sign == "i" else 5
    return f"{func}_wx_{sign}{2 * width}{double_lmul(lmul)}(a_{sign}{2 * width}_{n_elements}.data(), {regval}, result_{sign}{2 * width}_{n_elements}.data(), {n_elements})"


def int_func_regular_vi_call(
    func: str, width: int, lmul: str, sign: str, n_elements: int
) -> str:
    return f"{func}_vi_{sign}{width}{lmul}(a_{sign}{width}_{n_elements}.data(), result_{sign}{width}_{n_elements}.data(), {n_elements})"


def int_func_regular_vv(func: str, width: int, lmul: str, sign: str) -> str:
    ctype = "int" if sign == "i" else "uint"
    return f"""\
{int_func_regular_vv_signature(func, width, lmul, sign)} {{
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, b += avl, result += avl) {{
    avl = __riscv_vsetvl_e{width}{lmul}(vl);
    v{ctype}{width}{lmul}_t va = __riscv_vle{width}_v_{sign}{width}{lmul}(a, avl);
    v{ctype}{width}{lmul}_t vb = __riscv_vle{width}_v_{sign}{width}{lmul}(b, avl);
    __riscv_vse{width}_v_{sign}{width}{lmul}(result, __riscv_{func}_vv_{sign}{width}{lmul}(va, vb, avl), avl);
  }}
  return;
}}\n
"""


def int_func_widening_vv(func: str, width: int, lmul: str, sign: str) -> str:
    ctype = "int" if sign == "i" else "uint"
    return f"""\
{int_func_widening_vv_signature(func, width, lmul, sign)} {{
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, b += avl, result += avl) {{
    avl = __riscv_vsetvl_e{width}{lmul}(vl);
    v{ctype}{width}{lmul}_t va = __riscv_vle{width}_v_{sign}{width}{lmul}(a, avl);
    v{ctype}{width}{lmul}_t vb = __riscv_vle{width}_v_{sign}{width}{lmul}(b, avl);
    __riscv_vse{2 * width}_v_{sign}{2 * width}{double_lmul(lmul)}(result, __riscv_{func}_vv_{sign}{2 * width}{double_lmul(lmul)}(va, vb, avl), avl);
  }}
  return;
}}\n
"""


def int_func_widening_wv(func: str, width: int, lmul: str, sign: str) -> str:
    ctype = "int" if sign == "i" else "uint"
    return f"""\
{int_func_widening_wv_signature(func, width, lmul, sign)} {{
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, b += avl, result += avl) {{
    avl = __riscv_vsetvl_e{width}{lmul}(vl);
    v{ctype}{2 * width}{double_lmul(lmul)}_t va = __riscv_vle{2 * width}_v_{sign}{2 * width}{double_lmul(lmul)}(a, avl);
    v{ctype}{width}{lmul}_t vb = __riscv_vle{width}_v_{sign}{width}{lmul}(b, avl);
    __riscv_vse{2 * width}_v_{sign}{2 * width}{double_lmul(lmul)}(result, __riscv_{func}_wv_{sign}{2 * width}{double_lmul(lmul)}(va, vb, avl), avl);
  }}
  return;
}}\n
"""


def int_func_regular_vx(func: str, width: int, lmul: str, sign: str) -> str:
    ctype = "int" if sign == "i" else "uint"
    return f"""\
{int_func_regular_vx_signature(func, width, lmul, sign)} {{
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, result += avl) {{
    avl = __riscv_vsetvl_e{width}{lmul}(vl);
    v{ctype}{width}{lmul}_t va = __riscv_vle{width}_v_{sign}{width}{lmul}(a, avl);
    __riscv_vse{width}_v_{sign}{width}{lmul}(result, __riscv_{func}_vx_{sign}{width}{lmul}(va, b, avl), avl);
  }}
  return;
}}\n
"""


def int_func_widening_vx(func: str, width: int, lmul: str, sign: str) -> str:
    ctype = "int" if sign == "i" else "uint"
    return f"""\
{int_func_widening_vx_signature(func, width, lmul, sign)} {{
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, result += avl) {{
    avl = __riscv_vsetvl_e{width}{lmul}(vl);
    v{ctype}{width}{lmul}_t va = __riscv_vle{width}_v_{sign}{width}{lmul}(a, avl);
    __riscv_vse{2 * width}_v_{sign}{2 * width}{double_lmul(lmul)}(result, __riscv_{func}_vx_{sign}{2 * width}{double_lmul(lmul)}(va, b, avl), avl);
  }}
  return;
}}\n
"""


def int_func_widening_wx(func: str, width: int, lmul: str, sign: str) -> str:
    ctype = "int" if sign == "i" else "uint"
    return f"""\
{int_func_widening_wx_signature(func, width, lmul, sign)} {{
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, result += avl) {{
    avl = __riscv_vsetvl_e{width}{lmul}(vl);
    v{ctype}{2 * width}{double_lmul(lmul)}_t va = __riscv_vle{2 * width}_v_{sign}{2 * width}{double_lmul(lmul)}(a, avl);
    __riscv_vse{2 * width}_v_{sign}{2 * width}{double_lmul(lmul)}(result, __riscv_{func}_wx_{sign}{2 * width}{double_lmul(lmul)}(va, b, avl), avl);
  }}
  return;
}}\n
"""


def int_func_regular_vi(func: str, width: int, lmul: str, sign: str) -> str:
    ctype = "int" if sign == "i" else "uint"
    return f"""\
{int_func_regular_vi_signature(func, width, lmul, sign)} {{
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, result += avl) {{
    avl = __riscv_vsetvl_e{width}{lmul}(vl);
    v{ctype}{width}{lmul}_t va = __riscv_vle{width}_v_{sign}{width}{lmul}(a, avl);
    v{ctype}{width}{lmul}_t vr;
    __asm__ volatile("{func}.vi %[vd], %[vs2], %2" : [vd]"=vr"(vr) : [vs2]"vr"(va), "K"(10));
    __riscv_vse{width}_v_{sign}{width}{lmul}(result, vr, avl);
  }}
  return;
}}\n
"""


H_START = """\
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>
#include <stdint.h>\n
"""

H_END_EXTERN_C = """\
#ifdef __cplusplus
}
#endif\n
"""

C_INCLUDES = """\
#include "rvv.h"
#include <riscv_vector.h>
#include <stddef.h>
#include <stdint.h>\n
"""

TEST_INCLUDES = """\
#include "perfsim.h"
#include "rvv.h"
#include <array>
#include <cstdint>
#include <cstddef>\n
"""

TEST_MATCH_DEFS = """\
extern "C" {
MATCH_BEGIN_DEF
MATCH_END_DEF
}\n
"""

MODE_FUNCS = {
    "vv": {
        "signature": int_func_regular_vv_signature,
        "func": int_func_regular_vv,
        "call": int_func_regular_vv_call,
    },
    "wvv": {
        "signature": int_func_widening_vv_signature,
        "func": int_func_widening_vv,
        "call": int_func_widening_vv_call,
    },
    "wwv": {
        "signature": int_func_widening_wv_signature,
        "func": int_func_widening_wv,
        "call": int_func_widening_wv_call,
    },
    "vx": {
        "signature": int_func_regular_vx_signature,
        "func": int_func_regular_vx,
        "call": int_func_regular_vx_call,
    },
    "wvx": {
        "signature": int_func_widening_vx_signature,
        "func": int_func_widening_vx,
        "call": int_func_widening_vx_call,
    },
    "wwx": {
        "signature": int_func_widening_wx_signature,
        "func": int_func_widening_wx,
        "call": int_func_widening_wx_call,
    },
    "vi": {
        "signature": int_func_regular_vi_signature,
        "func": int_func_regular_vi,
        "call": int_func_regular_vi_call,
    },
}


def write_lib() -> None:
    with open(f"{SCRIPT_DIR}/{HEADER_NAME}.h", "w", encoding="utf-8") as h_file:
        h_file.write(H_START)

        for func, info in TEST_FUNCS.items():
            h_file.write(f"/* --- {func} --- */\n")
            with open(f"{SCRIPT_DIR}/{func}.c", "w", encoding="utf-8") as c_file:
                c_file.write(C_INCLUDES)
                for sign in info["signs"]:
                    for mode in info["modes"]:
                        for lmul in info["lmuls"]:
                            for width in info["widths"]:
                                h_file.write(
                                    f"{MODE_FUNCS[mode]["signature"](func, width, lmul, sign)};\n"
                                )
                                c_file.write(
                                    MODE_FUNCS[mode]["func"](func, width, lmul, sign)
                                )
                                # if mode == "vv":
                                #     h_file.write(
                                #         f"{int_func_regular_vv_signature(func, width, lmul, sign)};\n"
                                #     )
                                #     c_file.write(
                                #         int_func_regular_vv(func, width, lmul, sign)
                                #     )

                                # if mode == "vx":
                                #     h_file.write(
                                #         f"{int_func_regular_vx_signature(func, width, lmul, sign)};\n"
                                #     )
                                #     c_file.write(
                                #         int_func_regular_vx(func, width, lmul, sign)
                                #     )

                                # if mode == "vi":
                                #     h_file.write(
                                #         f"{int_func_regular_vi_signature(func, width, lmul, sign)};\n"
                                #     )
                                #     c_file.write(
                                #         int_func_regular_vi(func, width, lmul, sign)
                                #     )
                            h_file.write("\n")
                        h_file.write("\n")

        h_file.write(H_END_EXTERN_C)

    with open(f"{SCRIPT_DIR}/CMakeLists.txt", "w", encoding="utf-8") as cmake:
        cmake.write("add_library(librvv STATIC\n")
        sources = "\n".join([f"\t{func}.c" for func in TEST_FUNCS.keys()])
        cmake.write(f"{sources}\n)")


TEST_N_ELEMENTS = [1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024]


def generate_test_arrays(n_elements: int, width: int, sign: str) -> str:
    ctype = "int" if sign == "i" else "uint"
    array_a = [
        (
            str(clamp(-i, -(2 ** (width - 1)), 2 ** (width - 1) - 1))
            if sign == "i"
            else str(min(i, 2**width - 1))
        )
        for i in range(n_elements)
    ]
    array_b = [str(min(2 * i + 3, 2 ** (width - 1) - 1)) for i in range(n_elements)]
    res_str = f"""\
  auto a_{sign}{width}_{n_elements} = std::array<{ctype}{width}_t, {n_elements}>({{{", ".join(array_a)}}});
  auto b_{sign}{width}_{n_elements} = std::array<{ctype}{width}_t, {n_elements}>({{{", ".join(array_b)}}});
  auto result_{sign}{width}_{n_elements} = std::array<{ctype}{width}_t, {n_elements}>{{0}};\n
"""
    return res_str


def write_test() -> None:
    with open(TEST_PATH, "w", encoding="utf-8") as test_file:
        test_file.write(TEST_INCLUDES)
        test_file.write(TEST_MATCH_DEFS)
        test_file.write("auto main() -> int {\n")
        test_file.write("  MATCH_BEGIN;\n")

        for sign in ["i", "u"]:
            for width in [8, 16, 32]:
                for n_elements in TEST_N_ELEMENTS:
                    test_file.write(generate_test_arrays(n_elements, width, sign))

        # for func, info in TEST_FUNCS.items():
        for func in USE_TEST_FUNCS:
            info = TEST_FUNCS[func]
            for sign in info["signs"]:
                if sign not in TEST_CONFIG["signs"]:
                    continue
                for mode in info["modes"]:
                    if mode not in TEST_CONFIG["modes"]:
                        continue
                    for lmul in info["lmuls"]:
                        if lmul not in TEST_CONFIG["lmuls"]:
                            continue
                        for width in info["widths"]:
                            for n_elements in TEST_CONFIG["n_elements"]:
                                test_file.write(
                                    f"  {MODE_FUNCS[mode]["call"](
                                            func, width, lmul, sign, n_elements
                                        )};\n"
                                )
                                # if mode == "vv":
                                #     test_file.write(
                                #         f"  {int_func_regular_vv_call(
                                #             func, width, lmul, sign, n_elements
                                #         )};\n"
                                #     )

                                # if mode == "vx":
                                #     test_file.write(
                                #         f"  {int_func_regular_vx_call(
                                #             func, width, lmul, sign, n_elements
                                #         )};\n"
                                #     )

                                # if mode == "vi":
                                #     test_file.write(
                                #         f"  {int_func_regular_vi_call(
                                #             func, width, lmul, sign, n_elements
                                #         )};\n"
                                #     )

        test_file.write("  MATCH_END;\n")
        test_file.write("  EXIT_SIM_SUCCESS;\n")
        test_file.write("}\n")


def main():
    write_lib()
    write_test()


if __name__ == "__main__":
    main()
