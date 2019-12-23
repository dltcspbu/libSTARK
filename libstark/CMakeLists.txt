cmake_minimum_required(VERSION 3.14)
project(libstark)

set(LIBS algebralib fft)

add_library(${PROJECT_NAME}
        src/common/Algebra/LinearSpace.cpp
        src/common/Algebra/MultiVarPoly.cpp
        src/common/Algebra/ShiftedSubspacePolynomial.cpp
        src/common/Infrastructure/Infrastructure.cpp
        src/common/Utils/ErrorHandling.cpp
        src/common/Utils/specsPrint.cpp
        src/common/Utils/Timing.cpp
        src/languages/Acsp/AcspWitnessChecker.cpp
        src/languages/Bair/BairWitnessChecker.cpp
        src/languages/Bair/ConstraintsSys.cpp
        src/protocols/Ali/common_details/common.cpp
        src/protocols/Ali/verifier_details/queriesGen.cpp
        src/protocols/Ali/prover.cpp
        src/protocols/Ali/verifier.cpp
        src/protocols/common/CryptoCommitment/MerkleCommitment.cpp
        src/protocols/common/proofs.cpp
        src/protocols/common/verifier.cpp
        src/protocols/Fri/common/common.cpp
        src/protocols/Fri/verifier_details/queryGenerator.cpp
        src/protocols/Fri/prover.cpp
        src/protocols/Fri/verifier.cpp
        src/protocols/protocol.cpp
        src/reductions/BairToAcsp/Details/AcspSummandsPolynomial.cpp
        src/reductions/BairToAcsp/Details/commonDeffinitions.cpp
        src/reductions/BairToAcsp/Details/commonMappings.cpp
        src/reductions/BairToAcsp/Details/constraints.cpp
        src/reductions/BairToAcsp/Details/constraintSystemsTestLocations.cpp
        src/reductions/BairToAcsp/Details/instanceMappings.cpp
        src/reductions/BairToAcsp/Details/neighborsConstructor.cpp
        src/reductions/BairToAcsp/Details/spaces.cpp
        src/reductions/BairToAcsp/Details/witnessMappings.cpp
        src/reductions/BairToAcsp/Details/witnessReduction.cpp
        src/reductions/BairToAcsp/Routing/BenesNetwork.cpp
        src/reductions/BairToAcsp/Routing/BitReverseButterfliesNetwork.cpp
        src/reductions/BairToAcsp/Routing/BtrflyBasedPermutation.cpp
        src/reductions/BairToAcsp/Routing/DeBruijnPermutationNet.cpp
        src/reductions/BairToAcsp/Routing/FoldNetwork.cpp
        src/reductions/BairToAcsp/Routing/LongDeBruijnPermutationNet.cpp
        src/reductions/BairToAcsp/Routing/LongSymmetricDeBruijnNetwork.cpp
        src/reductions/BairToAcsp/Routing/PermutationRoutingNet.cpp
        src/reductions/BairToAcsp/Routing/SymmetricDeBruijnNetwork.cpp
        src/reductions/BairToAcsp/Routing/TandemNetwork.cpp
        src/reductions/BairToAcsp/BairToAcsp.cpp
)

file(READ ../compile_flags.txt COMPILE_FLAGS)
file(READ ../link_flags.txt    LINK_FLAGS)
separate_arguments(COMPILE_FLAGS NATIVE_COMMAND ${COMPILE_FLAGS})
separate_arguments(LINK_FLAGS    NATIVE_COMMAND ${LINK_FLAGS})

target_compile_options(${PROJECT_NAME} PUBLIC ${COMPILE_FLAGS})
target_link_options(${PROJECT_NAME} PUBLIC ${LINK_FLAGS})


target_include_directories(${PROJECT_NAME} PUBLIC src)

target_link_libraries(${PROJECT_NAME}  ${LIBS})
