void mCmd(const char * cmd)
{
	if (!TryEnterCriticalSection(&CriticalSection)) return;
	sprintf_s(sMircData, 1024, "%s", cmd);
	SendMessage(MircHwnd, WM_USER + 200, 1, 0);
	LeaveCriticalSection(&CriticalSection);
}