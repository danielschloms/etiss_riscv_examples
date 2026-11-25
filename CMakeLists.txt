cmake_minimum_required(VERSION 3.10)

set(CMAKE_SKIP_INSTALL_ALL_DEPENDENCY ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS On)

project(riscv_examples LANGUAGES ASM C CXX)

set(ETISS OFF CACHE BOOL "Compile for ETISS")
set(VICUNA OFF CACHE BOOL "Compile for Vicuna (Verilator)")
set(QEMU OFF CACHE BOOL "Compile for QEMU")
set(ARA OFF CACHE BOOL "Compile for Ara")

set(SCALAR_FLOAT OFF CACHE BOOL "Scalar core has FPU")

# set(MEM_ROM_ORIGIN 0x10000000)
# set(MEM_ROM_LENGTH 0x00400000)
# set(MEM_RAM_ORIGIN 0x20000000)
# set(MEM_RAM_LENGTH 0x00100000)

set(MEM_ROM_ORIGIN 0x00100000)
set(MEM_ROM_LENGTH 0x00400000)
set(MEM_RAM_ORIGIN 0x00600000)
set(MEM_RAM_LENGTH 0x00100000)

set(MIN_STACK_SIZE 0x1000)
set(MIN_HEAP_SIZE 0x1000)

configure_file(memsegs.ini.in memsegs.ini @ONLY)

set(LIBS_DIR "${PROJECT_SOURCE_DIR}/libs")
set(BSPS_DIR "${PROJECT_SOURCE_DIR}/bsps")
set(LINKER_DIR "${PROJECT_SOURCE_DIR}/linker")

# Configure linker scripts
configure_file(${LINKER_DIR}/etiss.ld.in etiss.ld @ONLY)
configure_file(${LINKER_DIR}/vicuna.ld.in vicuna.ld @ONLY)
# configure_file(${LINKER_DIR}/ara.ld.in ara.ld @ONLY)

# Linker scripts
set(ETISS_LDSCRIPT ${CMAKE_CURRENT_BINARY_DIR}/etiss.ld)
set(VICUNA_LDSCRIPT ${CMAKE_CURRENT_BINARY_DIR}/vicuna.ld)
set(ARA_LDSCRIPT ${CMAKE_CURRENT_BINARY_DIR}/ara.ld)

# Linker flags
set(VICUNA_LDFLAGS "-nostartfiles -T ${VICUNA_LDSCRIPT}")
set(ARA_LDFLAGS "-T ${ARA_LDSCRIPT}")
if(CMAKE_CXX_COMPILER_ID MATCHES "(C|c?)lang")
    set(ETISS_LDFLAGS "-nostdlib -lc -lsemihost -lgcc -lstdc++ -L${BSPS_DIR}/bsp_etiss -T ${ETISS_LDSCRIPT}")
else()
    set(ETISS_LDFLAGS "-L${CMAKE_CURRENT_BINARY_DIR}/bsps/bsp_etiss --specs=${CMAKE_CURRENT_SOURCE_DIR}/etiss-semihost.specs -T ${ETISS_LDSCRIPT}")
endif()

if(VICUNA)
    set(LDFLAGS ${VICUNA_LDFLAGS})
elseif(ETISS)
    set(LDFLAGS ${ETISS_LDFLAGS})
elseif(ARA)
    set(LDFLAGS ${ARA_LDFLAGS})
elseif(QEMU)
    set(LDFLAGS "")
else()
    message(FATAL_ERROR "Missing target platform, one of (VICUNA, ETISS, ARA, QEMU) must be ON")
endif()

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${LDFLAGS}")
set(ETISS_ELFINI ${CMAKE_CURRENT_SOURCE_DIR}/elffile.ini.in)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

add_subdirectory(bsps/bsp_etiss)
add_subdirectory(bsps/bsp_vicuna)
add_subdirectory(bsps/bsp_ara)
add_subdirectory(target_code)
