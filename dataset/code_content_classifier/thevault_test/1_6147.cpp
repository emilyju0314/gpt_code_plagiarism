void CILDBuffer ::PutItem (LEVEL_DATA item)
{ 
	pointer [actual]=item;
	actual++;
	if (actual == m_size) actual=0;
}