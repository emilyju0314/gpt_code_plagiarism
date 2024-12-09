void  executive::CooperativeThreadArray::setRegAsU64(int threadID, 
	ir::PTXOperand::RegisterType reg, ir::PTXU64 value) {
	ir::PTXU64* r = (ir::PTXU64*)(
		&functionCallStack.registerFilePointer(threadID)[reg]);
	#if REPORT_NTH_THREAD_ONLY == 1
	if (threadID == NTH_THREAD) {
		reportE(REPORT_REGISTER_WRITES, "   thread " << threadID 
			<< " reg " << reg << " value " << " => " << (void*)value );
	}
	#else
	reportE(REPORT_REGISTER_WRITES, "   thread " << threadID 
		<< " reg " << reg << " value " << " => " << (void*)value );
	#endif
	*r = value;
}