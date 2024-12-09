double CDirLine::ChainsQuality ( CHAINS &Chains )
{
	double gap, gap_paddings, sum_num, len, weight ;
	double sum_r;
    int segs, nChain, nNext ;

    gap = gap_paddings  = sum_num = 0 ;
	sum_r = 0;
    len = Chains.xe-Chains.xs+1 ;
    weight = segs = 0 ; 
    nChain = Chains.pHead ;
    while ( nChain >= 0 )
    {
        CHAIN Chain = m_pChain[nChain] ;
		sum_num += Chain.Num+2;//The start and end Run-Lengths are removed, so add 2 to detect dotted lines. 2000/4/22
        sum_r += Chain.r*Chain.Len ;
        weight += Chain.Len ;
        nNext = Chain.pRight ;
		int width = 0;
		int gap2 = 0;
        if ( nNext>=0)
		{	
			if(IsConnected2(nChain, nNext, width, gap2)==0)
			{
				if(width < 2*Chains.Width)
				{	gap +=gap2;
					sum_num += m_pChain[nNext].xs - Chain.xe - 1-gap2;
				}
				else	gap += m_pChain[nNext].xs - Chain.xe - 1 ;
				segs++ ;
			}
			else if(width < 2*Chains.Width)		
				sum_num += m_pChain[nNext].xs - Chain.xe-1;
		}
        if ( nChain == Chains.pTail )		break ;
        else
            nChain = nNext ;
    }

    double fgap ;
    if ( segs == 0 )
        fgap = 1 ;
    else
		fgap = sqrt(1-gap/segs/len);

	double	sum_dxdy, sum_dxdx, sum_dydy, dx, dy ;
	sum_dxdy = sum_dxdx = sum_dydy = 0;
    double  ax = (Chains.SumX+Chains.SumY)/Chains.Num ;
	double  ay = (Chains.SumY-Chains.SumX)/Chains.Num ;
	int		x, y, nTree;
	LineValley  v;
	
    int j = Chains.pHead ;
	nTree = 0;
	while(j >= m_nChainStart[nTree] && nTree<MAXSTRIP)	nTree++;
    while ( j >= 0 )
    {
        int pNode = m_pChain[j].pHead ;
		while ( pNode >= 0 )
        {
            v = m_pTree[nTree]->m_pNode[pNode].v ;
            x = v.x & 0x1fffffff ;
            if ( !(v.x & 0xc0000000))
            {   
                y = (v.yvs+v.yve)/2 ;
                dx=x+y-ax ; dy=y-x-ay ;
                sum_dxdx+=dx*dx ; sum_dydy+=dy*dy ; sum_dxdy+=dx*dy ;
            }
          if ( pNode != m_pChain[j].pTail )
                pNode = m_pTree[nTree]->m_pNode[pNode].pRight ;
            else
                break ;
        }
        j = m_pChain[j].pRight ;
    }
	double tmp = sqrt(sum_dxdx*sum_dydy);
	if(tmp<1e-8)
		Chains.r = 1.0;
	else
		Chains.r = fabs ( sum_dxdy / tmp ) ;

	Chains.Angle = GetAngle(DSCC_CPoint(Chains.xs, Chains.fYs), DSCC_CPoint(Chains.xe, Chains.fYe) );
	if(fabs(Chains.Angle) < PI*30/180)
		Chains.Q = sum_r/weight * Chains.r * Chains.r * fgap;
	else
		Chains.Q = fgap;

	if(segs == 0)//�����Ժõ�ֱ��
		Chains.Q = Chains.Q * pow(sum_num/(len-gap), 0.25)  ;
	else if(segs <= 2)
		Chains.Q = Chains.Q * pow(sum_num/(len-gap), 0.333);
	else//���ѵ�ֱ��
		Chains.Q = Chains.Q * pow(sum_num/(len-gap), 0.5) ;

	return Chains.Q ;
}