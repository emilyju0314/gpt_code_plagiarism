BOOL CKoordWork::OnInitDialog()
{
	if ( !CDialog::OnInitDialog() )
		return FALSE;

	Localization::LocalizationServer *pLocalizationServer = Localization::LocalizationServer::get();
	assert( NULL != pLocalizationServer );

	std::string id = "CoordWorkDialogTitle";
	GUITextUtils::setWindowTextPerId( this, id );

	GUITextUtils::setLocalizedText( this, IDC_XCOMP, "CoordWorkDlg_XComp" );
	GUITextUtils::setLocalizedText( this, IDC_YCOMP, "CoordWorkDlg_YComp" );
	GUITextUtils::setLocalizedText( this, IDC_BOUNDARY_GRP, "CoordWorkDlg_BoundaryGrp" );
	GUITextUtils::setLocalizedText( this, IDC_CHECK1, "CoordWorkDlg_BoundaryX" );
	GUITextUtils::setLocalizedText( this, IDC_CHECK2, "CoordWorkDlg_BoundaryY" );
	GUITextUtils::setLocalizedText( this, IDC_CHECK3, "CoordWorkDlg_BoundaryZ" );
	
	id = "DialogOK";
	GUITextUtils::setWindowTextPerId( &m_ButtonOK, id );
	
	id = "DialogCancel";
	GUITextUtils::setWindowTextPerId( &m_ButtonCancel, id );		
	return TRUE;
}