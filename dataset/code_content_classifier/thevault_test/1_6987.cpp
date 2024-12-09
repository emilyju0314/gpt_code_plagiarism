int QA::AllZero(double *arr, int len)
{
	int i;
  
	for (i=0; i<len; i++)
		if (arr[i] != 0.0)
			// debug("-- arr[%d}: %f\n", i, arr[i]);
			return 0;
	return 1;
}