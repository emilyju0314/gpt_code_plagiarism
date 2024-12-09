void MSYS_Shutdown(void)
{
	MSYS_SystemInitialized = FALSE;
	MSYS_TrashRegList();
}