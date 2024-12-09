static void *dec_pat_Init(MMSTREAM *mmfp)
{
	pat_readpat(0,0,0); // initialize pat loader
	return (void *)mmfp;
}