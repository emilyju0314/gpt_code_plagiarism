static void SetLastPageInRecords(void)
{
	AutoSGPFile f(GCM->tempFiles()->openForReading(FINANCES_DATA_FILE));

	const UINT32 size = f->size();

	if (size < FINANCE_HEADER_SIZE + FINANCE_RECORD_SIZE)
	{
		guiLastPageInRecordsList = 0;
		return;
	}

	guiLastPageInRecordsList =
		(size - FINANCE_HEADER_SIZE - FINANCE_RECORD_SIZE) /
		(FINANCE_RECORD_SIZE * NUM_RECORDS_PER_PAGE);
}