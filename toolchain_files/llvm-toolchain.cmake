cmake_minimum_required(VERSION 3.10)

set(RISCV_GCC_PREFIX "$ENV{RISCV_NO_MLIB}/${RISCV_ARCH}")
set(RISCV_GCC_BASENAME "riscv32-unknown-elf")

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)

set(CMAKE_C_COMPILER clang-18)
set(CMAKE_CXX_COMPILER clang-18)
set(CMAKE_ASM_COMPILER clang-18)
set(CMAKE_OBJCOPY llvm-objcopy-18)
set(CMAKE_OBJDUMP llvm-objdump-18)

set(RISCV_CMODEL "medany")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --target=riscv32 -march=${RISCV_ARCH}${RISCV_ARCH_VL} -mabi=${RISCV_ABI} -mcmodel=${RISCV_CMODEL}")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --gcc-toolchain=${RISCV_GCC_PREFIX} --sysroot=${RISCV_GCC_PREFIX}/${RISCV_GCC_BASENAME}")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --target=riscv32 -march=${RISCV_ARCH}${RISCV_ARCH_VL} -mabi=${RISCV_ABI} -mcmodel=${RISCV_CMODEL}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --gcc-toolchain=${RISCV_GCC_PREFIX} --sysroot=${RISCV_GCC_PREFIX}/${RISCV_GCC_BASENAME}")
set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} --target=riscv32 -march=${RISCV_ARCH}${RISCV_ARCH_VL} -mabi=${RISCV_ABI} -mcmodel=${RISCV_CMODEL}")
set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} --gcc-toolchain=${RISCV_GCC_PREFIX} --sysroot=${RISCV_GCC_PREFIX}/${RISCV_GCC_BASENAME}")

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -march=${RISCV_ARCH}${RISCV_ARCH_VL} -mabi=${RISCV_ABI} --ld-path=$ENV{RISCV_NO_MLIB}/${RISCV_ARCH}/bin/riscv32-unknown-elf-ld -mcmodel=${RISCV_CMODEL}")
# set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -march=${RISCV_ARCH}${RISCV_ARCH_VL} -mabi=${RISCV_ABI} -fuse-ld=lld -mcmodel=${RISCV_CMODEL} -nostartfiles")

set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O3 -g -ggdb ${AUTOVEC_FLAGS}")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O3 -g -ggdb ${AUTOVEC_FLAGS}")
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -O3 ${AUTOVEC_FLAGS}")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 ${AUTOVEC_FLAGS}")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Wshadow -Wno-format -std=c11 ${AUTOVEC_FLAGS}") 
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11 ${AUTOVEC_FLAGS}")


# set(RISCV_ARCH "rv32im" CACHE STRING "RISC-V architecture (-march)")
# set(RISCV_ABI "ilp32" CACHE STRING "RISC-V ABI (-mabi)")

# set(RISCV_TOOLCHAIN_PREFIX "" CACHE STRING "optional prefix for the riscv toolchain in case it is not on the path")
# set(RISCV_TOOLCHAIN_BASENAME "riscv32-unknown-elf" CACHE STRING "base name of the toolchain executables")


# if("${RISCV_TOOLCHAIN_PREFIX}" STREQUAL "")
#     set(RISCV_TOOLCHAIN "${RISCV_TOOLCHAIN_BASENAME}")
# else()
#     set(RISCV_TOOLCHAIN "${RISCV_TOOLCHAIN_PREFIX}/bin/${RISCV_TOOLCHAIN_BASENAME}")
# endif()

# set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D__riscv__ -march=${RISCV_ARCH} -mabi=${RISCV_ABI}")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D__riscv__ -march=${RISCV_ARCH} -mabi=${RISCV_ABI}")
# set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -D__riscv__ -march=${RISCV_ARCH} -mabi=${RISCV_ABI}")
# set(CMAKE_EXE_LINKER_FLAGS "-march=${RISCV_ARCH} -mabi=${RISCV_ABI}")


set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR ${RISCV_ARCH})
