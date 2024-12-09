void lf_ntoa(unsigned long addr, char *addrbuf)
{
  sprintf(addrbuf, "%lu.%lu.%lu.%lu",
	  (addr >> 24),
	  (addr >> 16) % 256,
	  (addr >> 8) % 256,
	  (addr) % 256);
}