int CImage::GetHeight()
{
//     if ( m_hImg != (HGLOBAL)NULL )
//     {
//         LPBITMAPINFO lpbi = (LPBITMAPINFO)GlobalLock(m_hImg) ;
// 	    int nHeight  = lpbi->bmiHeader.biHeight ;
//         GlobalUnlock(m_hImg) ;
//         return nHeight ;
//     }
//     else
        return m_nHeight;
}