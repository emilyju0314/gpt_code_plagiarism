void StateMachine::react__choice2_()
{
	/* The reactions of state null. */
	iface.accuStateUpdate_value = ifaceInternalSCI.actualChargingPort;
	iface.accuStateUpdate_raised = true;
	react__choice3_();
}