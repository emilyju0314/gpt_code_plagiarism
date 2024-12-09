static void LoadInRecords(UINT32 const page)
{
	iCurrentPage      = page;
	fReDrawScreenFlag = TRUE;
	SetFinanceButtonStates();
	ClearFinanceList();
	if (page == 0) return; // check if bad page

	AutoSGPFile f(GCM->tempFiles()->openForReading(FINANCES_DATA_FILE));

	UINT32 const size = f->size();
	if (size < FINANCE_HEADER_SIZE) return;

	UINT32       records      = (size - FINANCE_HEADER_SIZE) / FINANCE_RECORD_SIZE;
	UINT32 const skip_records = NUM_RECORDS_PER_PAGE * (page - 1);
	if (records <= skip_records) return;

	records -= skip_records;
	f->seek(FINANCE_HEADER_SIZE + FINANCE_RECORD_SIZE * skip_records, FILE_SEEK_FROM_START);

	if (records > NUM_RECORDS_PER_PAGE) records = NUM_RECORDS_PER_PAGE;
	for (; records > 0; --records)
	{
		BYTE data[FINANCE_RECORD_SIZE];
		f->read(data, sizeof(data));

		UINT8  code;
		UINT8  second_code;
		UINT32 date;
		INT32  amount;
		INT32  balance_to_date;
		DataReader d{data};
		EXTR_U8(d, code);
		EXTR_U8(d, second_code);
		EXTR_U32(d, date);
		EXTR_I32(d, amount);
		EXTR_I32(d, balance_to_date);
		Assert(d.getConsumed() == lengthof(data));

		ProcessAndEnterAFinacialRecord(code, date, amount, second_code, balance_to_date);
	}
}