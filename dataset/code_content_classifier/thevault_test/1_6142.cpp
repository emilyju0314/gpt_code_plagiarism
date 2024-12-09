CORR_DATA CITDBuffer::GetWeighedMedia()
{ 
	int i;
	CORR_DATA tmp;
	tmp.itd=0;
	tmp.peak_level=0;
	tmp.valid=0;

	for (i=0;i<m_size;i++ )
	{
		tmp.itd=tmp.itd+pointer[i].itd;
		tmp.peak_level=tmp.peak_level+pointer[i].peak_level;
		tmp.valid=(tmp.valid)||(pointer[i].valid);
	}

	tmp.itd=(tmp.itd)/m_size;
	tmp.peak_level=(tmp.peak_level)/m_size;
	
	return tmp;
}