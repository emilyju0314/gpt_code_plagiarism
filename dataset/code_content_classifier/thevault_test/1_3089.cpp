__declspec(dllexport)
BOOL
QdMonitor(t_processMonitorCallback processMonitorCallback)
{
	BOOL ReturnValue = FALSE;
	OVERLAPPED CommRequestOverlapped = { 0 };
	COMM_REQUEST CommRequest = { 0 };

	// Open a handle to the device.
	ReturnValue = QdOpenDevice();
	if (ReturnValue != TRUE)
	{
		LOG_ERROR(_T("QdOpenDevice failed"));
		goto Exit;
	}

	//
	// Init overlapped structured
	//
	CommRequestOverlapped.hEvent = CommRequestEvent;
	ResetEvent(CommRequestEvent);

	CommRequest.CommControlRequest.RequestBuffer = &CommRequest.CommRequestBuffer[0];
	// TODO Set CommRequest.CommControlRequest.RequestID
	CommRequest.CommControlRequest.RequestBufferLength = sizeof(CommRequest.CommRequestBuffer);

	BOOL    status;
	DWORD   bytesReturned;
	DWORD	dwLastError;

	status = DeviceIoControl(g_QdDeviceHandle, QD_IOCTL_GET_NEW_PROCESSES,
		&(CommRequest), sizeof(COMM_REQUEST),
		&(CommRequest), sizeof(COMM_REQUEST),
		&bytesReturned,
		&CommRequestOverlapped);
	dwLastError = GetLastError();

	//
	// Ensure the request is either completed or pending
	//
	if (status) {
		// Completed
		LOG_INFO(_T("DeviceIoControl returned success immediately"));
	}
	else if (dwLastError == ERROR_IO_PENDING) {
		// Pending
		LOG_INFO(_T("DeviceIoControl Pending"));
	}
	else {
		// An error occurred
		LOG_ERROR(_T("DeviceIoControl failed - Status %x"), GetLastError());

		// TODO handle failure
		ReturnValue = FALSE;
		goto Exit;
	}

	// GetOverlappedResult waits infinitely.
	// Alternatively, could use HasOverlappedIoCompleted and Sleep in a loop
	// so I could terminate more easily
	// TODO EVENTUALLY Use GetOverlappedResultEx for Win 8 which allows timeouts

	DWORD   bytesTransferred;
	status = GetOverlappedResult(
		g_QdDeviceHandle,
		&CommRequestOverlapped,
		&bytesTransferred,
		TRUE); // bWait
	if (!status) {
		LOG_ERROR(_T("GetOverlappedResult failed - Status %x"), GetLastError());
		// Handle failure
		ReturnValue = FALSE;
		goto Exit;
	}

	if (!bRunning) {
		LOG_INFO(_T("We've been signalled to stop running"));
		ReturnValue = TRUE;
		goto Exit;
	}

	LOG_INFO(_T("GetOverlappedResult completed: Id= %08x, Type = %08x, CommRequest RequestBuffer %08x, CommRequestBuffer %08x, Length %x"),
		CommRequest.CommControlRequest.RequestID,
		CommRequest.CommControlRequest.RequestType,
		CommRequest.CommControlRequest.RequestBuffer,
		CommRequest.CommRequestBuffer,
		CommRequest.CommControlRequest.RequestBufferLength);

	//
	// Call the callback
	//
	PCOMM_CREATE_PROC pCreateProcStruct = (PCOMM_CREATE_PROC)CommRequest.CommRequestBuffer;
	processMonitorCallback(pCreateProcStruct);
	

	ResetEvent(CommRequestOverlapped.hEvent);
Exit:
	// Close our handle to the device.
	if (QdCloseDevice() != TRUE)
	{
		LOG_ERROR(_T("TcCloseDevice failed"));
	}

	return ReturnValue;
}