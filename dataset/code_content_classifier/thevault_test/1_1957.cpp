ir::PTXU64 executive::CooperativeThreadArray::getRegAsU64(int threadID, 
	ir::PTXOperand::RegisterType reg) {
	ir::PTXU64 r = *( (ir::PTXU64*)(
		&functionCallStack.registerFilePointer(threadID)[reg]));
	#if REPORT_NTH_THREAD_ONLY == 1
	if (threadID == NTH_THREAD) {
		reportE(REPORT_REGISTER_READS, "   thread " << threadID 
			<< " reg " << reg << " <= " << (void*)r);
	}
	#else
	reportE(REPORT_REGISTER_READS, "   thread " << threadID 
		<< " reg " << reg << " <= " << (void*)r);
	#endif
	return r;
}