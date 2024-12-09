void executive::EmulatedKernel::updateParamReferences() {
	using namespace std;
	for (PTXInstructionVector::iterator 
		i_it = instructions.begin();
		i_it != instructions.end(); ++i_it) {
		ir::PTXInstruction& instr = *i_it;
		if (instr.addressSpace == ir::PTXInstruction::Param) {
			if (instr.opcode == ir::PTXInstruction::Ld 
				&& instr.a.addressMode == ir::PTXOperand::Address) {
				
				ir::Parameter *pParam = getParameter(instr.a.identifier);
				if (pParam) {
					ir::Parameter &param = *pParam;
					instr.a.isArgument = param.isArgument() && !function();
					report("For instruction '" << instr.toString() 
							<< "' setting source parameter '"
							<< instr.a.toString() 
							<< "' offset to "
							<< (param.offset + instr.a.offset) << " " 
							<< ( instr.a.isArgument ? "(argument)" : "" ) );
					instr.a.offset += param.offset;
					instr.a.imm_uint = 0;
				}
			}
			else if (instr.opcode == ir::PTXInstruction::St
				&& instr.d.addressMode == ir::PTXOperand::Address) {
				ir::Parameter *pParam = getParameter(instr.d.identifier);
				if (pParam) {
					ir::Parameter &param = *pParam;
					instr.d.isArgument = param.isArgument() && !function();
					report("For instruction '" << instr.toString() 
							<< "' setting destination parameter '"
							<< instr.d.toString() 
							<< "' offset to "
							<< (instr.d.offset + param.offset) << " " 
							<< ( instr.d.isArgument ? "(argument)" : "" ) );

					instr.d.offset += param.offset;
					instr.d.imm_uint = 0;
				}
			}
		}
	}
}