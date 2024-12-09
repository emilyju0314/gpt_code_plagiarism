void CHexEditView::ProcConversion(unsigned char *buf, size_t count, convert_type op)
{
	// Operate on all the selected values
	for (size_t ii = 0; ii < count; ++ii)
	{
		switch (op)
		{
		case CONVERT_ASC2EBC:
			if (buf[ii] < 128)
				buf[ii] = a2e_tab[buf[ii]];
			else
				buf[ii] = '\0';
			break;
		case CONVERT_EBC2ASC:
			buf[ii] = e2a_tab[buf[ii]];
			break;
		case CONVERT_ANSI2IBM:
			if (buf[ii] > 128)
				buf[ii] = a2i_tab[buf[ii]&0x7F];
			break;
		case CONVERT_IBM2ANSI:
			if (buf[ii] > 128)
				buf[ii] = i2a_tab[buf[ii]&0x7F];
			break;
		case CONVERT_UPPER:
			if (EbcdicMode())
			{
				if (buf[ii] >= 0x81 && buf[ii] <= 0x89 ||
					buf[ii] >= 0x91 && buf[ii] <= 0x99 ||
					buf[ii] >= 0xA2 && buf[ii] <= 0xA9 )
				{
					buf[ii] += 0x40;
				}
			}
			else if (AnsiMode() || buf[ii] < 128)
				buf[ii] = toupper(buf[ii]);
			break;
		case CONVERT_LOWER:
			if (EbcdicMode())
			{
				if (buf[ii] >= 0xC1 && buf[ii] <= 0xC9 ||
					buf[ii] >= 0xD1 && buf[ii] <= 0xD9 ||
					buf[ii] >= 0xE2 && buf[ii] <= 0xE9 )
				{
				buf[ii] -= 0x40;
				}
			}
			else if (AnsiMode() || buf[ii] < 128)
				buf[ii] = tolower(buf[ii]);
			break;
		default:
			ASSERT(0);
		}
	}
}