void KforthInstructionDialog::LoadList()
{
	CListBox *pLB = (CListBox*) GetDlgItem(IDC_IKI_LIST);
	char buf[1000];
	int i, j;

	if( pLB->GetCount() > 0 )
		return;

	pLB->ResetContent();

	m_item = -1;
	m_lbitem = -1;
	j = 0;
	for(i=0; i < sizeof(KFI)/sizeof(KFI[0]); i++) {
		if( KFI[i].mask & m_mask ) {
			sprintf(buf, "%-15s; %s", KFI[i].instruction, KFI[i].comment);

			pLB->InsertString(-1, buf);

			if( stricmp(KFI[i].instruction, m_goto) == 0 ) {
				m_item = i;
				m_lbitem = j;
			}

			j++;
		}
	}

	if( m_lbitem < 0 )  {
		return;
	}

	pLB->SetCurSel(m_lbitem);
	m_description = CString(KFI[m_item].instruction)
			+ CString("      ; ")
			+ CString(KFI[m_item].comment)
			+ CString("\r\n")
			+ CString("\r\n")
			+ CString(KFI[m_item].description);
}