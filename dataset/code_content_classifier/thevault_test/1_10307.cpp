void CSDK_DEMODlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
// 		CDialog::OnPaint();
		
		CPaintDC dc(this); // device context for painting
		
		static int gImageType_prev = fp_bmp_raw;
		if (gImageType_prev != gImageType)
		{
			dc.FillRect(CRect(CPoint(LEFT,TOP), CSize(320,256)), &(CBrush(RGB(255,255,255))));
			gImageType_prev = gImageType;
		}

		if(gImageType == fp_bmp_256)
		{
			/*AVW*/
			fp_bmp_draw(dc.GetSafeHdc(), &fp_bmp256, gbyImg8bit, LEFT256, TOP, 256, 256);
		}
		if(gImageType == fp_bmp_raw)
		{
			fp_bmp_draw(dc.GetSafeHdc(), &fp_bmpraw, gbyImgRaw, LEFT, TOPRAW, 320, 240);
		}
	}
}