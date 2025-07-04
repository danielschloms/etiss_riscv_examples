macro(add_executable_etiss TARGET)
	set(SRC_FILES "${ARGN}")

	add_executable(${TARGET} ${SRC_FILES})
	add_dependencies(${TARGET} etiss_crt0)

	target_include_directories(
        ${TARGET} PRIVATE ${CMAKE_SOURCE_DIR}/riscv_crt0
        ${PROJECT_SOURCE_DIR}/target_code/librvv)

    target_link_libraries(${TARGET} PRIVATE librvv)
	set(BIN_NAME ${TARGET})

	configure_file(${ETISS_ELFINI} ${TARGET}.ini @ONLY)

	install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${TARGET}.ini DESTINATION ini)
	install(TARGETS ${TARGET} DESTINATION bin)
endmacro()

macro(add_ml_executable TARGET SOURCE_DIR)

    set(BIN_NAME ${TARGET})
    configure_file(${ETISS_ELFINI} ${TARGET}.ini @ONLY)
    add_executable(${BIN_NAME})
    add_dependencies(${TARGET} etiss_crt0)
    target_include_directories(${TARGET} PRIVATE ${CMAKE_SOURCE_DIR}/riscv_crt0)

    target_include_directories(${BIN_NAME} PRIVATE
        ${SOURCE_DIR}
        ${SOURCE_DIR}/model_data
        ${PERFSIM_INCLUDE}
    )

    target_sources(${BIN_NAME} PUBLIC
        ${SOURCE_DIR}/${TARGET}.cpp
        ${SOURCE_DIR}/${TARGET}_data/${TARGET}_input_data.cc
        ${SOURCE_DIR}/${TARGET}_data/${TARGET}_input_data.h
        ${SOURCE_DIR}/${TARGET}_data/${TARGET}_model_data.cc
        ${SOURCE_DIR}/${TARGET}_data/${TARGET}_model_data.h
        ${SOURCE_DIR}/${TARGET}_data/${TARGET}_model_settings.cc
        ${SOURCE_DIR}/${TARGET}_data/${TARGET}_model_settings.h
        ${SOURCE_DIR}/${TARGET}_data/${TARGET}_output_data_ref.cc
        ${SOURCE_DIR}/${TARGET}_data/${TARGET}_output_data_ref.h
    )

    target_link_libraries(${BIN_NAME} PRIVATE tflm)

    install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${TARGET}.ini DESTINATION ini)
	install(TARGETS ${TARGET} DESTINATION bin)

endmacro()

# add_subdirectory(hello_world)
# add_subdirectory(test_cases)
# add_subdirectory(interactive)
# add_subdirectory(semihosting_cpp)
# add_subdirectory(cpp)
# add_subdirectory(dhry)
# add_subdirectory(c)

SET(ML OFF CACHE BOOL "Compile ML programs.")

if (VECTOR)
	message("Compiling Vector Programs.")
	add_subdirectory(vector)
    # add_subdirectory(cpp)
    # add_subdirectory(vbench)
    # add_subdirectory(dhry)
    if (ML)
        add_subdirectory(ml_bench)
    endif()
else()
	message("Compiling Scalar Programs.")
	# add_subdirectory(scalar)
    # if (ML)
    #     add_subdirectory(ml_bench)
    # endif()
endif()

# add_subdirectory(vbench)
