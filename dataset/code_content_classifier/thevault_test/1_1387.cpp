static HKEY create_or_open_key(HKEY parentHandle, const String &sub_key, bool *readOnly, REGSAM access = 0) {
	// try to open or create it read/write
	HKEY resultHandle = create_or_open_key(parentHandle, registryPermissions, sub_key, access);
	if (resultHandle != 0) {
		if (readOnly != 0) {
			*readOnly = false;
		}
		return resultHandle;
	}
	// try to open or create it read/only
	resultHandle = create_or_open_key(parentHandle, KEY_READ, sub_key, access);
	if (resultHandle != 0) {
		if (readOnly != 0) {
			*readOnly = true;
		}
		return resultHandle;
	}
	return 0;
}