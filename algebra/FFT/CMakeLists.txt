cmake_minimum_required(VERSION 3.14)
project(fft)

add_library(${PROJECT_NAME}
        src/Basis.cpp
        # src/Basis.h
        src/Definitions.cpp
        # src/Definitions.h
        src/Element.cpp
        # src/Element.h
        src/FFT.cpp
        # src/FFT.h
        src/Polynomials.cpp
        # src/Polynomials.h)
)

file(READ ../../compile_flags.txt COMPILE_FLAGS)
file(READ ../../link_flags.txt    LINK_FLAGS)
separate_arguments(COMPILE_FLAGS NATIVE_COMMAND ${COMPILE_FLAGS})
separate_arguments(LINK_FLAGS    NATIVE_COMMAND ${LINK_FLAGS})

target_compile_options(${PROJECT_NAME} PUBLIC ${COMPILE_FLAGS})
target_link_options(${PROJECT_NAME} PUBLIC ${LINK_FLAGS})


target_include_directories(${PROJECT_NAME} PUBLIC src)
