void StateMachine::react__choice3_()
{
	/* The reactions of state null. */
	ifaceInternalSCI.actualChargingPort = (ifaceInternalSCI.actualChargingPort + 1) % StateMachine::DefaultSCI::NrOfChargingPorts;
	/* 'default' enter sequence for state off */
	/* Entry action for state 'off'. */
	timer->setTimer(this, (sc_eventid)(&timeEvents[0]), 100, false);
	stateConfVector[1] = off;
	stateConfVectorPosition = 1;
}