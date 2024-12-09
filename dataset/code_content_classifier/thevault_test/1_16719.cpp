int CImage::GetType()
{
// 	if (m_hImg != (HGLOBAL)NULL) {
// 		LPBITMAPINFO lpbi = (LPBITMAPINFO)GlobalLock(m_hImg);
// 		m_nBitCount = lpbi->bmiHeader.biBitCount;
// 		GlobalUnlock(m_hImg);
// 	}
    switch ( m_nBitCount )
    {
        case 1 :
            return DIB_1BIT ;
		case 4:
			return DIB_4BIT ;
        case 8 :
            return DIB_8BIT ;
        case 16 :
            return DIB_16BIT ;
        case 24 :
            return DIB_24BIT ;
        case 32 :
            return DIB_32BIT ;
        default :
            return DIB_UNKNOWN ;
    }
}