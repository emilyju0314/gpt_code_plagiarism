LEVEL_DATA CILDBuffer::GetModifiedMedia()
{ 
	int i;
	LEVEL_DATA tmp_data;
	LEVEL_DATA last;
	tmp_data.ild=0;
	tmp_data.left_level=0;
	tmp_data.right_level=0;

	if (!global_valid)
		return tmp_data;

	last = GetLastItem();

	for (i=0;i<m_size;i++ )
	{
		tmp_data.ild=(tmp_data.ild+pointer[i].ild);
		tmp_data.left_level=(tmp_data.left_level+pointer[i].left_level);
		tmp_data.right_level=(tmp_data.right_level+pointer[i].right_level);
	}
	
	tmp_data.ild=tmp_data.ild/m_size;
	tmp_data.left_level=tmp_data.left_level/m_size;
	tmp_data.right_level=tmp_data.right_level/m_size;
	tmp_data.valid = 1;
	
	if (fabs(last.ild - tmp_data.ild) > 3)
	 	return last;
	else
		return tmp_data;
}