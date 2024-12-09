int CDirLine::DumpChainData ( string  FileName)
{
	FILE *fp;
	fp= fopen(FileName.c_str(), "wt");
	if(fp== NULL)	return -1;
	for(int i=0; i<m_nChain; i++)
	{
		if(m_bIsHorLine)
			fprintf(fp, "(%d, %d)--(%d, %d)  Len=%d r=%f\n", m_pChain[i].xs, m_pChain[i].fYs, m_pChain[i].xe, m_pChain[i].fYe, m_pChain[i].Len, m_pChain[i].r);
		else
			fprintf(fp, "(%d, %d)--(%d, %d)  Len=%d r=%f\n", m_pChain[i].fYs,m_pChain[i].xs,  m_pChain[i].fYe, m_pChain[i].xe, m_pChain[i].Len, m_pChain[i].r);
	}
	fclose(fp);
	return 0 ;
}