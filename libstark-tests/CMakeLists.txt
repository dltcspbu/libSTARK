set(LIBS libstark gtest)

include_directories(.)

set(TEST_SRC_FILES
	main.cpp
	MerkleCommitment_UTEST.cpp
	BairWitnessChecker_UTEST.cpp
	AcspWitnessChecker_UTEST.cpp
	lightCircLib/lightCircuit.cpp
	lightCircLib/lightCircGate.cpp
	lightCircLib/lightCircPoly.cpp
	lightCircLib/lightCircPoly_UTEST.cpp
	BairToAcsp/witnessReduction_UTEST.cpp
	BairToAcsp/RoutingNetwork_UTEST.cpp
	BairToAcsp/neighborsConstructor_UTEST.cpp
	BairToAcsp/constraints_UTEST.cpp
	BairToAcsp/boundaryConstraints_UTEST.cpp
	BairToAcsp/AcspSummandsPolynomial_UTEST.cpp
)

add_executable(libstark-tests
	main.cpp
	MerkleCommitment_UTEST.cpp
	BairWitnessChecker_UTEST.cpp
	AcspWitnessChecker_UTEST.cpp
	lightCircLib/lightCircuit.cpp
	lightCircLib/lightCircGate.cpp
	lightCircLib/lightCircPoly.cpp
	lightCircLib/lightCircPoly_UTEST.cpp
	BairToAcsp/witnessReduction_UTEST.cpp
	BairToAcsp/RoutingNetworks_UTEST.cpp
	BairToAcsp/neighborsConstructor_UTEST.cpp
	BairToAcsp/constraints_UTEST.cpp
	BairToAcsp/boundaryConstraints_UTEST.cpp
	BairToAcsp/AcspSummandsPolynomial_UTEST.cpp
)


add_test(NAME libstark-tests-test COMMAND libstark-tests)

target_link_libraries(libstark-tests ${LIBS})