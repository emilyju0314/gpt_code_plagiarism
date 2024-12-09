void CDeviceInfoUtility::ConstructL()
    {
	// Initializing the Telephony interface.
	iTelephony = CTelephony::NewL();
	// Initializing the ActiveShedulerWait.
	iActiveSchedulerWait = new (ELeave) CActiveSchedulerWait();
    }