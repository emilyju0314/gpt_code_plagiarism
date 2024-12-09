static void GetBalanceFromDisk(void)
{
	if (!GCM->tempFiles()->exists(FINANCES_DATA_FILE)) {
		LaptopSaveInfo.iCurrentBalance = 0;
		return;
	}
	AutoSGPFile f(GCM->tempFiles()->openForReading(FINANCES_DATA_FILE));
	// get balance from disk first
	f->read(&LaptopSaveInfo.iCurrentBalance, sizeof(INT32));
}