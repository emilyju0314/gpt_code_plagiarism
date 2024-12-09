LEVEL_DATA CILDBuffer::GetMedia()
{ 
	int i;
	LEVEL_DATA tmp_data;
	tmp_data.ild=0;
	tmp_data.left_level=0;
	tmp_data.right_level=0;

	for (i=0;i<m_size;i++ )
	{
		tmp_data.ild=(tmp_data.ild+pointer[i].ild);
		tmp_data.left_level=(tmp_data.left_level+pointer[i].left_level);
		tmp_data.right_level=(tmp_data.right_level+pointer[i].right_level);
	}
	
	tmp_data.ild=tmp_data.ild/m_size;
	tmp_data.left_level=tmp_data.left_level/m_size;
	tmp_data.right_level=tmp_data.right_level/m_size;

	tmp_data.valid=global_valid;
	
	return tmp_data;
}