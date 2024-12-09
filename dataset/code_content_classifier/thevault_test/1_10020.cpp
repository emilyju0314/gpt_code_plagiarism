Viewer::Viewer(window_ptr Owner, bool bQuickView, uintptr_t aCodePage):
	SimpleScreenObject(std::move(Owner)),
	ViOpt(Global->Opt->ViOpt),
	Reader(ViewFile, (Global->Opt->ViOpt.MaxLineSize*2*64 > 64*1024 ? Global->Opt->ViOpt.MaxLineSize*2*64 : 64*1024)),
	strLastSearchStr(Global->GetSearchString()),
	LastSearchCase(Global->GlobalSearchCase),
	LastSearchWholeWords(Global->GlobalSearchWholeWords),
	LastSearchReverse(Global->GlobalSearchReverse),
	LastSearchHex(Global->GetSearchHex()),
	LastSearchRegexp(Global->Opt->ViOpt.SearchRegexp),
	LastSearchDirection(Global->GlobalSearchReverse? -1 : +1),
	m_DefCodepage(aCodePage),
	m_Codepage(m_DefCodepage),
	m_Wrap(Global->Opt->ViOpt.ViewerIsWrap),
	m_WordWrap(Global->Opt->ViOpt.ViewerWrap),
	m_DisplayMode(VMT_TEXT),
	ViewerID(::ViewerID++),
	m_bQuickView(bQuickView),
	vread_buffer(std::max(MaxViewLineBufferSize(), size_t(8192))),
	lcache_lines(16*1000),
	// dirty magic numbers, fix them!
	max_backward_size(std::min(Options::ViewerOptions::eMaxLineSize*3ll, std::max(Global->Opt->ViOpt.MaxLineSize*2, 1024ll) * 32)),
	llengths(max_backward_size / 40),
	Search_buffer(3 * std::max(MaxViewLineBufferSize(), size_t(8192))),
	ReadBuffer(MaxViewLineBufferSize())
{
	if (m_DefCodepage != CP_DEFAULT)
		MB.SetCP(m_DefCodepage);
}