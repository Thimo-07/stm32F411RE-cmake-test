cmake_minimum_required(VERSION 3.16.3)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/arm-none-eabi-gcc.cmake)
project(cmake_test VERSION 0.1.0)

set(EXECUTABLE ${PROJECT_NAME}.elf)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build/executables)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/build/executables)
set(LINKER_FILE ${CMAKE_SOURCE_DIR}/drivers/device/STM32F411RETx_FLASH.ld)

enable_language(C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 14)

set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_C_EXTENSIONS ON)
set(CMAKE_CXX_EXTENSIONS ON)

set(compiler_options
    -mcpu=cortex-m4
    -mthumb
    -mfpu=fpv4-sp-d16
    -mfloat-abi=hard
    -Wall
    -O0
    -g3
)

set(linker_options 
    -T${LINKER_FILE}
    -mcpu=cortex-m4
    -mthumb
    -mfpu=fpv4-sp-d16
    -mfloat-abi=hard
    -specs=nano.specs
    --specs=nosys.specs
    -g3
    -lc
    -lm
    -lnosys
    -Wl,-Map=${PROJECT_NAME}.map,--cref
    -Wl,--gc-sections
    -Xlinker -print-memory-usage -Xlinker
)

set(compile_definitions 
    -DEBUG
    -DUSE_HAL_DRIVER
    -DSTM32F411xE
)

message(STATUS "CMAKE_TOOLCHAIN_FILE is: ${CMAKE_TOOLCHAIN_FILE}")

add_subdirectory(drivers)
add_subdirectory(lib)
add_subdirectory(core)

target_compile_definitions(${EXECUTABLE} PRIVATE
    ${compile_definitions}
)

# Compiler options
target_compile_options(${EXECUTABLE} PRIVATE
    ${compiler_options}
)

# Linker options
target_link_options(${EXECUTABLE} PRIVATE
    ${linker_options}
)