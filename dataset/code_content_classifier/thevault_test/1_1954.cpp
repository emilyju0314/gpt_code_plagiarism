ir::PTXU8 executive::CooperativeThreadArray::getRegAsU8(int threadID, 
	ir::PTXOperand::RegisterType reg) {
	ir::PTXU8 r = *( (ir::PTXU8*)(
		&functionCallStack.registerFilePointer(threadID)[reg]));
	#if REPORT_NTH_THREAD_ONLY == 1
	if (threadID == NTH_THREAD) {
		reportE(REPORT_REGISTER_READS, "   thread " << threadID 
			<< " reg " << reg << " <= " << (int)r);
	}
	#else
	reportE(REPORT_REGISTER_READS, "   thread " << threadID 
		<< " reg " << reg << " <= " << (int)r);
	#endif
	return r;
}