ir::PTXF32 executive::CooperativeThreadArray::getRegAsF32(int threadID, 
	ir::PTXOperand::RegisterType reg) {
	ir::PTXF32 r = *( (ir::PTXF32*)(
		&functionCallStack.registerFilePointer(threadID)[reg]));
	#if REPORT_NTH_THREAD_ONLY == 1
	if (threadID == NTH_THREAD) {
		reportE(REPORT_REGISTER_READS, "   thread " << threadID 
			<< " reg " << reg << " <= " << r
			<< " (0x" << std::hex << (hydrazine::bit_cast<ir::PTXU32>(r))
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