MR_PHY_MIB::MR_PHY_MIB(Mac802_11mr *parent) 
	: snr_AP(1000),
	  AckMode_AP(Mode1Mb)
{
	/*
	 * Bind the phy mib objects.  Note that these will be bound
	 * to Mac/802_11 variables
	 */

	parent->bind("CWMin_", &CWMin);
	parent->bind("CWMax_", &CWMax);
	parent->bind("SlotTime_", &SlotTime);
	parent->bind("SIFS_", &SIFSTime);
	parent->bind_bool("useShortPreamble_",&useShortPreamble);
	parent->bind("bSyncInterval_",&bSyncInterval);
	parent->bind("gSyncInterval_",&gSyncInterval);
}