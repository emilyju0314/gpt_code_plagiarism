static HKEY create_or_open_key(HKEY parentHandle, REGSAM perms, const String &sub_key, REGSAM access = 0) {
	// try to open it
	HKEY resultHandle = open_key(parentHandle, perms, sub_key, access);
	if (resultHandle != 0) {
		return resultHandle;
	}
	// try to create it
	LONG res = RegCreateKeyEx(parentHandle, sub_key.c_str(), 0, 0, REG_OPTION_NON_VOLATILE, perms | access, 0, &resultHandle, 0);
	if (res == ERROR_SUCCESS) {
		return resultHandle;
	}
	return 0;
}