int trace::PerformanceBoundGenerator::isFlop(const ir::PTXInstruction &instr) {
	
	OpcodeWeight flopOpcodes[] = {
		{ir::PTXInstruction::Add, 1},
		{ir::PTXInstruction::AddC, 1},
		{ir::PTXInstruction::Mad, 2},
		
		{ir::PTXInstruction::Cos, 1},
		{ir::PTXInstruction::Div, 1},
		{ir::PTXInstruction::Ex2, 1},

		{ir::PTXInstruction::Fma, 2},
		{ir::PTXInstruction::Lg2, 1},
		{ir::PTXInstruction::Mad, 2},
		{ir::PTXInstruction::Mul, 1},
		{ir::PTXInstruction::Rcp, 1},
		{ir::PTXInstruction::Rsqrt, 1},
		{ir::PTXInstruction::Sin, 1},
		{ir::PTXInstruction::Sqrt, 1},
		{ir::PTXInstruction::Sub, 1},
		{ir::PTXInstruction::SubC, 1},
		
		{ir::PTXInstruction::Nop, 0}
	};
	
	int flops = 0;
	
	if (instr.d.type == ir::PTXOperand::f32 ||
		instr.d.type == ir::PTXOperand::f64) {
		
		for (int n = 0; 
			flopOpcodes[n].opcode != ir::PTXInstruction::Nop && flopOpcodes[n].flops;
			++n) {
			if (flopOpcodes[n].opcode == instr.opcode) {
				flops = flopOpcodes[n].flops * (int)instr.vec;
				break;
			}
		}
	}

	return flops;
}