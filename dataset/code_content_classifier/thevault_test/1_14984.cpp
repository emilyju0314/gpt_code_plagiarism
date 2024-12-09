static INT32 GetPreviousDaysBalance(void)
{
	const UINT32 date_in_minutes = GetWorldTotalMin() - 60 * 24;
	const UINT32 date_in_days    = date_in_minutes / (24 * 60);

	if (date_in_days < 2) return 0;

	AutoSGPFile f(GCM->tempFiles()->openForReading(FINANCES_DATA_FILE));

	INT32 balance = 0;
	// start at the end, move back until Date / 24 * 60 on the record equals date_in_days - 2
	// loop, make sure we don't pass beginning of file, if so, we have an error, and check for condifition above
	for (UINT32 pos = f->size(); pos >= FINANCE_HEADER_SIZE + RECORD_SIZE;)
	{
		f->seek(pos -= RECORD_SIZE, FILE_SEEK_FROM_START);

		BYTE data[RECORD_SIZE];
		f->read(data, sizeof(data));

		UINT32 date;
		INT32 balance_to_date;
		DataReader d{data};
		EXTR_SKIP(d, 2);
		EXTR_U32(d, date);
		EXTR_SKIP(d, 4);
		EXTR_I32(d, balance_to_date);
		Assert(d.getConsumed() == lengthof(data));

		// check to see if we are far enough
		if (date / (24 * 60) == date_in_days - 2)
		{
			balance = balance_to_date;
			break;
		}

		// there are no entries for the previous day
		if (date / (24 * 60) < date_in_days - 2) break;
	}

	return balance;
}