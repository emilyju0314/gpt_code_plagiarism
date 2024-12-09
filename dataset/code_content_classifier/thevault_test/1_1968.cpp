bool executive::CooperativeThreadArray::getRegAsPredicate(int threadID, 
	ir::PTXOperand::RegisterType reg) {
	bool r = (bool)getRegAsU64(threadID, reg);
	#if REPORT_NTH_THREAD_ONLY == 1
	if (threadID == NTH_THREAD) {
		reportE(REPORT_REGISTER_READS, "   thread " << threadID 
			<< " reg " << reg << " <= " << r);
	}
	#else
	reportE(REPORT_REGISTER_READS && REPORT_PREDICATE_READS,
		"   thread " << threadID 
		<< " reg " << reg << " <= " << r);
	#endif
	return r;
}