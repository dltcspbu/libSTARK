/************************************** TinyRAMInstance.hpp **************************************/
/**
 * @file
 *
 * @brief The file TinyRAMInstance.hpp contains the interface for a TinyRAM instance.
 * 
 * Main classes defined in the file:
 *     TinyRAMPartialInstance
 *     TinyRAMFullInstance
 */
  /***********************************************************************************************/

#ifndef __RAM_INSTANCE_HPP
#define __RAM_INSTANCE_HPP

#include <vector>
#include <string>
#include <cstdint>
#include "TinyRAM/TinyRAMDefinitions.hpp"
#include "common/Utils/ErrorHandling.hpp"
#include <algorithm>
#include <math.h>
#include <algebraLib/FieldElement.hpp>
#include <algebraLib/CircuitPolynomial.hpp>
#include <algebraLib/variable.hpp>
#include <gadgetlib/infrastructure.hpp>
#include <gadgetlib/common_use.hpp>
#include <gadgetlib/protoboard.hpp>

using gadgetlib::Opcode;
using gadgetlib::Log2ceil;



/*************************************************************************************************/
/*************************************************************************************************/
/****************************                                         ****************************/
/****************************         class RAMArchParams         ****************************/
/****************************                                         ****************************/
/*************************************************************************************************/
/*************************************************************************************************/

struct RAMArchParams {
	uint64_t numRegisters;
	uint64_t registerLength;

	bool operator==(const RAMArchParams& rhs) const;
};

/*************************************************************************************************/
/*************************************************************************************************/
/****************************                                         ****************************/
/****************************         class TinyRAMProgram            ****************************/
/****************************                                         ****************************/
/*************************************************************************************************/
/*************************************************************************************************/
/// A data object which holds a TinyRAM code and auxiliary information.
struct MachineInstruction {
	Opcode opcode_ = Opcode::ANSWER;
	bool arg2isImmediate_ = true;
	uint64_t destIdx_ = 0;
	uint64_t arg1Idx_ = 0;
	uint64_t arg2IdxOrImmediate_ = 1;

	MachineInstruction(
		const Opcode& opcode,
		const bool arg2isImmediate,
		const uint64_t destIdx,
		const uint64_t arg1Idx,
		const uint64_t arg2IdxOrImmediate);
	
    MachineInstruction(const std::string line);

    void print()const;
};

class TinyRAMProgram {
public:
	typedef std::vector<MachineInstruction> RAMMachineCode;
private:
	std::string name_;
	RAMArchParams archParams_;
	RAMMachineCode code_;
public:
	TinyRAMProgram(const std::string& name,
		const RAMArchParams& archParams,
		const RAMMachineCode& code) :
		name_(name), archParams_(archParams), code_(code) {}

	TinyRAMProgram(const std::string& name,
		uint64_t numRegisters,
		uint64_t wordSize) :
		name_(name), archParams_(RAMArchParams{ numRegisters, wordSize }) {
	}

	std::string name() const { return name_; }
	const RAMMachineCode& code() const { return code_; }
	const uint64_t size() const { return code_.size(); }
	const RAMArchParams& archParams() const { return archParams_; }
	const MachineInstruction& getInstructionAtPc(const uint64_t pc) const { return code_[pc]; }
	void addInstruction(const MachineInstruction& instruction) { code_.emplace_back(instruction); }
	void addInstructionsFromFile(const std::string filename);
    unsigned int pcLength() const {
		int codeSize = code_.size();
		if (codeSize == 0){ _COMMON_FATAL("TinyRAMProgram : The code is not initialized"); };
		if (codeSize == 1) { return 1; }
		return  gadgetlib::Log2ceiled(codeSize);
	}

    void print()const;

};


/*************************************************************************************************/
/*************************************************************************************************/
/****************************                                         ****************************/
/****************************         class TinyRAMProtoboardParams   ****************************/
/****************************                                         ****************************/
/*************************************************************************************************/
/*************************************************************************************************/

class TinyRAMProtoboardParams : public gadgetlib::ProtoboardParams {
private:
	RAMArchParams archParams_;
	uint64_t opcodeWidth_;
	uint64_t timeBound_;
	uint64_t pcIncrement_;
public:
	TinyRAMProtoboardParams(unsigned int numRegisters, unsigned int registerLength,
		uint64_t opcodeWidth, uint64_t timeBound, uint64_t pcIncrement)
		: archParams_(RAMArchParams{ numRegisters, registerLength }),
		opcodeWidth_(opcodeWidth),
		timeBound_(timeBound), pcIncrement_(pcIncrement) {}
	TinyRAMProtoboardParams()
		: archParams_(RAMArchParams{ 0, 0 }), opcodeWidth_(0), timeBound_(0), pcIncrement_(0) {}
	RAMArchParams archParams() const { return archParams_; }
	uint64_t opcodeWidth() const { return opcodeWidth_; }
	uint64_t numRegisters() const { return archParams_.numRegisters; }
	uint64_t registerLength() const { return archParams_.registerLength; }
	uint64_t registerIndexLength() const { return Log2ceil(numRegisters()); }
	uint64_t arg2length() const { return std::max({ registerIndexLength(), registerLength() }); }
	uint64_t numOpcodes() const { return 1u << (opcodeWidth()); }
	uint64_t timeBound() const { return timeBound_; }
	uint64_t pcIncrement() const { return pcIncrement_; }
}; // class TinyRAMProtoboardParams


#endif 
