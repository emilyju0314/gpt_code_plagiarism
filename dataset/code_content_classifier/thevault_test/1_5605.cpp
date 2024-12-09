static inline bool Match4(Uint8 const code1[4], Uint8 const code2[4], Uint8 const mask[4])
{
  return( ((code1[0] & mask[0]) == (code2[0] & mask[0])) &&
	  ((code1[1] & mask[1]) == (code2[1] & mask[1])) &&
	  ((code1[2] & mask[2]) == (code2[2] & mask[2])) &&
	  ((code1[3] & mask[3]) == (code2[3] & mask[3])) );
}