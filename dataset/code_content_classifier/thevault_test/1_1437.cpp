void YakinduManualStatechartTimer::cancel(){
	TimeEvent* actualTimeEvent = firstTimeEvent;
	TimeEvent* nextTimeEvent = null;
	sc_boolean endReached = false;
	while(!endReached){
		if(actualTimeEvent != null){
			nextTimeEvent = actualTimeEvent->nextTimeEvent;
			free(actualTimeEvent);
			actualTimeEvent = nextTimeEvent;
		}else{
			endReached = true;
		}
	}	
}