void *MMap(int	fd, int	access, off_t	offset, size_t	len, off_t	*gap)
{
	void	*p=NULL;
	
#ifdef _WIN32
	/*
	 int g=0;
	 // code for windows must be checked
	 HANDLE	fh,
	 mh;
	 
	 fh = (HANDLE)_get_osfhandle(fd);
	 if(offset) {
	 // bisogna accertarsi che l'offset abbia la granularita`
	 //corretta, MAI PROVATA!
	 SYSTEM_INFO	si;
	 
	 GetSystemInfo(&si);
	 g = *gap = offset % si.dwPageSize;
	 } else if(gap) {
	 *gap=0;
	 }
	 if(!(mh=CreateFileMapping(fh, NULL, PAGE_READWRITE, 0, len+g, NULL))) {
	 return 0;
	 }
	 p = (char*)MapViewOfFile(mh, FILE_MAP_ALL_ACCESS, 0,
	 offset-*gap, len+*gap);
	 CloseHandle(mh);
	 */
	
#else
	int pgsz,g=0;
	if(offset) {
		pgsz = sysconf(_SC_PAGESIZE);
		g = *gap = offset%pgsz;
	} else if(gap) {
		*gap=0;
	}
	p = mmap((void*)0, len+g, access,
					 MAP_SHARED|MAP_FILE,
					 fd, offset-g);
	if((long)p==-1L)
	{
		perror("mmap failed");
		p=0;
	}
#endif
	return p;
}