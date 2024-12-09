void CBlock::ComputeBlocks(CArray<CRect, CRect> & blocks, int nBlocks)
    {
     if(nBlocks == 0)
         return;

     TRACE("----------------------------------------------------------------\n");
     CRect r;
     GetClientRect(&r);

     TRACE("gap = %d\n", gap);

     int gaps = nBlocks - 1;
     TRACE("gaps = %d\n", gaps);
     
     int availableHeight = r.Height() - (gaps * gap);
     TRACE("availableHeight=%d\n", availableHeight);

     int height = availableHeight / nBlocks;
     TRACE("height = %d\n", height);

     height = min(r.Height() / 4, height);
     TRACE("constrained height = %d\n", height);

     int topToBottom = (height * nBlocks) + (gap * gaps);
     TRACE("top-to-bottom space = %d\n", topToBottom);

     int top = (r.Height() - topToBottom) / 2;
     TRACE("top = %d\n", top);

     blocks.SetSize(0);
     for(int i = 0; i < nBlocks; i++)
        { /* draw processors */
         CRect bk(r.left, top, r.right, top + height);
         TRACE("[%d] left=%d top=%d right=%d, bottom=%d\n", i, bk.left, bk.top, bk.right, bk.bottom);
         blocks.Add(bk);
         top += height + gap;
        } /* draw processors */
     TRACE("----------------------------------------------------------------\n");
    }