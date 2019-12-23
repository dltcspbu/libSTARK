#ifndef _COMMON_BairToAcsp_INSTANCEMAPPINGS_HPP__
#define _COMMON_BairToAcsp_INSTANCEMAPPINGS_HPP__

#include "commonMappings.hpp"

namespace libstark{
namespace BairToAcsp{
    
class instanceMappings : public commonMappings{
public:
    instanceMappings(const common& commonInfo);
    Algebra::FieldElement mapVariable(const uint64_t varId)const;
    witnessElement_t mapVariable_witnessElement(const uint64_t varId)const;
    Algebra::FieldElement mapNonPermutation_zeroRow(const uint64_t elementId)const;
    Algebra::FieldElement mapNonPermutation_lastRow(const uint64_t elementId)const;
protected:
    const common& commonInfo_;

private:
    Algebra::FieldElement getLastRowIndicator()const;
};

} //namespace BairToAcsp
} //namespace libstark


#endif // #ifndef _COMMON_BairToAcsp_INSTANCEMAPPINGS_HPP__
