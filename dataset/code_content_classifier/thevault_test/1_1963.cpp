ir::PTXF64 executive::CooperativeThreadArray::getRegAsF64(int threadID, 
	ir::PTXOperand::RegisterType reg) {
	ir::PTXF64 r = *( (ir::PTXF64*)(
		&functionCallStack.registerFilePointer(threadID)[reg]));
	#if REPORT_NTH_THREAD_ONLY == 1
	if (threadID == NTH_THREAD) {
		reportE(REPORT_REGISTER_READS, "   thread " << threadID 
			<< " reg " << reg << " <= " << r
			<< " (0x" << std::hex << (hydrazine::bit_cast<ir::PTXU64>(r))
			<< std::dec << ")");
	}
	#else
	reportE(REPORT_REGISTER_READS, "   thread " << threadID 
		<< " reg " << reg << " <= " << r
			<< " (0x" << std::hex << (hydrazine::bit_cast<ir::PTXU64>(r))
			<< std::dec << ")");
	#endif
	return r;
}