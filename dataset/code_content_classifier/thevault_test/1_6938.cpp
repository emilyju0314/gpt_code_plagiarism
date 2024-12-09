void RapAgent::listen()
{
	if (debugEnable_)
		logfile_ = DebugEnable(this->addr() >> 
				       Address::instance().NodeShift_[1]);
}