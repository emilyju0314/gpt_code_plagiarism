int CDirLine::SortChainHead ( INTCHAIN *pTbl, int *pIndex )
{
    int i, n, xl, x ;

    n = m_pTree[m_nCurTree]->m_nDepth ;
    for ( i=0 ; i<n ; i++ )
        pIndex[i] = -1 ;
    xl = m_pTree[m_nCurTree]->GetLeftMostX() ;
    for ( i=0; i<m_nChain-m_nOldChain ; i++ )
    {
        x = m_pTree[m_nCurTree]->m_pNode[m_pChain[i+m_nOldChain].pHead].v.x & 0x1fffffff ;
        n = x - xl ;
        pTbl[i].n = i+m_nOldChain ;
        pTbl[i].pNext = pIndex[n] ;
        pIndex[n] = i ;
    }
    return 0 ;
}