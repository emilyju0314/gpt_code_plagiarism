void ShowThemeHelper(WDL_FastString* _report, HWND _hwnd, bool _mcp, bool _sel)
{
	WDL_PtrList<HWND__> hwnds;
	EnumChildWindows(_hwnd, EnumXCPWindows, (LPARAM)&hwnds);
	for (int i=0; i < hwnds.GetSize(); i++)
	{
		if (HWND w = hwnds.Get(i))
		{
//			if (IsWindowVisible(w))
			{
				bool mcpChild = IsChildOf(w, __localizeFunc("Mixer", "DLG_151", 0));
				if ((_mcp && mcpChild) || (!_mcp && !mcpChild))
				{
					MediaTrack* tr = (MediaTrack*)GetWindowLongPtr(w, GWLP_USERDATA);
					int trIdx = CSurf_TrackToID(tr, false);
					if (trIdx>=0 && (!_sel || (_sel && *(int*)GetSetMediaTrackInfo(tr, "I_SELECTED", NULL))))
					{
						RECT r;	GetClientRect(w, &r);
						char* trName = (char*)GetSetMediaTrackInfo(tr, "P_NAME", NULL);
						_report->AppendFormatted(
							1024,
							__LOCALIZE_VERFMT("%s Track #%d '%s': W=%d, H=%d\n","theme_helper"),
							_mcp ? __LOCALIZE("MCP","theme_helper") : __LOCALIZE("TCP","theme_helper"),
							trIdx==-1 ? 0 : trIdx,
							trIdx==-1 ? __LOCALIZE("[MASTER]","theme_helper") : (trName?trName:""),
							(int)(r.right-r.left),
							(int)(r.bottom-r.top));
					}
				}
			}
		}
	}
}