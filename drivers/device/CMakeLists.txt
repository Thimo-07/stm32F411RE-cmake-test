add_library(lib_device STATIC
        startup_stm32f411xe.s
        system_stm32f4xx.c
        STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim.c
        STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim_ex.c
        STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_uart.c
        STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.c
        STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc_ex.c
        STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash.c
        STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ex.c
        STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ramfunc.c
        STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.c
        STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma_ex.c
        STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma.c
        STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr.c
        STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr_ex.c
        STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.c
        STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.c
        STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_exti.c
)

target_include_directories(lib_device PUBLIC 
        "${CMAKE_CURRENT_SOURCE_DIR}"
        STM32F4xx_HAL_Driver/Inc
        STM32F4xx_HAL_Driver/Inc/legacy
        STM32F4xx_HAL_Driver/Inc/config
        ../CMSIS
)

target_link_libraries(lib_device PRIVATE 
        lib_CMSIS
)

target_compile_definitions(lib_device PRIVATE
        ${compile_definitions}
)

# Compiler options
target_compile_options(lib_device PRIVATE
        ${compiler_options}
)

# Linker options
target_link_options(lib_device PRIVATE
        ${linker_options}
)