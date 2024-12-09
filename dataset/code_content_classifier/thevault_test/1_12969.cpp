void ThermalEventCamera::update()
{
	if(this->clearSigns){
		std::fill(std::begin(this->out),std::end(this->out),0);
	}
	// if there are events in the queue
	if(!this->events.empty())
	{
		EventData ev;
		// get current size of queue and iterate over it
		// getting the entries and updating the signs matrix
		for(unsigned long i=0;i< this->events.size();++i){
			// if successful, update sign
			if(this->events.pop(ev)){
				this->out[ev.idx] = ev.sign;
				this->lts = ev.time();
			}
		}
	}
}