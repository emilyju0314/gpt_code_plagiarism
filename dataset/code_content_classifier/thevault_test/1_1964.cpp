ir::PTXB8 executive::CooperativeThreadArray::getRegAsB8(int threadID, 
	ir::PTXOperand::RegisterType reg) {
	ir::PTXB8 r = *( (ir::PTXB8*)(
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