void CITDBuffer ::PutItem (CORR_DATA item)
{ 
	pointer [actual].itd=item.itd;
	pointer [actual].shift=item.shift;
	pointer [actual].peak_level=item.peak_level;
	pointer [actual].valid=item.valid;

	actual++;
	
	if (actual == m_size) actual=0;
}