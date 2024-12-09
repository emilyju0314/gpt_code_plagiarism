BOOL CGridTreeCellBase::DrawTreeCell(CDC* pDC, int nRow, int nCol, CRect* prect,
    BOOL /* bEraseBkgnd */)
{
    ASSERT( m_pTreeColumn != NULL);

    if( !m_pTreeColumn->GetAllowDraw())
        return FALSE;

    CGridCtrl* pGrid = GetGrid();

    if (!pGrid || !pDC)
        return FALSE;

    if( m_pTreeColumn->GetFixedRowCount() != pGrid->GetFixedRowCount()
        || m_pTreeColumn->GetRowCount() > pGrid->GetRowCount() )
    {
        ASSERT( FALSE); // if ASSERT here, this means that you a tree in a column
                        //  but you called CGridCtrl::SetFixedRowCount() or
                        //  or CGridCtrl::SetRowCount() directly.  You can't do this.
                        //  To change the layout of rows when you are using the tree,
                        //  you must call CTreeColumn::Setup().
        return FALSE;
    }

    if( prect->Width() <= 0
        || prect->Height() <= 0)  // prevents imagelist item from drawing even
        return FALSE;           //  though cell is hidden

    // tree drawing graphic logic begins here

    int nSavedDC = pDC->SaveDC();

    if( nCol == m_pTreeColumn->GetColumnWithTree())
    {
        // this column has a tree

        // move text over to allow for level indentation
        if( IsViewable() )
        {
            // if row is showing, draw the tree graphic
            if( m_pTreeColumn->GetTreeLines())
            {
                TreeDrawGraphic(    pDC,      // current CDC
                                    *prect);    // coordinates of bounding cell rectangle
            }
            else if( m_pTreeColumn->GetTreeUsesImages())
            {
                TREE_IMAGE TreeImage = TREE_IMAGE_DOCUMENT;

                // is it not the very last row?
                if( nRow + m_pTreeColumn->GetFixedRowCount() < m_pTreeColumn->GetRowCount())
                {
                    // is it a plus or minus?
                    BOOL bIsPlus;
                    BOOL bIsMinus;
                    BOOL bIsLastLeaf;

                    if( m_pTreeColumn->TreeCellHasPlusMinus(   nRow,        // row of Cell to check
                                                &bIsPlus,    // returns:  T=Is a plus
                                                &bIsMinus,   // returns:  T=Is a minus
                                                &bIsLastLeaf) )// returns:  T=Is Last Leaf
                    {
                        // returns:  T=cell has a plus or minus;  F=not
                        if( bIsPlus)
                            TreeImage = TREE_IMAGE_FOLDER_CLOSED;
                        else
                            TreeImage = TREE_IMAGE_FOLDER_OPEN;
                    }
                }
                SetImage( TreeImage);
            }
        }

        prect->left += GetTreeIndent();

    }
    pDC->RestoreDC(nSavedDC);
    return TRUE;
}