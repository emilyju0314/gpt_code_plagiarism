bool ParseList2(const char *str) {
	for (DWORD i = 0; i < g_serverCmdCount; i++) {
		if (!stricmp(str, g_serverCmds[i])) {
			return true;
		}
	}
	return false;
}