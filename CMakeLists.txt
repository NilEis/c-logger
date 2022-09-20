cmake_minimum_required(VERSION 3.0.0)
project(c-logger VERSION 0.1.0 LANGUAGES C)
find_package(Doxygen)

add_subdirectory(extern/terminal)

add_library(c_logger src/main.c)
add_library(c_logger_static STATIC src/main.c)

set_target_properties(c_logger PROPERTIES C_STANDARD 11 C_STANDARD_REQUIRED True C_EXTENSIONS Off)
set_target_properties(c_logger_static PROPERTIES C_STANDARD 11 C_STANDARD_REQUIRED True C_EXTENSIONS Off)

target_compile_options(c_logger PRIVATE $<$<OR:$<C_COMPILER_ID:Clang>,$<C_COMPILER_ID:AppleClang>,$<C_COMPILER_ID:GNU>>:-Werror -Wall -Wextra -Wconversion -Wsign-conversion>$<$<C_COMPILER_ID:MSVC>:/W4>)
target_compile_options(c_logger_static PRIVATE $<$<OR:$<C_COMPILER_ID:Clang>,$<C_COMPILER_ID:AppleClang>,$<C_COMPILER_ID:GNU>>:-Werror -Wall -Wextra -Wconversion -Wsign-conversion>$<$<C_COMPILER_ID:MSVC>:/W4>)

OPTION(BUILD_WITH_DOCS "Generate Docs" OFF)
OPTION(BUILD_EXAMPLE_LOG "Build example program" OFF)

target_include_directories(c_logger PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(c_logger_static PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(c_logger c_terminal)
target_link_libraries(c_logger_static c_terminal)

if(BUILD_EXAMPLE_LOG)
    add_executable(c_log_example example/main.c)
    target_link_libraries(c_log_example c_logger)
endif()

if(DOXYGEN_FOUND)
    if(BUILD_WITH_DOCS)
        doxygen_add_docs(c_logger_doc "include/" ALL COMMENT "Generate documents")
    endif()
endif()