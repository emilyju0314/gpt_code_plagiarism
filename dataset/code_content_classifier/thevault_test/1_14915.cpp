UINT16 IanDisplayWrappedString(UINT16 sx, UINT16 sy, UINT16 max_w, UINT8 gap, SGPFont font, UINT8 foreground, const ST::utf32_buffer& codepoints, UINT8 background, UINT32 flags)
{
	ST::string line_buf;
	const char32_t* i = codepoints.c_str();
	UINT16         cur_max_w      = max_w;
	UINT16         line_w         = 0;
	UINT16         x              = sx;
	UINT16         y              = sy;
	SGPFont        cur_font       = font;
	UINT16         h              = GetFontHeight(cur_font) + gap;
	bool           is_bold        = false;
	UINT8          cur_foreground = foreground;
	UINT16         justification  = LEFT_JUSTIFIED;
	do
	{
		// each character goes towards building a new word
		const char32_t* word_start = i;
		while (*i != TEXT_SPACE && *i != U'\0') ++i;

		// we hit a space (or end of record), so this is the END of a word!
		switch (word_start[0])
		{
			case TEXT_CODE_CENTER:
				if (justification != CENTER_JUSTIFIED)
				{
					justification = CENTER_JUSTIFIED;
				}
				else	// turn OFF centering...
				{
					// time to draw this line of text (centered)!
					IanDrawTextToScreen(line_buf, x, y, cur_max_w, cur_font, cur_foreground, background, justification, flags);

					x  = sx;
					y += h;

					// turn off centering...
					justification = LEFT_JUSTIFIED;
				}

				// reset the line
				line_buf = ST::null;
				line_w   = 0;
				break;

			case TEXT_CODE_NEWLINE:
				// Display what we have up to now
				IanDrawTextToScreen(line_buf, x, y, cur_max_w, cur_font, cur_foreground, background, justification, flags);

				x  = sx;
				y += h;

				// reset the line
				line_buf = ST::null;
				line_w   = 0;

				// reset width
				cur_max_w = max_w;
				break;

			case TEXT_CODE_BOLD:
				IanDrawTextToScreen(line_buf, x, y, cur_max_w, cur_font, foreground, background, justification, flags);
				// calculate new x position for next time
				x += StringPixLength(line_buf, cur_font);

				// shorten width for next time
				cur_max_w -= line_w;

				is_bold = !is_bold;
				if (is_bold)
				{ // turn bold ON
					SetFontShadow(NO_SHADOW);
					cur_font = FONT10ARIALBOLD;
				}
				else
				{ // turn bold OFF
					cur_font = font;
				}
				h = GetFontHeight(cur_font) + gap;

				// erase line string
				line_buf = ST::null;
				break;

			case TEXT_CODE_NEWCOLOR:
				// change to new color.... but first, write whatever we have in normal now...
				IanDrawTextToScreen(line_buf, x, y, cur_max_w, cur_font, cur_foreground, background, justification, flags);
				// calculate new x position for next time
				x += StringPixLength(line_buf, cur_font);

				// the new color value is the next character in the word
				if (word_start[1] != TEXT_SPACE && word_start[1] < 256)
					cur_foreground = (UINT8)word_start[1];

				cur_foreground = 184;

				// shorten width for next time
				cur_max_w -= line_w;

				// erase line string
				line_buf = ST::null;
				break;

			case TEXT_CODE_DEFCOLOR:
				// turn color back to default - write whatever we have in bold now...
				IanDrawTextToScreen(line_buf, x, y, cur_max_w, cur_font, cur_foreground, background, justification, flags);
				// calculate new x position for next time
				x += StringPixLength(line_buf, cur_font);

				// shorten width for next time
				cur_max_w -= line_w;

				// erase line string
				line_buf = ST::null;

				// change color back to default color
				cur_foreground = foreground;
				break;

			default: // not a special character
				// get the length (in pixels) of this word
				UINT16 word_w = 0;
				for (const char32_t* k = word_start; k != i; ++k)
				{
					word_w += GetCharWidth(cur_font, *k);
				}

				// can we fit it onto the length of our "line"?
				if (line_w + word_w >= max_w)
				{ // can't fit this word!
					// Display what we have up to now
					IanDrawTextToScreen(line_buf, x, y, cur_max_w, cur_font, cur_foreground, background, justification, flags);

					x  = sx;
					y += h;

					// start off next line string with the word we couldn't fit
					line_buf = ST::null;
					line_w   = 0;

					// reset width
					cur_max_w = max_w;
				}

				// add the word (with the space) to the line
				while (word_start != i) line_buf += *word_start++;
				line_buf += U' ';

				// calc new pixel length for the line
				line_w += word_w + GetCharWidth(cur_font, U' ');
				break;
		}
	}
	while (*i++ != U'\0');

	// draw the paragraph
	IanDrawTextToScreen(line_buf, x, y, cur_max_w, cur_font, cur_foreground, background, justification, flags);
	y += h;

	// return how many Y pixels we used
	return y - sy;
}