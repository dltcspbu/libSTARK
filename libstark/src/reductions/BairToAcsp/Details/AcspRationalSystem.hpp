#include "algebraLib/SubspacePolynomial.hpp"
#include "common/Algebra/ShiftedSubspacePolynomial.hpp"

#ifndef ACSP_RAT_SYS
#define ACSP_RAT_SYS

namespace libstark{
namespace BairToAcsp{

class AcspRationalSystem : public RationalConstraintSys{
public:
    virtual ~AcspRationalSystem(){};
private:
    typedef uint64_t polyId_t;
    typedef std::vector<uint64_t> translationTable_t;
    

    const std::unique_ptr<ConstraintSys> csTime_;
    const std::unique_ptr<ConstraintSys> csMem_;
};

} //namespace BairToAcsp
} //namespace libstark

#endif //ifndef ACSP_RAT_SYS
