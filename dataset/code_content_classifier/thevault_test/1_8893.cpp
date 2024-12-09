bool cFile::IsBuffered(u32 Addr)
{
	if((this->BufferMap.size() > (Addr >> 3))
	&&(this->BufferMap[Addr >> 3] & (1 << (Addr & 7))))
		return true;
	else return false;
}