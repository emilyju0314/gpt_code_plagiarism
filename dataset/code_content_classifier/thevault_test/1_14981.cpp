static void AppendFinanceToEndOfFile(void)
{
	AutoSGPFile f(GCM->tempFiles()->openForAppend(FINANCES_DATA_FILE));

	const FinanceUnit* const fu = pFinanceListHead;
	BYTE  data[FINANCE_RECORD_SIZE];
	DataWriter d{data};
	INJ_U8(d, fu->ubCode);
	INJ_U8(d, fu->ubSecondCode);
	INJ_U32(d, fu->uiDate);
	INJ_I32(d, fu->iAmount);
	INJ_I32(d, fu->iBalanceToDate);
	Assert(d.getConsumed() == lengthof(data));

	f->write(data, sizeof(data));
}