trace::InstructionTraceGenerator::FunctionalUnit trace::InstructionTraceGenerator::getFunctionalUnit(
	const ir::PTXInstruction &instr) {

	// switch warning: many fall-through cases follow - code blocks not listed in braces are suspect
	switch (instr.opcode) {

	// Arithmetic
	case ir::PTXInstruction::Abs:
	case ir::PTXInstruction::Add:
	case ir::PTXInstruction::AddC:
	case ir::PTXInstruction::Cvt:
	case ir::PTXInstruction::Cvta:
	case ir::PTXInstruction::Div:
	case ir::PTXInstruction::Fma:
	case ir::PTXInstruction::Mad24:
	case ir::PTXInstruction::Mad:
	case ir::PTXInstruction::Max:
	case ir::PTXInstruction::Min:
	case ir::PTXInstruction::Mov:
	case ir::PTXInstruction::Mul24:
	case ir::PTXInstruction::Mul:
	case ir::PTXInstruction::Neg:
	case ir::PTXInstruction::Rcp:
	case ir::PTXInstruction::Rem:
	case ir::PTXInstruction::Sad:
	case ir::PTXInstruction::Sub:
		{
			switch (instr.type) {
				case ir::PTXOperand::b8:
				case ir::PTXOperand::b16:
				case ir::PTXOperand::b32:
				case ir::PTXOperand::b64:
				case ir::PTXOperand::s8:
				case ir::PTXOperand::s16:
				case ir::PTXOperand::s32:
				case ir::PTXOperand::s64:
				case ir::PTXOperand::u8:
				case ir::PTXOperand::u16:
				case ir::PTXOperand::u32:
				case ir::PTXOperand::u64:
					{
						return Integer_arithmetic;
					}
				case ir::PTXOperand::f32:
					{
						return Float_single;
					}
				case ir::PTXOperand::f64:
					{
						return Float_double;
					}
				default:
					return FunctionalUnit_invalid;
			}
		}
		break;

	// Logical
	case ir::PTXInstruction::And:
	case ir::PTXInstruction::CNot:
	case ir::PTXInstruction::Not:
	case ir::PTXInstruction::Or:
	case ir::PTXInstruction::Shl:
	case ir::PTXInstruction::Shr:
	case ir::PTXInstruction::Xor:
		{
			switch (instr.type) {
				case ir::PTXOperand::b8:
				case ir::PTXOperand::b16:
				case ir::PTXOperand::b32:
				case ir::PTXOperand::b64:
				case ir::PTXOperand::s8:
				case ir::PTXOperand::s16:
				case ir::PTXOperand::s32:
				case ir::PTXOperand::s64:
				case ir::PTXOperand::u8:
				case ir::PTXOperand::u16:
				case ir::PTXOperand::u32:
				case ir::PTXOperand::u64:
					{
						return Integer_logical;
					}
				default:
					return FunctionalUnit_invalid;
			}
		}
		break;

	// Comparison
	case ir::PTXInstruction::SetP:
	case ir::PTXInstruction::Set:
	case ir::PTXInstruction::SlCt:
	case ir::PTXInstruction::SelP:
		{
			switch (instr.type) {
				case ir::PTXOperand::f32:
				case ir::PTXOperand::f64:
					{
						return Float_comparison;
					}

				case ir::PTXOperand::b8:
				case ir::PTXOperand::b16:
				case ir::PTXOperand::b32:
				case ir::PTXOperand::b64:
				case ir::PTXOperand::s8:
				case ir::PTXOperand::s16:
				case ir::PTXOperand::s32:
				case ir::PTXOperand::s64:
				case ir::PTXOperand::u8:
				case ir::PTXOperand::u16:
				case ir::PTXOperand::u32:
				case ir::PTXOperand::u64:
					{
						return Integer_comparison;
					}
				default:
					break;
			}
		}
		break;

	// Transcendental and other special
	case ir::PTXInstruction::Cos:
	case ir::PTXInstruction::Ex2:
	case ir::PTXInstruction::Lg2:
	case ir::PTXInstruction::Rsqrt:
	case ir::PTXInstruction::Sqrt:
	case ir::PTXInstruction::Sin:
		{
			switch (instr.type) {
				case ir::PTXOperand::f32:
				case ir::PTXOperand::f64:
					{
						return Special;
					}
				default:
					return FunctionalUnit_invalid;
			}
		}
		break;

	// Memory
	case ir::PTXInstruction::Atom:
	case ir::PTXInstruction::Ld:
	case ir::PTXInstruction::Ldu:
	case ir::PTXInstruction::Membar:
	case ir::PTXInstruction::Tex:
	case ir::PTXInstruction::St:
		{
			switch (instr.addressSpace) {
				case ir::PTXInstruction::Global:
				case ir::PTXInstruction::Local:
				{
					return Memory_offchip;
				}

				default:
				{
					return Memory_onchip;
				}
			}
		}
		break;

	// Parallelism
	case ir::PTXInstruction::Bar:
	case ir::PTXInstruction::Red:
	case ir::PTXInstruction::Vote:
		{
			return Parallelism;
		}
		break;

	// Control flow
	case ir::PTXInstruction::Bra:
	case ir::PTXInstruction::Call:
	case ir::PTXInstruction::Exit:
	case ir::PTXInstruction::Reconverge:
	case ir::PTXInstruction::Ret:
		{
			return Control;
		}
		break;

	// this should be an exhaustive list!
	default:
		break;
	}

	std::stringstream ss;
	ss << "InstructionTraceGenerator - PTX instruction not supported: " 
		<< ir::PTXInstruction::toString(instr.opcode);
	throw hydrazine::Exception(ss.str());
}