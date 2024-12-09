int strcat_s(char *strDestination, U32 sizeInBytes, const char *strSource)
{
	if (!strSource)
		return EINVAL;
	if (sizeInBytes == 0)
		return EINVAL;

	strDestination[sizeInBytes-1]=0;
	U32 posCopy = strlen(strDestination);
	if (posCopy >= sizeInBytes)
		return ERANGE;

	strncpy(&strDestination[posCopy], strSource, sizeInBytes-posCopy);
	if (strDestination[sizeInBytes-1]==0)
		return 0;

	strDestination[sizeInBytes-1]=0;
	return ERANGE;
}