void YakinduManualStatechartTimer::setTimer(TimedStatemachineInterface* statemachine, sc_eventid event, sc_integer time, sc_boolean isPeriodic){
	if (firstTimeEvent == null){
		
		//firstTimeEvent = (TimeEvent*) malloc(sizeof(TimeEvent));
		//*firstTimeEvent = {statemachine, event, time, isPeriodic, time, true, null};
		
		firstTimeEvent = new TimeEvent(
			statemachine,
			event,
			time,
			isPeriodic,
			time,
			true,
			null
		);
		
	}else{	
		TimeEvent* actualTimeEvent = firstTimeEvent;
		sc_boolean timerSet = false;
		while(!timerSet){
			if(!actualTimeEvent->isActive){
				//actualTimeEvent = {statemachine, event, time, isPeriodic, time, true, actualTimerEvent.nextTimeEvent};
				
				// actualTimeEvent->statemachine = statemachine;
				// actualTimeEvent->eventId = event;
				// actualTimeEvent->time_ms = time;
				// actualTimeEvent->isPeriodic = isPeriodic;
				// actualTimeEvent->remainingTime_ms = time;
				// actualTimeEvent->isActive = true;
				// actualTimeEvent->nextTimeEvent = null;
				
				actualTimeEvent->setValues(
					statemachine,
					event,
					time,
					isPeriodic,
					time,
					true,
					actualTimeEvent->nextTimeEvent
				);
		
				timerSet = true;
			}else if(actualTimeEvent->nextTimeEvent == null){
				
				//old actualTimeEvent->nextTimeEvent = (TimeEvent*) malloc(sizeof(TimeEvent));
				//old *(actualTimeEvent->nextTimeEvent) = {statemachine, event, time, isPeriodic, time, true, null};
				actualTimeEvent->nextTimeEvent = new TimeEvent(
					statemachine,
					event,
					time,
					isPeriodic,
					time,
					true,
					null
				);
				
				timerSet = true;
			}else{
				actualTimeEvent = actualTimeEvent->nextTimeEvent;
			}
		}
	}
}