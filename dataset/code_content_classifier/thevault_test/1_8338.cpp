CString FormatBinary(UINT n, UINT w)
   {
    CString s;

    for(UINT i = 0; i < w; i++)
       { /* format bits */
        s = ((n & 1) ? _T("1") : _T("0")) + s;
        n >>= 1;
       } /* format bits */
    return s;
   }