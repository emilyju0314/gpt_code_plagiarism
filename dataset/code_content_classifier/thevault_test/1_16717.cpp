int CImage::GetWidth()
{
// 	if (m_hImg != (HGLOBAL)NULL) {
// 		LPBITMAPINFO lpbi = (LPBITMAPINFO)GlobalLock(m_hImg);
// 		int nWidth = lpbi->bmiHeader.biWidth;
// 		GlobalUnlock(m_hImg);
// 		return nWidth;
// 	} else
        return m_nWidth;
}