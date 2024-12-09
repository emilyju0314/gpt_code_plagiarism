void  executive::CooperativeThreadArray::setRegAsF32(int threadID, 
	ir::PTXOperand::RegisterType reg, ir::PTXF32 value) {
	ir::PTXF32* r = (ir::PTXF32*)(
		&functionCallStack.registerFilePointer(threadID)[reg]);
	#if REPORT_NTH_THREAD_ONLY == 1
	if (threadID == NTH_THREAD) {
		reportE(REPORT_REGISTER_WRITES, "   thread " << threadID 
			<< " reg " << reg << " value " << " => " << value
			<< " (0x" << std::hex << (hydrazine::bit_cast<ir::PTXU32>(value))
			<< std::dec << ")");
	}
	#else
	reportE(REPORT_REGISTER_WRITES, "   thread " << threadID 
		<< " reg " << reg << " value " << " => " << value
			<< " (0x" << std::hex << (hydrazine::bit_cast<ir::PTXU32>(value))
			<< std::dec << ")");
	#endif
	*r = value;
}