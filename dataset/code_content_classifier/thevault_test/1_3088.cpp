BOOL QdUnloadDriver()
{
	BOOL ReturnValue = FALSE;

	LOG_TRACE(L"Entering");

	//
	// Unload the driver.
	//
	ReturnValue = QdStopService();
	if (ReturnValue == FALSE)
	{
		LOG_ERROR(L"TcStopService failed");
		goto Exit;
	}

	//
	// Delete the service.
	//
	ReturnValue = QdDeleteService();
	if (ReturnValue == FALSE)
	{
		LOG_ERROR(L"QdDeleteService failed");
		goto Exit;
	}

	ReturnValue = TRUE;

Exit:
	LOG_TRACE(L"Exiting");
	return ReturnValue;
}