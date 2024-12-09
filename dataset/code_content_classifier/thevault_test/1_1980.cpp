void  executive::CooperativeThreadArray::setRegAsB16(int threadID, 
	ir::PTXOperand::RegisterType reg, ir::PTXB16 value) {
	ir::PTXB16* r = (ir::PTXB16*)(
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