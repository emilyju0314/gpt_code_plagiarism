int CDirLine::DumpChainsData ( string  FileName)
{
	FILE *fp;
	fp= fopen(FileName.c_str(), "wt");
	if(fp== NULL)	return -1;
	for(int i=0; i<m_nChains; i++)
	{
		if(m_pChains[i].Num < 30)	continue;
		ChainsQuality(m_pChains[i]);
		if(m_bIsHorLine)
			fprintf(fp, "(%d, %d)--(%d, %d)  Q=%f\n", m_pChains[i].xs, m_pChains[i].fYs, m_pChains[i].xe, m_pChains[i].fYe, m_pChains[i].Q);
		else
			fprintf(fp, "(%d, %d)--(%d, %d)  Q=%f\n", m_pChains[i].fYs, m_pChains[i].xs,  m_pChains[i].fYe, m_pChains[i].xe, m_pChains[i].Q);
	}
	fclose(fp);
	return 0 ;
}