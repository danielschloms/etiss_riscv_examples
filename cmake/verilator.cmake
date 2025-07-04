#######
# Macro for adding a tinyml benchmark to CTest
#######

macro(add_ml_bin_rtl TEST SOURCE_DIR TEST_BUILD_DIR)

    set(TEST_NAME ${TEST}) #need to add a suffix, ctest doesn't allow 'test' as a test name
    
    add_executable(${TEST_NAME})

    target_include_directories(${TEST_NAME} PRIVATE
        ${SOURCE_DIR}
        ${SOURCE_DIR}/model_data
        ${PERFSIM_INCLUDE}
    )

    target_compile_definitions(${TEST_NAME} PRIVATE VERILATOR)

    target_sources(${TEST_NAME} PUBLIC
        ${SOURCE_DIR}/${TEST}.cpp
        ${SOURCE_DIR}/${TEST}_data/${TEST}_input_data.cc
        ${SOURCE_DIR}/${TEST}_data/${TEST}_input_data.h
        ${SOURCE_DIR}/${TEST}_data/${TEST}_model_data.cc
        ${SOURCE_DIR}/${TEST}_data/${TEST}_model_data.h
        ${SOURCE_DIR}/${TEST}_data/${TEST}_model_settings.cc
        ${SOURCE_DIR}/${TEST}_data/${TEST}_model_settings.h
        ${SOURCE_DIR}/${TEST}_data/${TEST}_output_data_ref.cc
        ${SOURCE_DIR}/${TEST}_data/${TEST}_output_data_ref.h
    )

    #Set Linker
    message("LINKFILE ${BSP_TOP}/lld_link.ld")
    target_link_options(${TEST_NAME} PRIVATE "-nostartfiles")
    target_link_options(${TEST_NAME} PRIVATE "-T${BSP_TOP}/lld_link.ld")
    # target_link_options(${TEST_NAME} PRIVATE "-T${VERILATOR_LDSCRIPT}")


    #Link BSP
    target_link_libraries(${TEST_NAME} PUBLIC bsp_Vicuna UART_Vicuna tflm)

    add_custom_command(TARGET ${TEST_NAME}
                       POST_BUILD
                       COMMAND ${CMAKE_OBJCOPY} -O binary ${TEST_NAME}.elf ${TEST_NAME}.bin
                       COMMAND srec_cat ${TEST_NAME}.bin -binary -offset 0x0000 -byte-swap 4 -o ${TEST_NAME}.vmem -vmem
                       COMMAND rm -f prog_${TEST_NAME}.txt
                       COMMAND echo -n "${TEST_BUILD_DIR}/${TEST_NAME}.vmem ${TEST_BUILD_DIR}/${TEST_NAME}_unused.txt " > prog_${TEST_NAME}.txt
                       COMMAND readelf -s ${TEST_NAME}.elf | sed '2,13 s/ //1' | grep vref_start | cut -d " " -f 6 | tr [=["\n"]=] " " >> prog_${TEST_NAME}.txt
                       COMMAND readelf -s ${TEST_NAME}.elf | sed '2,13 s/ //1' | grep vref_end | cut -d " " -f 6 | tr [=["\n"]=] " " >> prog_${TEST_NAME}.txt
                       COMMAND echo -n "${TEST_BUILD_DIR}/${TEST_NAME}_vicuna_sim_out.txt " >> prog_${TEST_NAME}.txt
                       COMMAND readelf -s ${TEST_NAME}.elf | sed '2,13 s/ //1' | grep vdata_start | cut -d " " -f 6 | tr [=["\n"]=] " " >> prog_${TEST_NAME}.txt
                       COMMAND readelf -s ${TEST_NAME}.elf | sed '2,13 s/ //1' | grep vdata_end | cut -d " " -f 6 | tr [=["\n"]=] " " >> prog_${TEST_NAME}.txt
                       COMMAND ${CMAKE_OBJDUMP} -D ${TEST_NAME}.elf > ${TEST_NAME}_dump.txt
                       )

    message(STATUS "Successfully added ${TEST_NAME}")

endmacro()

macro(add_bin TEST SOURCE_DIR TEST_BUILD_DIR TYPE)

    set(TEST_NAME ${TEST}) #need to add a suffix, ctest doesn't allow 'test' as a test name
    
    add_executable(${TEST_NAME})

    target_include_directories(${TEST_NAME} PRIVATE
        ${SOURCE_DIR}
        ${PROJECT_SOURCE_DIR}/target_code/perfsim
        ${PROJECT_SOURCE_DIR}/target_code/librvv
    )

    target_compile_definitions(${TEST_NAME} PRIVATE VERILATOR)

    target_sources(${TEST_NAME} PUBLIC
        ${SOURCE_DIR}/${TEST}.${TYPE}
    )

    #Set Linker
    target_link_options(${TEST_NAME} PRIVATE "-nostartfiles")
    target_link_options(${TEST_NAME} PRIVATE "-T${BSP_TOP}/lld_link.ld")
    # target_link_options(${TEST_NAME} PRIVATE "-T${VERILATOR_LDSCRIPT}")


    #Link BSP
    target_link_libraries(${TEST_NAME} PRIVATE bsp_Vicuna UART_Vicuna librvv)

    add_custom_command(TARGET ${TEST_NAME}
                       POST_BUILD
                       COMMAND ${CMAKE_OBJCOPY} -O binary ${TEST_NAME}.elf ${TEST_NAME}.bin
                       COMMAND srec_cat ${TEST_NAME}.bin -binary -offset 0x0000 -byte-swap 4 -o ${TEST_NAME}.vmem -vmem
                       COMMAND rm -f prog_${TEST_NAME}.txt
                       COMMAND echo -n "${TEST_BUILD_DIR}/${TEST_NAME}.vmem ${TEST_BUILD_DIR}/${TEST_NAME}_unused.txt " > prog_${TEST_NAME}.txt
                       COMMAND readelf -s ${TEST_NAME}.elf | sed '2,13 s/ //1' | grep vref_start | cut -d " " -f 6 | tr [=["\n"]=] " " >> prog_${TEST_NAME}.txt
                       COMMAND readelf -s ${TEST_NAME}.elf | sed '2,13 s/ //1' | grep vref_end | cut -d " " -f 6 | tr [=["\n"]=] " " >> prog_${TEST_NAME}.txt
                       COMMAND echo -n "${TEST_BUILD_DIR}/${TEST_NAME}_vicuna_sim_out.txt " >> prog_${TEST_NAME}.txt
                       COMMAND readelf -s ${TEST_NAME}.elf | sed '2,13 s/ //1' | grep vdata_start | cut -d " " -f 6 | tr [=["\n"]=] " " >> prog_${TEST_NAME}.txt
                       COMMAND readelf -s ${TEST_NAME}.elf | sed '2,13 s/ //1' | grep vdata_end | cut -d " " -f 6 | tr [=["\n"]=] " " >> prog_${TEST_NAME}.txt
                       COMMAND ${CMAKE_OBJDUMP} -D ${TEST_NAME}.elf > ${TEST_NAME}_dump.txt
                       )

    message(STATUS "Successfully added ${TEST_NAME}")

endmacro()