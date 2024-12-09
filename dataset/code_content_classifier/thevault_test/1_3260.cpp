void CGridTreeCellBase::OnClickDown( CPoint PointCellRelative)
{
    ASSERT( m_pTreeColumn != NULL);

    if( TreeHitPlusMinus(  PointCellRelative) ) // relative coordinates of mouse click
    {
        // returns:  T=hit a plus or minus;  F=Missed it or tree cell has no plus or minus
        m_pTreeColumn->TreeExpandCollapseToggle( m_iRow); // Grid row of node to toggle
    }

}