CITDBuffer::CITDBuffer()
{
	m_size=1;
	actual=0;
	global_peak=0;
	global_valid=0;

	pointer = new CORR_DATA [m_size];

	ACE_ASSERT(pointer!=NULL);
	for (int i=0;i<m_size;i++) 
	{
			pointer[i].itd=0;
			pointer[i].shift=0;
			pointer[i].peak_level=0;
			pointer[i].valid=0;
	}

}