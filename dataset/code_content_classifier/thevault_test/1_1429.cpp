void StateMachine::react_charging_running()
{
	/* The reactions of state charging running. */
	if (timeEvents[1])
	{ 
		ifaceInternalSCI.chargingTime_s += 1;
	} 
	if (ifaceInternalSCI.chargingCurrent_filtered_raw < 514.5)
	{ 
		/* Default exit sequence for state charging running */
		stateConfVector[1] = AccuChargerExtensionSM_last_state;
		stateConfVectorPosition = 1;
		/* 'default' enter sequence for state endOfCharging */
		/* Entry action for state 'endOfCharging'. */
		timer->setTimer(this, (sc_eventid)(&timeEvents[2]), 5 * 1000, false);
		stateConfVector[1] = endOfCharging;
		stateConfVectorPosition = 1;
	} 
}