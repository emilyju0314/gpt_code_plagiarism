Uint32 skip_zeros(Uint8 * pointer, Uint32 size)
{
  Uint32 header_size;
  Uint8 const one[4]  = {0x00,0x00,0x00,0x01};

  if(!size) return(0);

  header_size = 0;
  while(Match4(pointer, ZERO_CODE, FULL_MASK))
  {
    pointer++;
    if((++header_size) >= size - 4) return(0); 

    if(Match4(pointer, one, FULL_MASK))
    {
      pointer++;
      if((++header_size) >= size - 4) return(0); 
    }
  }
  return(header_size);
}