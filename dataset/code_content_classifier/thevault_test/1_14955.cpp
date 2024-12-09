static void DrawEmailSummary(INT32 y, const Email* e)
{
	const BOOLEAN read = e->fRead;
	const SGPFont font = read ? MESSAGE_FONT : FONT10ARIALBOLD;

	// will draw the icon for letter in mail list depending if the mail has been read or not
	BltVideoObject(FRAME_BUFFER, guiEmailIndicator, read ? 0 : 1, INDIC_X, y + 2);

	SetFont(font);

	ST::string pTempSubject = e->pSubject;
	pTempSubject = ReduceStringLength(pTempSubject, SUBJECT_WIDTH - 10, font);
	MPrint(SUBJECT_X, y + 4, pTempSubject);
	MPrint(SENDER_X,  y + 4, pSenderNameList[e->ubSender]);

	// draw date of message being displayed in mail viewer
	MPrint(DATE_X, y + 4, ST::format("{} {}", pDayStrings, e->iDate / (24 * 60)));
}