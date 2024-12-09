void StateMachine::react__choice0_()
{
	/* The reactions of state null. */
	ifaceInternalSCI.chargingCurrent_filtered_raw = 0;
	/* 'default' enter sequence for state filter */
	stateConfVector[0] = filter;
	stateConfVectorPosition = 0;
}