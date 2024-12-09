int strncpy_s(char* strDestination, U32 sizeInBytes, const char* strSource, U32 nMaxCount)
{
	if (sizeInBytes == 0)
		return EINVAL;

	strDestination[sizeInBytes-1] = 0;

	if (nMaxCount == _TRUNCATE || nMaxCount >= sizeInBytes) {
		strncpy(strDestination, strSource, sizeInBytes);
	}
	else {
		strncpy(strDestination, strSource, nMaxCount);
		strDestination[nMaxCount]=0;
	}

	if (strDestination[sizeInBytes-1] == 0) {
		// strncpy does not leave a terminating zero on trunc
		// so no truncation.
		return 0;
	}
	strDestination[sizeInBytes-1]=0;
	return STRUNCATE;
}