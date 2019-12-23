# include(GoogleTest)
# enable_testing()
# find_package(GTest REQUIRED)
# include_directories(${GTEST_INCLUDE_DIR})

set(LIBS gadgetlib tinyram-lib gtest)

add_executable(stark-tinyram-tests
	main.cpp
	ALUInputConsistenctUTEST.cpp
	ALU_UTEST.cpp
	traceConsistencyUTEST.cpp
	ConstraintsSystem2Bair_UTEST.cpp
	memory_UTEST.cpp
	transitionFunctionUTEST.cpp
	generalPupose_UTEST.cpp
	programs_UTEST.cpp
)

add_test(NAME stark-tinyram-tests-test COMMAND stark-tinyram-tests)

target_link_libraries(stark-tinyram-tests ${LIBS})
