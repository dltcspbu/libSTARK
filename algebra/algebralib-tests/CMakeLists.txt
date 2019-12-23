# include(GoogleTest)
# enable_testing()
# find_package(GTest REQUIRED)
# include_directories(${GTEST_INCLUDE_DIR})

set(LIBS algebralib gtest)# ${GTEST_LIBRARIES})

add_executable(algebralib-tests
	main.cpp
	CircuitPolynomial_UTEST.cpp
	FFT_UTEST.cpp
	SelectorSum_UTEST.cpp
	FieldElement_UTEST.cpp
	UnivariatePolynomialGeneral_UTEST.cpp
	LinearizedPolynomials_UTEST.cpp
	variable_UTEST.cpp
	LinearPolynomial_UTEST.cpp
)

add_test(NAME algebralib-tests-test COMMAND algebralib-tests)

target_link_libraries(algebralib-tests ${LIBS})