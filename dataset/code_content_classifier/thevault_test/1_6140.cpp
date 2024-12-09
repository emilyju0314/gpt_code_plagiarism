CORR_DATA CITDBuffer::GetMedia()
{ 
	int i;
	CORR_DATA tmp;
	tmp.itd=0;
	tmp.shift=0;
	tmp.peak_level=0;
	tmp.valid=0;

	int n = 0;

	for (i=0;i<m_size;i++ )
	{
		if (pointer[i].valid != 0)
		{
			tmp.itd=tmp.itd+pointer[i].itd;
			tmp.shift=tmp.shift+pointer[i].shift;
			n++;
		}
		
	}

	if (n>(m_size/3))
	{
		tmp.itd=(tmp.itd)/n;
		tmp.shift=(tmp.shift)/n;
		tmp.valid = 1;
	}
	else
		tmp.valid = 0;
	
	return tmp;
}