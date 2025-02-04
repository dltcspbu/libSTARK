#ifndef Bair_TO_Acsp_WITNESS_MAPPING_HPP__
#define Bair_TO_Acsp_WITNESS_MAPPING_HPP__

#include "commonMappings.hpp"
#include <functional>

namespace libstark{
namespace BairToAcsp{
    
class witnessMappings : public commonMappings{
public:
    witnessMappings(const common& commonInfo);
    Algebra::FieldElement mapNonPermutationElement(const uint64_t vecId, const uint64_t varIndex)const;
    witnessElement_t mapNonPermutationElement_witness(const uint64_t vecId, const uint64_t varIndex)const;
    
    ///
    /// Let \f$ \eta \f$ be the rows modulus, of degree \f$ d \f$
    /// This function maps the elementId \f$ \sum_{i=0}^{n} b_i 2^i \f$
    /// to the field element \f$ b_0 \cdot \eta + x^d \cdot \sum_{i=1}^{n} b_i x^i \f$
    ///
    /// For more details ask Michael Riabzev (this method reduces maximal number of neighbors)
    ///
    spaceIndex_t mapIndexOfNonPermutationVariable_spaceIndex(const spaceIndex_t& row_spaceIndex, const uint64_t& varIndex)const;
    witnessIndex_t mapIndexOfNonPermutationVariable_witnessIndex(const spaceIndex_t& row_spaceIndex, const uint64_t& varIndex)const;
    spaceIndex_t getFirstRow_spaceIndex()const{return 1;}
    spaceIndex_t getNextRow_spaceIndex(const spaceIndex_t& row_spaceIndex)const;
    
    spaceIndex_t mapNetworkElement_spaceIndex(const uint64_t rowId, const uint64_t column, const uint64_t layerId)const;
    witnessIndex_t mapNetworkElement_witnessIndex(const uint64_t rowId, const uint64_t column, const uint64_t layerId)const;
    spaceIndex_t mapNetworkRoutingBit_spaceIndex(const uint64_t rowId, const uint64_t column, const uint64_t layerId)const;
    witnessIndex_t mapNetworkRoutingBit_witnessIndex(const uint64_t rowId, const uint64_t column, const uint64_t layerId)const;

    std::vector<Algebra::FieldElement> getImageSpaceOrderedBasis()const;
private:
    const uint64_t firstRoutingBitsLayer_;
    const spaceIndex_t overflow_mask_;
    const uint64_t imageSpaceDim_;

    static uint64_t calculateImageSpaceDim(const commonDeffinitions& commonDef);
};

} //namespace BairToAcsp
} //namespace libstark

#endif //Bair_TO_Acsp_WITNESS_MAPPING_HPP__
