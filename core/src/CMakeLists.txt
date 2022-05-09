add_executable(${EXECUTABLE}
                main.cpp
                stm32f4xx_it.c
)             

target_link_libraries(${EXECUTABLE} PUBLIC lib_device)
target_link_libraries(${EXECUTABLE} PUBLIC lib_includes)

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