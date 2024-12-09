void YakinduManualStatechartTimer::unsetTimer(TimedStatemachineInterface* statemachine, sc_eventid event){
  (void)statemachine; //Dummy access to suppress "unused parameter" warning.
  
	TimeEvent* actualTimeEvent = firstTimeEvent;
	sc_boolean timerUnset = false;
	sc_boolean endReached = false;
	
	while(!timerUnset && !endReached ){
		if(actualTimeEvent->eventId == event){
      
			actualTimeEvent->isActive = false;
			timerUnset = true;
		}else if(actualTimeEvent->nextTimeEvent == null){
			endReached = true;
		}else{
			actualTimeEvent = actualTimeEvent->nextTimeEvent;
		}
	}
	
	//note: if endReached is true, then probably an error happened!
}