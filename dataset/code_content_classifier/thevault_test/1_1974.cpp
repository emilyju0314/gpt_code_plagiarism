void  executive::CooperativeThreadArray::setRegAsS16(int threadID, 
	ir::PTXOperand::RegisterType reg, ir::PTXS16 value) {
	ir::PTXS16* r = (ir::PTXS16*)(
		&functionCallStack.registerFilePointer(threadID)[reg]);
	#if REPORT_NTH_THREAD_ONLY == 1
	if (threadID == NTH_THREAD) {
		reportE(REPORT_REGISTER_WRITES, "   thread " << threadID 
			<< " reg " << reg << " value " << " => " << value );
	}
	#else
	reportE(REPORT_REGISTER_WRITES, "   thread " << threadID 
		<< " reg " << reg << " value " << " => " << value );
	#endif
	*r = value;
}