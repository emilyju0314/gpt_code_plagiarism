CORR_DATA CITDBuffer::GetSimpleMedia()
{ 
	int i;
	CORR_DATA tmp;
	tmp.itd=0;
	tmp.shift=0;
	tmp.peak_level=0;
	tmp.valid=0;

	for (i=0;i<m_size;i++ )
	{
		tmp.itd=tmp.itd+pointer[i].itd;
		tmp.shift=tmp.shift+pointer[i].shift;
	}

	tmp.itd=(tmp.itd)/m_size;
	tmp.shift=(tmp.shift)/m_size;
	
	tmp.peak_level=global_peak;
	tmp.valid=global_valid;
	
	return tmp;
}