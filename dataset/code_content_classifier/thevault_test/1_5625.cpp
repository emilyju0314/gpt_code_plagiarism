static int abc_tuplet(int *nl, int *nd, int p, int q, int r)
{
	if( !r ) return 0;
	*nl *= q;
	*nd *= p;
	return r - 1;
}