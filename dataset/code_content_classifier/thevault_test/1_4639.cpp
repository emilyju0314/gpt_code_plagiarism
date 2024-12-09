HMENU CLocateDlg::CreateFileContextMenu(HMENU hFileMenu,CLocatedItem** pItems,int nItems,BOOL bSimple)
{
	ClearMenuVariables();
	
	if (hFileMenu!=NULL)
	{
		CMenu FileMenu(hFileMenu);

		// Freeing memyry in SentToMenuItems
		FreeSendToMenuItems(FileMenu);
		
		// Removing all items
		for (int i=FileMenu.GetMenuItemCount()-1;i>=0;i--)
			FileMenu.DeleteMenu(i,MF_BYPOSITION);
		
		// Copying menu from template menu in resource
		if (nItems==0)
		{
			InsertMenuItemsFromTemplate(FileMenu,m_Menu.GetSubMenu(SUBMENU_FILEMENUNOITEMS),0);
			return hFileMenu;
		}
		InsertMenuItemsFromTemplate(FileMenu,m_Menu.GetSubMenu(SUBMENU_FILEMENU),0);
	}
	
	if (!bSimple)
	{
		// Creating context menu for file items
		m_pActiveContextMenu=GetContextMenuForItems(nItems,pItems);

		if (m_pActiveContextMenu!=NULL)
		{
			// IContextMenu interface has created succesfully,
			// so they can insert their own menu items

			HRESULT hRes;
			if (hFileMenu==NULL)
			{
				hFileMenu=CreatePopupMenu();

				if (HIBYTE(GetKeyState(VK_SHIFT)))
				{
					hRes=m_pActiveContextMenu->pContextMenu->QueryContextMenu(hFileMenu,0,
						IDM_DEFCONTEXTITEM,IDM_DEFSENDTOITEM,CMF_EXPLORE|CMF_EXTENDEDVERBS|CMF_CANRENAME);

				}
				else
				{
					hRes=m_pActiveContextMenu->pContextMenu->QueryContextMenu(hFileMenu,0,
						IDM_DEFCONTEXTITEM,IDM_DEFSENDTOITEM,CMF_EXPLORE|CMF_CANRENAME);
				}
			}
			else
			{
				hRes=m_pActiveContextMenu->pContextMenu->QueryContextMenu(hFileMenu,0,
					IDM_DEFCONTEXTITEM,IDM_DEFSENDTOITEM,CMF_EXPLORE|CMF_VERBSONLY|CMF_CANRENAME);
			}
			if (SUCCEEDED(hRes))
			{
				
				

				/* Insert "Rename" 
				UINT uID;
				if (IsUnicodeSystem())
				{
					for (int iPos=0;(uID=FileMenu.GetMenuItemID(iPos))!=UINT(-1);iPos++)
					{
						if (uID>=IDM_DEFCONTEXTITEM && uID<IDM_DEFCONTEXTITEM+1000)
						{
							WCHAR szName[200];
							HRESULT hRes=m_pActiveContextMenu->pContextMenu->GetCommandString(
								uID-IDM_DEFCONTEXTITEM,GCS_VERBW,NULL,(LPSTR)szName,200);
							
							if (hRes!=NOERROR)
							{
								if (wcscmp(szName,L"delete")==0)
								{
									CAppData::stdfunc();
								}
							}
						}							
					}
				}*/

				// Insert special menu, ...
				InsertMenuItemsFromTemplate(CMenu(hFileMenu),m_Menu.GetSubMenu(SUBMENU_EXTRACONTEXTMENUITEMS),0);
				return hFileMenu;
			}

			// Didn't succee, so freeing pointer
			delete m_pActiveContextMenu;
			m_pActiveContextMenu=NULL;
		}
	}

	if (hFileMenu==NULL)
	{
		CMenu FileMenu;
		FileMenu.CreatePopupMenu();
		InsertMenuItemsFromTemplate(FileMenu,m_Menu.GetSubMenu(SUBMENU_CONTEXTMENUPLAIN),0,IDM_DEFOPEN);
		InsertMenuItemsFromTemplate(FileMenu,m_Menu.GetSubMenu(SUBMENU_EXTRACONTEXTMENUITEMS),0);
		return FileMenu;
	}
	else
		InsertMenuItemsFromTemplate(CMenu(hFileMenu),m_Menu.GetSubMenu(SUBMENU_OPENITEMFORFILEMENU),0);
		
			

	return hFileMenu;
	
}