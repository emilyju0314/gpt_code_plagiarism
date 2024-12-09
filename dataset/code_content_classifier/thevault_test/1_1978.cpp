void  executive::CooperativeThreadArray::setRegAsF64(int threadID, 
	ir::PTXOperand::RegisterType reg, ir::PTXF64 value) {
	ir::PTXF64* r = (ir::PTXF64*)(
		&functionCallStack.registerFilePointer(threadID)[reg]);
	#if REPORT_NTH_THREAD_ONLY == 1
	if (threadID == NTH_THREAD) {
		reportE(REPORT_REGISTER_WRITES, "   thread " << threadID 
			<< " reg " << reg << " value " << " => " << value
			<< " (0x" << std::hex << (hydrazine::bit_cast<ir::PTXU64>(value))
			<< std::dec << ")");
	}
	#else
	reportE(REPORT_REGISTER_WRITES, "   thread " << threadID 
		<< " reg " << reg << " value " << " => " << value
			<< " (0x" << std::hex << (hydrazine::bit_cast<ir::PTXU64>(value))
			<< std::dec << ")");
	#endif
	*r = value;
}