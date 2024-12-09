void CCamviewDlg::OnPaint() 
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
		m_zx = 1;
		m_zy = 1;
		m_x = x;
		m_y = x;
		m_fx = 0;
		m_fy = 0;
	}
	else
	{
		CPaintDC dc(this);

		unsigned char *dib = m_receiver.AcquireBuffer();

		CRect rect, rect2 = 0;
		GetClientRect (&rect);
		
		/// is this needed?
		dc.LPtoDP (&rect);

		GetDlgItem(IDC_NAME)->GetWindowRect(&rect2);
		/*
		if (m_connection_name.m_hWnd != NULL)
		{
			m_connection_name.GetWindowRect (&rect2);
		}*/
		
		double zx = double(rect.Width() - 2 * _BORDER) / double(m_receiver.GetWidth());
		double zy = double(rect.Height() - 2 * _BORDER - rect2.Height() - 2) / double(m_receiver.GetHeight());

		if (zx > zy)
		{
			zx = zy;
		}

		int fx = int (m_receiver.GetWidth() * zx + .5);
		int fy = int (m_receiver.GetHeight() * zx +.5);

		int x = ((rect.Width() - 2 * _BORDER) - fx) / 2 + _BORDER;
		int y = ((rect.Height() - 2 * _BORDER - rect2.Height() - 2) - fy) / 2 + _BORDER;

		if (dib != NULL)
			CopyToScreen(m_drawdib, dc.GetSafeHdc(), dib, x, y, zx, zx);
		else
		{
			CGdiObject * old = dc.SelectStockObject (GRAY_BRUSH);
			dc.Rectangle (x, y, x+fx, y+fy);
			dc.SelectObject (old);
		}
		
		m_receiver.ReleaseBuffer();

		m_receiver.SetPaintRectangle (x, y, x+fx, y+fy);

		m_x = x;
		m_y = y;
		m_zx = zx;
		m_zy = zx;	// should be zy but we use zx
		m_fx = fx;
		m_fy = fy;

		CDialog::OnPaint();
	}
}