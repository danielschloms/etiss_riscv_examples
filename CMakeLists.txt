cmake_minimum_required(VERSION 3.10)

project(riscv_examples LANGUAGES C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)

include(CTest)

SET(VECTOR OFF CACHE BOOL "Compile for RVV")
SET(VERILATOR OFF CACHE BOOL "Compile for Verilator")

if(VERILATOR)
    set(RISCV_ARCH rv32im CACHE STRING "Specify the configuration")
    set(MEM_LATENCY 1 CACHE STRING "Memory latency")
    set(MIN_VLEN 128 CACHE STRING "LLVM Autovectorizer parameter for minimum VLEN in bits")  #Does the same thing as _ZvlXXXb architecture string
    set(MEM_W 32 CACHE STRING "Width of main memory data port in bits")

    option(TRACE        "Enable trace outputs" OFF)
    option(PRINT        "Enable print statements" ON)

    #####
    # Default Paths to Subdirectories
    #####

    set(VICUNA_DIR "$ENV{WS_PATH}/vicuna2_tinyml_benchmarking" CACHE STRING "Vicuna Repository")
    set(BUILD_DIR ${VICUNA_DIR}/build_from_other)
    set(MODEL_DIR ${VICUNA_DIR}/build_model/build)
    set(BENCHMARKS_TOP ${CMAKE_CURRENT_SOURCE_DIR}/target_code/vector)
    set(BSP_TOP ${CMAKE_CURRENT_SOURCE_DIR}/verilator_bsp)

    #These control benchmark configurations specific to the selected RISCV_ARCH
    # option(RISCV_F "Use the RISC-V F Extension" OFF)
    # option(RISCV_ZFH "Use the RISC-V ZFH Extension" OFF)
    # option(RISCV_ZVE32X "Use the RISC-V Embedded V Extension" OFF)
    # option(RISCV_ZVE32F "Use the RISC-V Embedded V Float Extension" OFF)
    # option(RISCV_ZVHF "Use the RISC-V V Half Float Extension" OFF)

    # set(AUTOVEC_FLAGS "")

    # if(${RISCV_ARCH} STREQUAL "rv32im") 
    #     set(RISCV_ABI ilp32)
    #     option(FH_OPS      "Use FP16 for intermediate operations (no conversion to float)"  OFF)
        
    # elseif(${RISCV_ARCH} STREQUAL "rv32im_zicsr")
    #     set(RISCV_ABI ilp32)  
    #     option(FH_OPS      "Use FP16 for intermediate operations (no conversion to float)"  OFF)

    # elseif(${RISCV_ARCH} STREQUAL "rv32imf")
    #     set(RISCV_ABI ilp32f)  
    #     set(RISCV_F ON)
    #     option(FH_OPS      "Use FP16 for intermediate operations (no conversion to float)"  OFF)
        
    # elseif(${RISCV_ARCH} STREQUAL "rv32imf_zfh")
    #     set(RISCV_ABI ilp32f)  
    #     set(RISCV_F ON)
    #     set(RISCV_ZFH ON)
    #     option(FH_OPS      "Use FP16 for intermediate operations (no conversion to float)"  ON)
        
    # elseif(${RISCV_ARCH} STREQUAL "rv32im_zve32x")
    #     set(RISCV_ABI ilp32) 
    #     set(RISCV_ZVE32X ON)
    #     set(AUTOVEC_FLAGS "-fvectorize -fslp-vectorize -mllvm -scalable-vectorization=on -mllvm --riscv-v-vector-bits-min=${MIN_VLEN}")
    #     option(FH_OPS      "Use FP16 for intermediate operations (no conversion to float)"  OFF)
        
    # elseif(${RISCV_ARCH} STREQUAL "rv32imf_zve32f")
    #     set(RISCV_ABI ilp32f) 
    #     set(RISCV_ZVE32X ON)
    #     set(RISCV_ZVE32F ON)
    #     set(RISCV_F ON)
    #     set(AUTOVEC_FLAGS "-fvectorize -fslp-vectorize -mllvm -scalable-vectorization=preferred -mllvm --riscv-v-vector-bits-min=${MIN_VLEN}")
    #     option(FH_OPS      "Use FP16 for intermediate operations (no conversion to float)"  OFF)
        
    # elseif(${RISCV_ARCH} STREQUAL "rv32imf_zfh_zve32f_zvfh")
    #     set(RISCV_ABI ilp32f) 
    #     set(RISCV_ZVE32X ON)
    #     set(RISCV_ZVE32F ON)
    #     set(RISCV_ZFH ON)
    #     set(RISCV_F ON)
    #     set(RISCV_ZVFH ON)
    #     set(AUTOVEC_FLAGS "-fvectorize -fslp-vectorize -mllvm -scalable-vectorization=preferred -mllvm --riscv-v-vector-bits-min=${MIN_VLEN}")
    #     option(FH_OPS      "Use FP16 for intermediate operations (no conversion to float)"  ON)
        

    # else()
    #     message(FATAL_ERROR "Unsupported RISCV_ARCH selected")
        
    # endif()

    set(RISCV_CMODEL "medany" CACHE STRING "mcmodel argument to the compiler")
    # Tell CMake about our processor
    set(CMAKE_SYSTEM_PROCESSOR ${RISCV_ARCH})
    # The Generic system name is used for bare-metal targets (without OS) in CMake
    set(CMAKE_SYSTEM_NAME Generic)
    message("TOOLCHAIN PATH ${CMAKE_CURRENT_SOURCE_DIR}/toolchain_files/gcc-toolchain.cmake")
    set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/toolchain_files/gcc-toolchain.cmake")
    ####
    # Set build mode, Release by default
    ####
    if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE RELEASE)
    endif()

    if(PRINT)
    add_definitions(-DPRINT_OUTPUTS)
    endif()

    # See whats going in CMake while getting the build process up and running
    # set(CMAKE_VERBOSE_MAKEFILE ON)

    set(CMAKE_EXECUTABLE_SUFFIX_C .elf)
    set(CMAKE_EXECUTABLE_SUFFIX_CXX .elf)
    set(CMAKE_EXECUTABLE_SUFFIX_ASM .elf) 
    set(CMAKE_EXECUTABLE_SUFFIX ".elf") #For some reason setting this works for ASM files but SUFFIX_ASM doesnt

    set(CMAKE_C_STANDARD 11)
    set(CMAKE_CXX_STANDARD 11)

    add_subdirectory(./target_code/vector vector)
    add_subdirectory(./verilator_bsp verilator_bsp)

    # set(BSP_TOP ${CMAKE_CURRENT_SOURCE_DIR}/verilator_bsp)
    # set(VERILATOR_LDSCRIPT ${CMAKE_CURRENT_SOURCE_DIR}/verilator_bsp/lld_link.ld)
    # # set(VERILATOR_LDSCRIPT ${CMAKE_CURRENT_BINARY_DIR}/verilator.ld)
    # include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/verilator.cmake)
    # add_subdirectory(target_code)
    # add_subdirectory(verilator_bsp)

else()

    set(MEM_ROM_ORIGIN 0x10000000)
    set(MEM_ROM_LENGTH 0x00400000)
    set(MEM_RAM_ORIGIN 0x20000000)
    set(MEM_RAM_LENGTH 0x00100000)
    set(MIN_STACK_SIZE 0x1000)
    set(MIN_HEAP_SIZE 0x1000)
    configure_file(etiss.ld.in etiss.ld @ONLY)
    configure_file(memsegs.ini.in memsegs.ini @ONLY)
    set(ETISS_LDSCRIPT ${CMAKE_CURRENT_BINARY_DIR}/etiss.ld)
    set(ETISS_LDFLAGS "-L${CMAKE_CURRENT_BINARY_DIR}/riscv_crt0 --specs=${CMAKE_CURRENT_SOURCE_DIR}/etiss-semihost.specs -T ${ETISS_LDSCRIPT}")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${ETISS_LDFLAGS}")
    set(ETISS_ELFINI ${CMAKE_CURRENT_SOURCE_DIR}/elffile.ini.in)
    add_subdirectory(riscv_crt0)
    add_subdirectory(target_code)
endif()


