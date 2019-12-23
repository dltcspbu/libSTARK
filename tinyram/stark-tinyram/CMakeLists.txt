cmake_minimum_required(VERSION 3.14)
project(stark-tinyram)

set(LIBS gadgetlib fft algebralib libstark)

add_library(tinyram-lib
        src/TinyRAM/TinyRAMDefinitions.cpp
        src/TinyRAM/TinyRAMInstance.cpp
        src/TinyRAMtoBair/ConstraintSystemToBair/cs2Bair.cpp
        src/TinyRAMtoBair/RamToContraintSystem/ALU.cpp
        src/TinyRAMtoBair/RamToContraintSystem/ALUInputConsistency.cpp
        src/TinyRAMtoBair/RamToContraintSystem/generalPurpose.cpp
        src/TinyRAMtoBair/RamToContraintSystem/MemoryConsraints.cpp
        src/TinyRAMtoBair/RamToContraintSystem/traceConsistency.cpp
        src/TinyRAMtoBair/RamToContraintSystem/transitionFunction.cpp
)

# set(MY_FLAGS -O3 -Wall -p -pthread -fmessage-length=0 -std=gnu++11)
file(READ ../../compile_flags.txt COMPILE_FLAGS)
file(READ ../../link_flags.txt    LINK_FLAGS)
separate_arguments(COMPILE_FLAGS NATIVE_COMMAND ${COMPILE_FLAGS})
separate_arguments(LINK_FLAGS    NATIVE_COMMAND ${LINK_FLAGS})

target_compile_options(tinyram-lib PUBLIC ${COMPILE_FLAGS})
target_link_options(tinyram-lib PUBLIC ${LINK_FLAGS})

target_link_libraries(tinyram-lib  ${LIBS})

target_include_directories(tinyram-lib PUBLIC src)

set(LIBS ${LIBS} tinyram-lib)

add_executable(${PROJECT_NAME}
        src/main.cpp
)

target_compile_options(${PROJECT_NAME} PUBLIC ${COMPILE_FLAGS})
target_link_options(${PROJECT_NAME} PUBLIC ${LINK_FLAGS})

target_link_libraries(${PROJECT_NAME}  ${LIBS})

install(TARGETS ${PROJECT_NAME} DESTINATION ${INSTALL_DIR})