void DDX_RangeValue(CDataExchange *pDX, int nIDC, int& value, int minval, int maxval)
{
	char buf[1000];
	CString str;

	ASSERT( pDX != NULL );

	if( pDX->m_bSaveAndValidate ) {
		DDX_Text(pDX, nIDC, str);
		value = atoi_comma(str);
		if( value < minval ) {
			value = minval;
		} else if( value > maxval ) {
			value = maxval;
		}
	} else {
		itoa_comma(buf, value);
		str = buf;
		DDX_Text(pDX, nIDC, str);
	}

}