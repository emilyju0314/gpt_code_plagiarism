void StateMachine::react_endOfCharging()
{
	/* The reactions of state endOfCharging. */
	if (timeEvents[1])
	{ 
		ifaceInternalSCI.chargingTime_s += 1;
	} 
	if (timeEvents[2])
	{ 
		/* Default exit sequence for state charging */
		/* Default exit sequence for region r1 */
		/* Handle exit of all possible states (of accuChargerExtensionSM._2__charge_batteries.charging.r1) at position 1... */
		switch(stateConfVector[ 1 ])
		{
			case endOfCharging :
			{
				/* Default exit sequence for state endOfCharging */
				stateConfVector[1] = AccuChargerExtensionSM_last_state;
				stateConfVectorPosition = 1;
				/* Exit action for state 'endOfCharging'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[2]));
				break;
			}
			case charging_running :
			{
				/* Default exit sequence for state charging running */
				stateConfVector[1] = AccuChargerExtensionSM_last_state;
				stateConfVectorPosition = 1;
				break;
			}
			default: break;
		}
		/* Exit action for state 'charging'. */
		timer->unsetTimer(this, (sc_eventid)(&timeEvents[1]));
		iface.chargingPortDisable_value = -1;
		iface.chargingPortDisable_raised = true;
		react__choice1_();
	}  else
	{
		if (ifaceInternalSCI.chargingCurrent_filtered_raw > 514.5)
		{ 
			/* Default exit sequence for state endOfCharging */
			stateConfVector[1] = AccuChargerExtensionSM_last_state;
			stateConfVectorPosition = 1;
			/* Exit action for state 'endOfCharging'. */
			timer->unsetTimer(this, (sc_eventid)(&timeEvents[2]));
			/* 'default' enter sequence for state charging running */
			stateConfVector[1] = charging_running;
			stateConfVectorPosition = 1;
		} 
	}
}