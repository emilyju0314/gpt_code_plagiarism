static void DrawRecordsText(void)
{
	SetFont(FINANCE_TEXT_FONT);
	SetFontBackground(FONT_BLACK);
	SetFontShadow(NO_SHADOW);

	const FinanceUnit* fu = pFinanceListHead;
	for (INT32 i = 0; i < NUM_RECORDS_PER_PAGE && fu != NULL; ++i, fu = fu->Next)
	{
		const INT32 y = 12 + RECORD_Y + i * (GetFontHeight(FINANCE_TEXT_FONT) + 6);

		SetFontForeground(FONT_BLACK);

		// get and write the date
		DrawStringCentered(RECORD_DATE_X, y, RECORD_DATE_WIDTH, ST::format("{}", fu->uiDate / (24 * 60)));

		// get and write debit/credit
		if (fu->iAmount >= 0)
		{
			// increase in asset - debit
			DrawStringCentered(RECORD_DEBIT_X, y, RECORD_DEBIT_WIDTH, SPrintMoney(fu->iAmount));
		}
		else
		{
			// decrease in asset - credit
			SetFontForeground(FONT_RED);
			DrawStringCentered(RECORD_CREDIT_X, y, RECORD_CREDIT_WIDTH, SPrintMoney(-fu->iAmount));
		}

		// the balance to this point
		INT32 balance = fu->iBalanceToDate;
		if (balance >= 0)
		{
			SetFontForeground(FONT_BLACK);
		}
		else
		{
			SetFontForeground(FONT_RED);
			balance = -balance;
		}
		DrawStringCentered(RECORD_BALANCE_X, y, RECORD_BALANCE_WIDTH, SPrintMoney(balance));

		// transaction string
		DrawStringCentered(RECORD_TRANSACTION_X, y, RECORD_TRANSACTION_WIDTH, ProcessTransactionString(fu));
	}
}