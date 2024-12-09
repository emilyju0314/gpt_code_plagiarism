int GetCurrentColor(HANDLE cHandle) {
	if (cHandle == NULL) throw new exception("Console handle is null.");
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(cHandle, &info);
	return info.wAttributes;
}