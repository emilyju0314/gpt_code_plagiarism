static INT32 GetPreviousDaysIncome(void)
{
	const UINT32 date_in_minutes = GetWorldTotalMin();
	const UINT32 date_in_days    = date_in_minutes / (24 * 60);

	AutoSGPFile f(GCM->tempFiles()->openForReading(FINANCES_DATA_FILE));

	INT32 iTotalPreviousIncome = 0;
	// start at the end, move back until Date / 24 * 60 on the record is = date_in_days - 2
	// loop, make sure we don't pass beginning of file, if so, we have an error, and check for condifition above
	BOOLEAN fOkToIncrement = FALSE;
	for (UINT32 pos = f->size(); pos >= FINANCE_HEADER_SIZE + RECORD_SIZE;)
	{
		f->seek(pos -= RECORD_SIZE, FILE_SEEK_FROM_START);

		BYTE data[RECORD_SIZE];
		f->read(data, sizeof(data));

		UINT8  code;
		UINT32 date;
		INT32  amount;
		DataReader d{data};
		EXTR_U8(d, code);
		EXTR_SKIP(d, 1);
		EXTR_U32(d, date);
		EXTR_I32(d, amount);
		EXTR_SKIP(d, 4);
		Assert(d.getConsumed() == lengthof(data));

		// now ok to increment amount
		if (date / (24 * 60) == date_in_days - 1) fOkToIncrement = TRUE;

		if (fOkToIncrement && (code == DEPOSIT_FROM_GOLD_MINE || code == DEPOSIT_FROM_SILVER_MINE))
		{
			// increment total
			iTotalPreviousIncome += amount;
		}

		// check to see if we are far enough
		if (date / (24 * 60) <= date_in_days - 2) break;
	}

	return iTotalPreviousIncome;
}