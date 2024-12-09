void StateMachine::react_off()
{
	/* The reactions of state off. */
	if (timeEvents[0])
	{ 
		/* Default exit sequence for state off */
		stateConfVector[1] = AccuChargerExtensionSM_last_state;
		stateConfVectorPosition = 1;
		/* Exit action for state 'off'. */
		timer->unsetTimer(this, (sc_eventid)(&timeEvents[0]));
		iface.chargingPortEnable_value = ifaceInternalSCI.actualChargingPort;
		iface.chargingPortEnable_raised = true;
		ifaceInternalSCI.chargingTime_s = 0;
		/* Entry action for state 'charging'. */
		timer->setTimer(this, (sc_eventid)(&timeEvents[1]), 1 * 1000, true);
		/* 'default' enter sequence for state charging running */
		stateConfVector[1] = charging_running;
		stateConfVectorPosition = 1;
	} 
}