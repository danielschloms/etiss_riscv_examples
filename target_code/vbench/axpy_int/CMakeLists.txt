add_executable_etiss(axpy_v 
src/main.c 
src/axpy.c
src/utils.c)

target_compile_definitions(axpy_v PRIVATE USE_RISCV_VECTOR)

add_executable_etiss(axpy_s 
src/main.c 
src/axpy.c
src/utils.c)
