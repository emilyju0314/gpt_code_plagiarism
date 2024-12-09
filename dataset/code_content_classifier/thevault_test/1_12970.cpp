int ThermalEventCamera::wrapperUpdate()
{
	std::unique_lock<std::mutex> lck(this->print_mutex);
	lck.unlock();
	while(!this->stopFlag){
		this->update();
	}
	lck.lock();
	return 0;
}