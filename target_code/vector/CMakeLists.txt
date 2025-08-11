if (VERILATOR)
    set(SRC "${CMAKE_CURRENT_SOURCE_DIR}")
    add_executable_verilator(basic_asm ${SRC} ${BUILD_DIR}/vector ${SRC}/basic_asm.S)
    add_executable_verilator(cpptest ${SRC} ${BUILD_DIR}/vector ${SRC}/cpptest.cpp)
    add_executable_verilator(rvv_asm_bench ${SRC} ${BUILD_DIR}/vector ${SRC}/rvv_asm_bench.S)

    add_executable_verilator(instrs ${SRC} ${BUILD_DIR}/vector ${SRC}/instr_rvv/main.c ${SRC}/instr_rvv/bench.S)
    target_compile_definitions(instrs PRIVATE SKIP_FENCEI)

    # Needs librvv
    add_executable_verilator(rvvbench ${SRC} ${BUILD_DIR}/vector ${SRC}/rvvbench.cpp)
    target_link_libraries(rvvbench PRIVATE librvv)
else()
    add_executable_etiss(basic_asm basic_asm.S)
    add_executable_etiss(cpptest cpptest.cpp)
    add_executable_etiss(rvv_asm_bench rvv_asm_bench.S)
    
    add_executable_etiss(instrs instr_rvv/main.c instr_rvv/bench.S)
    target_compile_definitions(instrs PRIVATE SKIP_FENCEI)

    # Needs librvv
    add_executable_etiss(rvvbench rvvbench.cpp)
    target_link_libraries(rvvbench PRIVATE librvv)
endif()
