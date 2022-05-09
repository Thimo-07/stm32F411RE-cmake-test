add_library(
    lib_includes STATIC
    main.hpp
)

set_target_properties(lib_includes PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(lib_includes PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

