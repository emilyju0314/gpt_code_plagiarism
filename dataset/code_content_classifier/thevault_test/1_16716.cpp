int CImage::GetLineSizeInBytes()
{
//     if ( m_hImg != (HGLOBAL)NULL )
//     {
//         LPBITMAPINFO lpbi = (LPBITMAPINFO)GlobalLock(m_hImg) ;
// 	    int n = GetLineSizeInBytes(lpbi) ;
//         GlobalUnlock(m_hImg) ;
//         return n ;
//     }
//     else
		return m_nWidthByte;
}