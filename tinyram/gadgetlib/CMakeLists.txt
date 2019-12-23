cmake_minimum_required(VERSION 3.14)
project(gadgetlib)

include_directories(gadgetlib)
include_directories(gadgetlib/SHA)

set(LIBS fft algebralib libstark)

add_library(${PROJECT_NAME}
        # gadgetlib/examples/tutorial.cpp
        # gadgetlib/SHA/sha2.cpp
        # gadgetlib/SHA/sha2.hpp
        # gadgetlib/tests/constraint_UTEST.cpp
        # gadgetlib/tests/gadget_UTEST.cpp
        # gadgetlib/tests/gadgetlib2_test.cpp
        # gadgetlib/tests/protoboard_UTEST.cpp
        # gadgetlib/tests/variable_UTEST.cpp
        gadgetlib/common_use.cpp
        # gadgetlib/common_use.hpp
        gadgetlib/constraint.cpp
        # gadgetlib/constraint.hpp
        gadgetlib/gadget.cpp
        # gadgetlib/gadget.hpp
        gadgetlib/gadgetMacros.hpp
        gadgetlib/infrastructure.cpp
        # gadgetlib/infrastructure.hpp
        gadgetlib/protoboard.cpp
        # gadgetlib/protoboard.hpp
)

file(READ ../../compile_flags.txt COMPILE_FLAGS)
file(READ ../../link_flags.txt    LINK_FLAGS)
separate_arguments(COMPILE_FLAGS NATIVE_COMMAND ${COMPILE_FLAGS})
separate_arguments(LINK_FLAGS    NATIVE_COMMAND ${LINK_FLAGS})

target_compile_options(${PROJECT_NAME} PUBLIC ${COMPILE_FLAGS})
target_link_options(${PROJECT_NAME} PUBLIC ${LINK_FLAGS})

target_include_directories(gadgetlib PUBLIC .)

target_link_libraries(gadgetlib ${LIBS})
