void MPEGaudio::huffmandecoder_1(const HUFFMANCODETABLE *h,int *x,int *y)
{  
  HUFFBITS level=(1<<(sizeof(HUFFBITS)*8-1));
  int point=0;

  /* Lookup in Huffman table. */
  for(;;)
  {
    if(h->val[point][0]==0)
    {   /*end of tree*/
      int xx,yy;

      xx=h->val[point][1]>>4;
      yy=h->val[point][1]&0xf;

      if(h->linbits)
      {
	if((h->xlen)==(unsigned)xx)xx+=wgetbits(h->linbits);
	if(xx)if(wgetbit())xx=-xx;
	if((h->ylen)==(unsigned)yy)yy+=wgetbits(h->linbits);
	if(yy)if(wgetbit())yy=-yy;
      }
      else
      {
	if(xx)if(wgetbit())xx=-xx;
	if(yy)if(wgetbit())yy=-yy;
      }
      *x=xx;*y=yy;
      break;
    } 

    point+=h->val[point][wgetbit()];
    
    level>>=1;
    if(!(level || ((unsigned)point<ht->treelen)))
    {
      register int xx,yy;

      xx=(h->xlen<<1);// set x and y to a medium value as a simple concealment
      yy=(h->ylen<<1);

      // h->xlen and h->ylen can't be 1 under tablename 32
      //      if(xx)
	if(wgetbit())xx=-xx;
      //      if(yy)
	if(wgetbit())yy=-yy;

      *x=xx;*y=yy;
      break;
    }
  }
}