double QA::TotalBuf(int n, double *buffer)
{
	double totbuf = 0.0;
	int i;

	for(i=0; i<n; i++)
		totbuf += buffer[i]; 
	return totbuf;
}