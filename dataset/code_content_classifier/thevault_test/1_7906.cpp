void CevolveView::OnView3D()
{
	CevolveDoc *doc;
	CString str;
	CWinApp *app;
	UNIVERSE *u;
	char cwd[1000], *p;
	char tmp_filename[1000], *tp;
	char args[1000];
	char errbuf[1000];
	char tmp_path[1000];
	char buf[1000];
	int n;

	doc = GetDocument();
	u = doc->universe;

	app = AfxGetApp();
	str = app->GetProfileString("evolve3d", "program");

	strcpy(cwd, str);

	p = strrchr(cwd, '\\');
	if( p == NULL ) {
		p = strrchr(cwd, '/');
	}

	if( p != NULL ) {
		*p = '\0';
	}

	n = GetTempPath(1000, tmp_path);
	if( n == 0 ) {
		sprintf(buf, "Unable to get TempPath");
		str = buf;
		AfxMessageBox(str, MB_OK, 0);
		return;
	}

	tp = _tempnam(tmp_path, "evolve3d_");
	if( tp != NULL ) {
		strcpy(tmp_filename, tp);
		strcat(tmp_filename, ".evolve");

		n = Universe_Write(u, tmp_filename, errbuf);
		if( !n ) {
			sprintf(buf, "%s", errbuf);
			str = buf;
			AfxMessageBox(str, MB_OK, 0);
			return;
		}
	} else {
		sprintf(buf, "Cannot create a unique filename\n" );
		str = buf;
		AfxMessageBox(str, MB_OK, 0);
		return;
	}

	sprintf(args, "%s /d", tmp_filename);

	ShellExecute(m_hWnd, "open",
		str,
		args,
		cwd,
		SW_SHOWNORMAL);

}