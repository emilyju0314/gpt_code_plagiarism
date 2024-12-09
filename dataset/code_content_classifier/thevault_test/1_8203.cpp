void HdlcSimulationDataGenerator::CreateSyncBit ( BitState bitState )
{
	if ( bitState == BIT_LOW ) // BIT_LOW == transition, BIT_HIGH == no transition
	{
		mHdlcSimulationData.Transition();
	}
	mHdlcSimulationData.Advance ( mSamplesInHalfPeriod );
}