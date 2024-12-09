int CILDBuffer::Resize(int new_size)
{
	if (new_size < 1) return 0;
	
	delete [] pointer;
	m_size=new_size;

	actual=0;
	pointer = new LEVEL_DATA [m_size];

	if (pointer == NULL) 
			return 0;
	for (int i=0;i<m_size;i++) 	
	{
		pointer[i].ild         = 0;
		pointer[i].left_level  = 0;
		pointer[i].right_level = 0;
		pointer[i].valid       = 0;
	}

	global_valid=0;

	return 1;
}