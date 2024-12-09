LEVEL_DATA CILDBuffer::GetLastItem ()
{
	if ((actual-1)>=0) return pointer[actual-1];
	else return pointer[m_size-1];
}