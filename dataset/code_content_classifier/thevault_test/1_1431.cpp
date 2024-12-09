void StateMachine::react_react__choice0_()
{
	/* The reactions of state null. */
	iface.chargingPortDisable_value = -1;
	iface.chargingPortDisable_raised = true;
	ifaceInternalSCI.actualChargingPort = 0;
	/* 'default' enter sequence for state off */
	/* Entry action for state 'off'. */
	timer->setTimer(this, (sc_eventid)(&timeEvents[0]), 100, false);
	stateConfVector[1] = off;
	stateConfVectorPosition = 1;
}