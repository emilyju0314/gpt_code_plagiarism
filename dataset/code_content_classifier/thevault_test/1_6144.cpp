CILDBuffer::CILDBuffer()
{
	int i  = 0;
	m_size = 1;
	actual = 0;
	global_valid=0;

	pointer = new LEVEL_DATA [m_size];

	ACE_ASSERT(pointer!=NULL);
	for (i=0;i<m_size;i++) 
	{
		pointer[i].ild         = 0;
		pointer[i].left_level  = 0;
		pointer[i].right_level = 0;
		pointer[i].valid       = 0;
	}
}