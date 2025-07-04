cmake_minimum_required(VERSION 3.10)

project(riscv_examples LANGUAGES C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 20)

SET(VECTOR OFF CACHE BOOL "Compile for RVV")
SET(VERILATOR OFF CACHE BOOL "Compile for Verilator")
SET(PERFSIM_INCLUDE ${PROJECT_SOURCE_DIR}/target_code/perfsim)

SET(EXPORT_COMPILE_COMMANDS On)

add_subdirectory(target_code/librvv)

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

    add_subdirectory(./verilator_bsp verilator_bsp)
    add_subdirectory(./target_code/vector vector)
    if (ML)
        add_subdirectory(./target_code/ml_bench ml_bench)
    endif()

else()

    set(MEM_ROM_ORIGIN 0x10000000)
    set(MEM_ROM_LENGTH 0x00400000)
    set(MEM_RAM_ORIGIN 0x20000000)
    set(MEM_RAM_LENGTH 0x00200000)
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


