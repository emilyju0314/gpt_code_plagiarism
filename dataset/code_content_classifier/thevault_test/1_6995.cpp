void QA::UpdateState()
{
	double last_ptime = playTime_; // Last time to drain buffer
	DrainBuffers();
	DumpInfo(Scheduler::instance().clock(), last_ptime, 
		 rate(), avgrate_, rap()->srtt());
}