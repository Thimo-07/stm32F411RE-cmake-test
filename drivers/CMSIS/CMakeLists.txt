add_library(
    lib_CMSIS STATIC
    arm_common_tables.h
    arm_const_structs.h
    arm_math.h
    cmsis_armcc_V6.h
    cmsis_armcc.h
    cmsis_gcc.h
    core_cm0.h
    core_cm0plus.h
    core_cm3.h
    core_cm4.h
    core_cm7.h
    core_cmFunc.h
    core_cmInstr.h
    core_cmSimd.h
    core_sc000.h
    core_sc300.h
)

set_target_properties(lib_CMSIS PROPERTIES LINKER_LANGUAGE C)

target_include_directories(lib_CMSIS PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

target_compile_definitions(lib_CMSIS PRIVATE
        ${compile_definitions}
)

# Compiler options
target_compile_options(lib_CMSIS PRIVATE
    ${compiler_options}
)

# Linker options
target_link_options(lib_CMSIS PRIVATE
    ${linker_options}
)