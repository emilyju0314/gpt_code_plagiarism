void StateMachine::react_filter()
{
	/* The reactions of state filter. */
	/* Default exit sequence for state filter */
	stateConfVector[0] = AccuChargerExtensionSM_last_state;
	stateConfVectorPosition = 0;
	ifaceInternalSCI.a = InternalSCI_OCB::exponential(-StateMachine::DefaultSCI::SamplingTime_ms / 16.6);
	ifaceInternalSCI.chargingCurrent_filtered_raw = iface.chargingCurrent_raw * (1 - ifaceInternalSCI.a) + ifaceInternalSCI.chargingCurrent_filtered_raw * ifaceInternalSCI.a;
	/* 'default' enter sequence for state filter */
	stateConfVector[0] = filter;
	stateConfVectorPosition = 0;
}