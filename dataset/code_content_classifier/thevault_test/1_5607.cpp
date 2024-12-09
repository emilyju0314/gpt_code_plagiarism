static inline bool audio_aligned(Uint8 *pointer, Uint32 size)
{
    Uint32 i, s;

#if 1 // Sam 10/27 - Don't choke on partially corrupt data
    size = 4;
#endif
    /* Check on all data available that next headers are aligned too */
    for(i = 0; i + 3 < size && audio_header(pointer+i, &s, 0); i+=s);

    if(i + 3 < size)
	return(false);
    else
	return(true);
}