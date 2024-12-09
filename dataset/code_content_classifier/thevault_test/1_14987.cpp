void ShutdownMemoryManager(void)
{
	if (MemDebugCounter != 0)
	{
		SLOGE(ST::format("Memory leak detected: \n\
					{} memory blocks still allocated\n\
					{} bytes memory total was allocated\n\
					{} bytes memory total was freed",
					MemDebugCounter, guiMemAlloced, guiMemFreed));
	}
	fMemManagerInit = FALSE;
}