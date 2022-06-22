add_executable(${EXECUTABLE}
                main.cpp
                stm32f4xx_it.c
                logger.cpp
                $<TARGET_OBJECTS:lib_device>
)             

target_include_directories(${EXECUTABLE} PRIVATE
                ../inc
                ../../drivers/device/
                ../../drivers/device/STM32F4xx_HAL_Driver/Inc
                ../../drivers/device/STM32F4xx_HAL_Driver/Inc/legacy
                ../../drivers/device/STM32F4xx_HAL_Driver/Inc/config
                ../../drivers/CMSIS
)

add_custom_command(TARGET ${EXECUTABLE}
POST_BUILD
COMMAND ${CMAKE_OBJCOPY} -O srec --srec-len=64 
        ${EXECUTABLE_OUTPUT_PATH}/${EXECUTABLE} 
        ${EXECUTABLE_OUTPUT_PATH}/${PROJECT_NAME}.s19
COMMAND ${CMAKE_OBJCOPY} -O ihex 
        ${EXECUTABLE_OUTPUT_PATH}/${EXECUTABLE} 
        ${EXECUTABLE_OUTPUT_PATH}/${PROJECT_NAME}.hex
COMMAND ${CMAKE_OBJCOPY} -O binary 
        ${EXECUTABLE_OUTPUT_PATH}/${EXECUTABLE} 
        ${EXECUTABLE_OUTPUT_PATH}/${PROJECT_NAME}.bin
)