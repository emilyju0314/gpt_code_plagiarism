void CBlock::OnMouseMove(UINT nFlags, CPoint point)
    {
     ShowTip(point);
     CStatic::OnMouseMove(nFlags, point);
    }