#include "witnessMappings.hpp"

namespace libstark{
namespace BairToAcsp{

using Algebra::FieldElement;
using Algebra::mapIntegerToFieldElement;
using Algebra::mapFieldElementToInteger;
using Algebra::elementsSet_t;
using Infrastructure::Log2;
using std::vector;

witnessMappings::witnessMappings(const common& commonInfo):
    commonMappings(commonInfo),
    firstRoutingBitsLayer_(2*commonInfo.variablesPerm().size()),
    overflow_mask_(commonInfo.imageHeight()),
    imageSpaceDim_(calculateImageSpaceDim(commonInfo)){};

FieldElement witnessMappings::mapNonPermutationElement(const uint64_t vecId, const uint64_t varIndex)const{
    return map_x_power_modulu_poly(vecId, rowsModulus_) + commonMappings::mapNonPermutationElement(varIndex);
}

witnessMappings::witnessElement_t witnessMappings::mapNonPermutationElement_witness(const uint64_t vecId, const uint64_t varIndex)const{
    witnessElement_t res = commonMappings::mapNonPermutationElement_witness(varIndex);
    res.second += map_x_power_modulu_poly(vecId, rowsModulus_);

    return res;
}

witnessMappings::spaceIndex_t witnessMappings::getNextRow_spaceIndex(const spaceIndex_t& row_spaceIndex)const{
    spaceIndex_t nextVal = row_spaceIndex<<1;
    if(nextVal & overflow_mask_){
        nextVal ^= rowsModulus_;
    }
    return nextVal;
}

witnessMappings::spaceIndex_t witnessMappings::mapIndexOfNonPermutationVariable_spaceIndex(const spaceIndex_t& row_spaceIndex, const uint64_t& varIndex)const{
    return row_spaceIndex ^ mapNonPermutationVariable_spaceIndex(varIndex);
}

witnessMappings::witnessIndex_t witnessMappings::mapIndexOfNonPermutationVariable_witnessIndex(const spaceIndex_t& row_spaceIndex, const uint64_t& varIndex)const{
    const auto spaceIdx = mapIndexOfNonPermutationVariable_spaceIndex(row_spaceIndex, varIndex);
    return map_spaceIndex_to_witnessIndex(spaceIdx);
}

witnessMappings::spaceIndex_t witnessMappings::mapNetworkElement_spaceIndex(const uint64_t rowId, const uint64_t column, const uint64_t layerId)const{
    return rowId ^ mapPermutationElement_spaceIndex(column,layerId);
}

witnessMappings::witnessIndex_t witnessMappings::mapNetworkElement_witnessIndex(const uint64_t rowId, const uint64_t column, const uint64_t layerId)const{
    const auto spaceIdx = mapNetworkElement_spaceIndex(rowId,column,layerId);
    return map_spaceIndex_to_witnessIndex(spaceIdx);
}

witnessMappings::spaceIndex_t witnessMappings::mapNetworkRoutingBit_spaceIndex(const uint64_t rowId, const uint64_t column, const uint64_t layerId)const{
    const uint64_t routingBitslLayer = (layerId%2) + firstRoutingBitsLayer_;
    return mapNetworkElement_spaceIndex(rowId,column,routingBitslLayer);
}

witnessMappings::witnessIndex_t witnessMappings::mapNetworkRoutingBit_witnessIndex(const uint64_t rowId, const uint64_t column, const uint64_t layerId)const{
    const auto spaceIdx = mapNetworkRoutingBit_spaceIndex(rowId,column,layerId);
    return map_spaceIndex_to_witnessIndex(spaceIdx);
}

vector<FieldElement> witnessMappings::getImageSpaceOrderedBasis()const{
    vector<FieldElement> imageSpaceBasis;
    for(uint64_t i=0; i< imageSpaceDim_; i++){
        //the i'th element of the standard basis
        FieldElement basisElement = mapIntegerToFieldElement(i,1,1);

        //add to basis
        imageSpaceBasis.push_back(basisElement);
    }
    return imageSpaceBasis;
}

uint64_t witnessMappings::calculateImageSpaceDim(const commonDeffinitions& commonDef){
    const uint64_t dimOfImage = commonDef.widthSpaceDimension() + commonDef.heightSpaceDimension();
    return dimOfImage + (SUPPORT_ZK?1:0);
}
    
} //namespace BairToAcsp
} //namespace libstark
