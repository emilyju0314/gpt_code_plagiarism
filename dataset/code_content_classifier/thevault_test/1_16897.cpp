int LoadStartModule(char *path)
{
	uint32 loadResult;
	uint32 startResult = 0;;
	int status;

	loadResult = sceKernelLoadModule(path, 0, NULL);
	if(loadResult & 0x80000000)
		return -1;
	else
		startResult = sceKernelStartModule(loadResult, 0, NULL, &status, NULL);

	if(loadResult != startResult)
		return -2;

	return 0;
}