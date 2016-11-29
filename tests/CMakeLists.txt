function(add_unit_test test_name)
    add_executable(${test_name} ${test_name}.c)
    target_link_libraries(${test_name} safe-c criterion)
    add_test(${test_name} ${test_name})
endfunction(add_unit_test)

if(${CMAKE_C_COMPILER_ID} STREQUAL GNU OR
    ${CMAKE_C_COMPILER_ID} STREQUAL Clang)
    string(REPLACE "-Wconversion" "" FLAGS_WITHOUT_CONVSERION_WARNING ${CMAKE_C_FLAGS})
    set(CMAKE_C_FLAGS ${FLAGS_WITHOUT_CONVSERION_WARNING})
endif()

add_subdirectory(safe_memory)
add_subdirectory(safe_string)
