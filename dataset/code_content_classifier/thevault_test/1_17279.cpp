int GetSelectedAction(char* _section, int _secSize, int* _cmdId, char* _id, int _idSize, char* _desc, int _descSize)
{
	HWND hList = GetActionListBox(_section, _secSize);
	if (hList)
	{
		if (ListView_GetSelectedCount(hList))
		{
			LVITEM li;
			li.mask = LVIF_STATE | LVIF_PARAM;
			li.stateMask = LVIS_SELECTED;
			li.iSubItem = 0;
			for (int i=0; i < ListView_GetItemCount(hList); i++)
			{
				li.iItem = i;
				ListView_GetItem(hList, &li);
				if (li.state == LVIS_SELECTED)
				{
					int cmdId = (int)li.lParam;
					if (_cmdId) *_cmdId = cmdId;

					char actionName[SNM_MAX_ACTION_NAME_LEN] = "";
					ListView_GetItemText(hList, i, 1, actionName, SNM_MAX_ACTION_NAME_LEN); //JFB displaytodata? (ok: columns not re-orderable yet)
					if (_desc && _descSize > 0)
						lstrcpyn(_desc, actionName, _descSize);

					if (_id && _idSize > 0)
					{
						const char *custid=ReverseNamedCommandLookup(cmdId);
						if (custid) _snprintfStrict(_id, _idSize, "_%s", custid);
						else _snprintfStrict(_id, _idSize, "%d", cmdId);
					}
					return i;
				}
			}
		}
		else
			return -3;
	}
	return -1;
}