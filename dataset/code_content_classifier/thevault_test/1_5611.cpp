int next_start_code( VidStream* vid_stream )
{
  int state;
  int byteoff;
  unsigned int data;

#if 0
  /* If no current stream, return error. */
  if (vid_stream== NULL)
    return NO_VID_STREAM;
#endif

  /* If insufficient buffer length, correct underflow. */

  if (vid_stream->buf_length < 4) {
    correct_underflow(vid_stream);
  }

  /* If bit offset not zero, reset and advance buffer pointer. */

  byteoff = vid_stream->bit_offset % 8;

  if (byteoff != 0) {
    flush_bits((8-byteoff));
  }

  /* Set state = 0. */

  state = 0;

  /* While buffer has data ... */

  while(vid_stream->buf_length > 0) {

    /* If insufficient data exists, correct underflow. */

    
    if (vid_stream->buf_length < 4) {
      correct_underflow(vid_stream);
    }

    /* If next byte is zero... */

    get_bits8(data);

    if (data == 0) {

      /* If state < 2, advance state. */

      if (state < 2) state++;
    }

    /* If next byte is one... */

    else if (data == 1) {

      /* If state == 2, advance state (i.e. start code found). */

      if (state == 2) state++;

      /* Otherwise, reset state to zero. */

      else state = 0;
    }

    /* Otherwise byte is neither 1 or 0, reset state to 0. */

    else {
      state = 0;
    }

    /* If state == 3 (i.e. start code found)... */

    if (state == 3) {

      /* Set buffer pointer back and reset length & bit offsets so
       * next bytes will be beginning of start code. 
       */

      vid_stream->bit_offset = vid_stream->bit_offset - 24;

#ifdef ANALYSIS
      bitCount -= 24;
#endif

      if (vid_stream->bit_offset < 0) {
        vid_stream->bit_offset = 32 + vid_stream->bit_offset;
        vid_stream->buf_length++;
        vid_stream->buffer--;
#ifdef UTIL2
        vid_stream->curBits = *vid_stream->buffer << vid_stream->bit_offset;
#else
        vid_stream->curBits = *vid_stream->buffer;
#endif
      }
      else {
#ifdef UTIL2
        vid_stream->curBits = *vid_stream->buffer << vid_stream->bit_offset;
#else
        vid_stream->curBits = *vid_stream->buffer;
#endif
      }

#ifdef NO_GRIFF_MODS
      /* Return success. */
      return OK;
#else /* NO_GRIFF_MODS */
      show_bits32(data);
      if ( data==SEQ_START_CODE ||
	   data==GOP_START_CODE ||
	   data==PICTURE_START_CODE ||
	   (data>=SLICE_MIN_START_CODE && data<=SLICE_MAX_START_CODE) ||
	   data==EXT_START_CODE ||
	   data==USER_START_CODE )
      {
        /* Return success. */
        return OK;
      }
      else
      {
	flush_bits32;
      }
#endif /* NO_GRIFF_MODS */
    }
  }

  /* Return underflow error. */
  return STREAM_UNDERFLOW;
}