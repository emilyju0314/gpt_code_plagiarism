void ShowMUInfo(char chDrive)
{
	MFCALLSTACK;

	WCHAR szName[MAX_MUNAME + 1];
	ULARGE_INTEGER uliFreeAvail, uliFree, uliTotal;
	char szDrive[] = "X:\\";

	*szDrive = chDrive;
	GetDiskFreeSpaceEx( szDrive, &uliFreeAvail, &uliTotal, &uliFree );
	XMUNameFromDriveLetter( chDrive, szName, MAX_MUNAME + 1 );

	MFDebug_Message(MFStr("MU %c: (%S) free: %u total: %u.\r\n", chDrive, szName, uliFreeAvail.LowPart, uliTotal.LowPart));

	EnumSavedGames( *szDrive );
}