ir::PTXS16 executive::CooperativeThreadArray::getRegAsS16(int threadID, 
	ir::PTXOperand::RegisterType reg) {
	ir::PTXS16 r = *( (ir::PTXS16*)(
		&functionCallStack.registerFilePointer(threadID)[reg]));
	#if REPORT_NTH_THREAD_ONLY == 1
	if (threadID == NTH_THREAD) {
		reportE(REPORT_REGISTER_READS, "   thread " << threadID 
			<< " reg " << reg << " <= " << r);
	}
	#else
	reportE(REPORT_REGISTER_READS, "   thread " << threadID 
		<< " reg " << reg << " <= " << r);
	#endif
	return r;
}