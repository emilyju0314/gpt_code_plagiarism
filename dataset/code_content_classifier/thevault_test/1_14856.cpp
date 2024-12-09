void MSYS_Init(void)
{
	MSYS_TrashRegList();

	MSYS_CurrentMX = 0;
	MSYS_CurrentMY = 0;
	MSYS_CurrentButtons = 0;
	MSYS_Action=MSYS_NO_ACTION;

	MSYS_PrevRegion = NULL;
	MSYS_SystemInitialized = TRUE;
}