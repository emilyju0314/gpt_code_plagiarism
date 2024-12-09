CORR_DATA CITDBuffer::GetModifiedMedia()
{
	int i;
	CORR_DATA tmp;
	CORR_DATA last;
	tmp.itd=0;
	tmp.shift=0;
	tmp.peak_level=0;
	tmp.valid=0;

	if (!global_valid)
		return tmp;

	last = GetLastItem();

	for (i=0;i<m_size;i++ )
	{
		tmp.itd=tmp.itd+pointer[i].itd;
		tmp.shift=tmp.shift+pointer[i].shift;
		tmp.peak_level = tmp.peak_level+pointer[i].peak_level;
	}

	tmp.itd=tmp.itd/m_size;
	tmp.shift=tmp.shift/m_size;
	tmp.peak_level=tmp.peak_level/m_size;
	tmp.valid = 1;
	
	if (fabs(last.shift - tmp.shift) > 3)
	 	return last;
	else
	return tmp;
}