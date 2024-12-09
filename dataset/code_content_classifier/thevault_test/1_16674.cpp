int CDirLine::DumpLineData(string FileName)
{
	FILE *fp;
	fp= fopen(FileName.c_str(), "wt");
	if(fp== NULL)	return -1;
	for(int i=0; i<m_nLine; i++)
		fprintf(fp, "Line:%2d  (%4d, %4d)------>(%4d, %4d) Angle=%5.2f Q=%5.2f\n", i, m_pLine[i].StPnt.x, m_pLine[i].StPnt.y, m_pLine[i].EdPnt.x, m_pLine[i].EdPnt.y, m_pLine[i].Angle, m_pLine[i].Q);
	fclose(fp);
	return 0;
}