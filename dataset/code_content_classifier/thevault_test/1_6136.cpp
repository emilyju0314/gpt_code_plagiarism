int CITDBuffer::Resize(int new_size)
{
	if (new_size < 1) return 0;
	
	delete [] pointer;
	m_size=new_size;

	actual=0;
	pointer = new CORR_DATA [m_size];
	if (pointer == NULL) 
			return 0;
	
	for (int i=0;i<m_size;i++) 
	{
			pointer[i].itd=0;
			pointer[i].shift=0;
			pointer[i].peak_level=0;
			pointer[i].valid=0;
	}


	global_peak=0;
	global_valid=0;

	return 1;
}