#include "constraintSystemsTestLocations.hpp"

namespace libstark{
namespace BairToAcsp{
    
CS_testLocations::CS_testLocations(const common& commonDef){
    uint64_t currIndex = 0;

    for(uint64_t i=0; i< commonDef.getConstraintsPi().size();i++){
        indexesPermutation_[i] = currIndex++;
    }

    for(uint64_t i=0; i< commonDef.getConstraintsChi().size();i++){
        indexesAssignment_[i] = currIndex++;
    }
}

uint64_t CS_testLocations::indexOfConstraint_Assignment(polynomialIndicator_t poly)const{
    return indexesAssignment_.at(poly);
}

uint64_t CS_testLocations::indexOfConstraint_Permuation(polynomialIndicator_t poly)const{
    return indexesPermutation_.at(poly);
}

} //namespace BairToAcsp
} //namespace libstark
