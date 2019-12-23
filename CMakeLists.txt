cmake_minimum_required(VERSION 3.14)

project(libSTARK)

set(INSTALL_DIR ${PROJECT_SOURCE_DIR})

set(BINARY_DIR bin)

set(FFTLIB_SRC_DIR algebra/FFT/src)

set(ALGEBRALIB_DIR ${PROJECT_SOURCE_DIR}/algebra/algebralib)
set(LIBSTARK_DIR ${PROJECT_SOURCE_DIR}/libstark)
set(GADGETLIB3_DIR ${PROJECT_SOURCE_DIR}/tinyram/gadgetlib)
set(TINYRAM_DIR ${PROJECT_SOURCE_DIR}/tinyram/stark-tinyram)
set(DPM_DIR ${PROJECT_SOURCE_DIR}/starkdpm)
set(FFTLIB_DIR ${PROJECT_SOURCE_DIR}/algebra/FFT)

set(GTEST_DIR ${PROJECT_SOURCE_DIR}/_googletest)

set(ALGEBRALIB_TESTS_DIR ${PROJECT_SOURCE_DIR}/algebra/algebralib-tests)
set(LIBSTARK_TESTS_DIR ${PROJECT_SOURCE_DIR}/libstark-tests)
set(TINYRAM_TESTS_DIR ${PROJECT_SOURCE_DIR}/tinyram/stark-tinyram-tests)

set(LIBS gadgetlib fft algebralib libstark)
set(TESTS algebralib-tests libstark-tests stark-tinyram-tests)

add_subdirectory(${FFTLIB_DIR} ${BINARY_DIR}/fftlib)
add_subdirectory(${ALGEBRALIB_DIR} ${BINARY_DIR}/algebralib)
add_subdirectory(${LIBSTARK_DIR} ${BINARY_DIR}/libstark)
add_subdirectory(${GADGETLIB3_DIR} ${BINARY_DIR}/gadgetlib)

add_subdirectory(${TINYRAM_DIR})

# add_subdirectory(${GTEST_DIR} bin/_googletest)
# add_subdirectory(${ALGEBRALIB_TESTS_DIR})
# add_subdirectory(${LIBSTARK_TESTS_DIR})
# add_subdirectory(${TINYRAM_TESTS_DIR})