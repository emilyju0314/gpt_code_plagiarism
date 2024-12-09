ir::PTXB64 executive::CooperativeThreadArray::getRegAsB64(int threadID, 
	ir::PTXOperand::RegisterType reg) {
	ir::PTXB64 r = *( (ir::PTXB64*)(
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