CString CHexEditView::get_info()
{
	FILE_ADDRESS start = nav_start_;
	if (start >= GetDocument()->length())
	{
		return CString("End\nof\nfile");
	}

	if (display_.vert_display && pos2row(GetCaret()) == 0 || display_.edit_char)
	{
		// Take a sample of the file as text
		char buf[36];
		char *pp = buf;
		FILE_ADDRESS aa, end;
		unsigned char cc = '\0';
		end = start + 30;
		if (end > GetDocument()->length())
			end = GetDocument()->length();
		// Just use the selection if it is short enough
		if (start != nav_end_ && nav_end_ < end)
			end = nav_end_;
		for (aa = start; aa < end; ++aa)
		{
			GetDocument()->GetData(&cc, 1, aa);
			if (display_.char_set != CHARSET_EBCDIC)
			{
				if (isprint(cc))
					*pp++ = cc;
				else
					goto hex_info;
			}
			else
			{
				if (e2a_tab[cc] != '\0')
					*pp++ = e2a_tab[cc];
				else
					goto hex_info;
			}
		}
		*pp = '\0';
		if (aa < GetDocument()->length())
			strcat(pp, "...");
		return CString(buf);
	}

hex_info:
	{
		// Take a sample of the file as hex
		char buf[36];
		char *pp = buf;
		FILE_ADDRESS aa, end;
		unsigned char cc = '\0';
		end = start + 10;
		if (end > GetDocument()->length())
			end = GetDocument()->length();
		// Just use the selection if it is short enough
		if (start != nav_end_ && nav_end_ < end)
			end = nav_end_;
		for (aa = start; aa < end; ++aa)
		{
			GetDocument()->GetData(&cc, 1, aa);
			if (theApp.hex_ucase_)
				sprintf(pp, "%2.2X ", cc);
			else
				sprintf(pp, "%2.2x ", cc);
			pp += 3;
		}
		if (aa < GetDocument()->length())
			strcat(pp, "...");
		return CString(buf);
	}
}