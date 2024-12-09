COLORREF CBlock::GetBrushColor(CBrush & br)
    {
     if(br.GetSafeHandle() == NULL)
        return RGB(255, 255, 255);

     LOGBRUSH LB;
     bkgnd.GetLogBrush(&LB);
     return LB.lbColor;
     
    }