ULONGLONG CFileEx::GetFileSize()
{
	ULONGLONG ulSize = 0;
	LARGE_INTEGER lInt;
	
	IsOpenThrows();
    
	if( ::GetFileSizeEx( m_hFile, &lInt ) ) {
		ulSize = lInt.QuadPart;
	}else{
		ThrowErr( ::GetLastError(), FALSE );
	}

	return ulSize;
}