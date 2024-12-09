void CMainFrame::set_rca(RCA_TYPE type)
{
	CWnd *pMain = AfxGetMainWnd();
	CMenu *menu = pMain->GetMenu();

	m_rca = type;

	//
	// clear all check marks
	//
	menu->CheckMenuItem(ID_EDIT_RIGHTCLICK_NOTHING, MF_UNCHECKED);
	menu->CheckMenuItem(ID_EDIT_RIGHTCLICK_BARRIER, MF_UNCHECKED);
	menu->CheckMenuItem(ID_EDIT_RIGHTCLICK_THIN_BARRIER, MF_UNCHECKED);
	menu->CheckMenuItem(ID_EDIT_RIGHTCLICK_DYE, MF_UNCHECKED);
	menu->CheckMenuItem(ID_EDIT_RIGHTCLICK_MOVE, MF_UNCHECKED);
	menu->CheckMenuItem(ID_EDIT_RIGHTCLICK_ENERGY, MF_UNCHECKED);

	//
	// Clear all check marks for popup menu too
	//
	CMenu* popup = m_popup.GetSubMenu(0);

	popup->CheckMenuItem(0, MF_BYPOSITION|MF_UNCHECKED);
	popup->CheckMenuItem(2, MF_BYPOSITION|MF_UNCHECKED);
	popup->CheckMenuItem(3, MF_BYPOSITION|MF_UNCHECKED);
	popup->CheckMenuItem(4, MF_BYPOSITION|MF_UNCHECKED);
	popup->CheckMenuItem(5, MF_BYPOSITION|MF_UNCHECKED);
	popup->CheckMenuItem(6, MF_BYPOSITION|MF_UNCHECKED);

	//
	// set the check mark for this rca type
	//
	switch( m_rca ) {
	case RCA_NOTHING:
		menu->CheckMenuItem(ID_EDIT_RIGHTCLICK_NOTHING, MF_CHECKED);
		popup->CheckMenuItem(0, MF_BYPOSITION|MF_CHECKED);
		break;

	case RCA_BARRIER:
		menu->CheckMenuItem(ID_EDIT_RIGHTCLICK_BARRIER, MF_CHECKED);
		popup->CheckMenuItem(2, MF_BYPOSITION|MF_CHECKED);
		break;

	case RCA_THIN_BARRIER:
		menu->CheckMenuItem(ID_EDIT_RIGHTCLICK_THIN_BARRIER, MF_CHECKED);
		popup->CheckMenuItem(3, MF_BYPOSITION|MF_CHECKED);
		break;

	case RCA_DYE:
		menu->CheckMenuItem(ID_EDIT_RIGHTCLICK_DYE, MF_CHECKED);
		popup->CheckMenuItem(4, MF_BYPOSITION|MF_CHECKED);
		break;

	case RCA_MOVE:
		menu->CheckMenuItem(ID_EDIT_RIGHTCLICK_MOVE, MF_CHECKED);
		popup->CheckMenuItem(5, MF_BYPOSITION|MF_CHECKED);
		break;

	case RCA_ENERGY:
		menu->CheckMenuItem(ID_EDIT_RIGHTCLICK_ENERGY, MF_CHECKED);
		popup->CheckMenuItem(6, MF_BYPOSITION|MF_CHECKED);
		break;

	default:
		ASSERT(0);
	}

}