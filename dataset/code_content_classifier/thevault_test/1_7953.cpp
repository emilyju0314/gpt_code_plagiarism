void DDX_CommaValuePositive(CDataExchange *pDX, int nIDC, int& value)
{
	char buf[1000];
	CString str;

	ASSERT( pDX != NULL );

	if( pDX->m_bSaveAndValidate ) {
		DDX_Text(pDX, nIDC, str);
		value = atoi_comma(str);
		if( value < 0 ) {
			value = 0;
		}
	} else {
		itoa_comma(buf, value);
		str = buf;
		DDX_Text(pDX, nIDC, str);
	}

}