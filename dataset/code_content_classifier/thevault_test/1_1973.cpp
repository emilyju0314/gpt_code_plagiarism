void  executive::CooperativeThreadArray::setRegAsS8(int threadID, 
	ir::PTXOperand::RegisterType reg, ir::PTXS8 value) {
	ir::PTXS8* r = (ir::PTXS8*)(
		&functionCallStack.registerFilePointer(threadID)[reg]);
	#if REPORT_NTH_THREAD_ONLY == 1
	if (threadID == NTH_THREAD) {
		reportE(REPORT_REGISTER_WRITES, "   thread " << threadID 
			<< " reg " << reg << " value " << " => " << (int)value );
	}
	#else
	reportE(REPORT_REGISTER_WRITES, "   thread " << threadID 
		<< " reg " << reg << " value " << " => " << (int)value );
	#endif
	*r = value;
}