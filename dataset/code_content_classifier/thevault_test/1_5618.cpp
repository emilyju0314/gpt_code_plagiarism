void MPEGaudio::huffmandecoder_2(const HUFFMANCODETABLE *h,
				       int *x,int *y,int *v,int *w)
{  
  HUFFBITS level=(1<<(sizeof(HUFFBITS)*8-1));
  int point=0;

  /* Lookup in Huffman table. */
  for(;;)
  {
    if(h->val[point][0]==0)
    {   /*end of tree*/
      register int t=h->val[point][1];

      if(t&8)*v=1-(wgetbit()<<1); else *v=0;
      if(t&4)*w=1-(wgetbit()<<1); else *w=0;
      if(t&2)*x=1-(wgetbit()<<1); else *x=0;
      if(t&1)*y=1-(wgetbit()<<1); else *y=0;
      break;
    } 
    point+=h->val[point][wgetbit()];
    level>>=1;
    if(!(level || ((unsigned)point<ht->treelen)))
    {
      *v=1-(wgetbit()<<1);
      *w=1-(wgetbit()<<1);
      *x=1-(wgetbit()<<1);
      *y=1-(wgetbit()<<1);
      break;
    }
  }
}