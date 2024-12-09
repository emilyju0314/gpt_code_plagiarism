int ThermalEventCamera::wrapperRead()
{
	// get lock on std cout
	// to be used when exception handling is set
	std::unique_lock<std::mutex> lck(this->print_mutex);
	lck.unlock();
	while(!this->stopFlag)
	{
		this->read();
	}
	lck.lock();
	return 0;
}