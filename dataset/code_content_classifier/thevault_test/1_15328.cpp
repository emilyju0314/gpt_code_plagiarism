void scintillate(SCNotification* N, LPARAM lParam) {
	const auto h = static_cast<HWND>(N->nmhdr.hwndFrom);

	if (N->nmhdr.code == SCN_CHARADDED) {
		auto c = N->ch;
		const auto lpos = send_editor(h, SCI_GETCURRENTPOS);
		const auto line = send_editor(h, SCI_LINEFROMPOSITION, lpos);
	}

	else if (N->nmhdr.code == SCN_UPDATEUI) {
		const auto lpos = send_editor(h, SCI_GETCURRENTPOS);
		const auto c =static_cast<const int>(send_editor(h, SCI_GETCHARAT, lpos, 0));
		if (is_brace(c)) {
			const int bracepos = send_editor(h, SCI_BRACEMATCH, lpos, 0);
			if (bracepos != -1) {
				send_editor(h, SCI_BRACEHIGHLIGHT, lpos, bracepos);
			}
			else {
				SendMessage(h, SCI_BRACEBADLIGHT, lpos, 0);
			}
		}
	}
	else if (N->nmhdr.code == SCN_DWELLSTART) {
		const auto lpos = send_editor(h, SCI_GETCURRENTPOS);
		const auto c = static_cast<const int>(send_editor(h, SCI_GETCHARAT, lpos, 0));
		if (is_brace(c)) {
			const int bracepos = send_editor(h, SCI_BRACEMATCH, lpos, 0);
			if (bracepos != -1) {
				send_editor(h, SCI_BRACEHIGHLIGHT, lpos, bracepos);
			}
			else {
				SendMessage(h, SCI_BRACEBADLIGHT, lpos, 0);
			}
		}
	}
}