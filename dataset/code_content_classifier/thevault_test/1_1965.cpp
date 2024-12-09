ir::PTXB16 executive::CooperativeThreadArray::getRegAsB16(int threadID, 
	ir::PTXOperand::RegisterType reg) {
	ir::PTXB16 r = *( (ir::PTXB16*)(
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