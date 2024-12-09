void trace::InstructionTraceGenerator::event(const TraceEvent & event) {
	// every instruction we encounter is guaranteed to be mapped to in the instructionCounter
	// data structure
	FunctionalUnit fu = getFunctionalUnit(*event.instruction);
	instructionCounter[fu][event.instruction->opcode].count(*event.instruction, 
		event.active.count());
}