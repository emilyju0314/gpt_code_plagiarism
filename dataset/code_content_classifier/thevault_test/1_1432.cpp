void StateMachine::react__choice1_()
{
	/* The reactions of state null. */
	if (ifaceInternalSCI.chargingTime_s > 1800)
	{ 
		iface.accuState = StateMachine::DefaultSCI::AccuStateRun;
		react__choice2_();
	}  else
	{
		if (ifaceInternalSCI.chargingTime_s < 60)
		{ 
			iface.accuState = StateMachine::DefaultSCI::AccuStateUndef;
			react__choice2_();
		}  else
		{
			iface.accuState = StateMachine::DefaultSCI::AccuStateFull;
			react__choice2_();
		}
	}
}