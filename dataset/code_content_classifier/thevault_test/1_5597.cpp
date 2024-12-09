static int ParseSeqHead( VidStream* vid_stream )
{
  unsigned int data;
  int i, j;
#ifndef DISABLE_DITHER
  int ditherType=vid_stream->ditherType;
#endif

  /* Flush off sequence start code. */

  flush_bits32;

  /* Get horizontal size of image space. */

  get_bits12(data);
  vid_stream->h_size = (data + 15) & ~15;

  /* Get vertical size of image space. */

  get_bits12(data);
  vid_stream->v_size = (data + 15) & ~15;

  /* Calculate macroblock width and height of image space. */

  vid_stream->mb_width = (vid_stream->h_size + 15) / 16;
  vid_stream->mb_height = (vid_stream->v_size + 15) / 16;

#ifndef DISABLE_DITHER
  /* If dither type is MBORDERED allocate ditherFlags. */
  if (ditherType == MBORDERED_DITHER) {
    vid_stream->ditherFlags =
         (char *) malloc(vid_stream->mb_width*vid_stream->mb_height);
  }
#endif

  /* Parse of aspect ratio code. */

  get_bits4(data);
  vid_stream->aspect_ratio = (unsigned char) data;

  /* Parse off picture rate code. */

  get_bits4(data);
  vid_stream->picture_rate = (unsigned char) data;

  /* Parse off bit rate. */

  get_bits18(data);
  vid_stream->bit_rate = data;

  /* Flush marker bit. */

  flush_bits(1);

  /* Parse off vbv buffer size. */

  get_bits10(data);
  vid_stream->vbv_buffer_size = data;

#ifdef not_def
  /* Lets not bother with this.  Only increases memory image */
  if (data*1024>vid_stream->max_buf_length) {
    unsigned int *newbuf;
    int sz=1024*data+1;
    /* If they actually want a bigger buffer than we default to,
       let them have it! (if we can) */
    newbuf = (unsigned int *) realloc(vid_stream->buf_start, (unsigned int) 4*sz);
    if (newbuf!=(unsigned int *)NULL) {
      vid_stream->max_buf_length=sz;
      vid_stream->buffer=
          (vid_stream->buffer-vid_stream->buf_start)+newbuf;
      vid_stream->buf_start=newbuf;
    }}
#endif

  /* Parse off contrained parameter flag. */

  get_bits1(data);
  if (data) {
    vid_stream->const_param_flag = TRUE;
  } else
    vid_stream->const_param_flag = FALSE;

  /*
   * If intra_quant_matrix_flag set, parse off intra quant matrix values.
   */

  get_bits1(data);
  if (data) {
    for (i = 0; i < 64; i++) {
      get_bits8(data);

      vid_stream->intra_quant_matrix[zigzag[i][1]][zigzag[i][0]] =
        (unsigned char) data;
    }
  }
  /*
   * If non intra quant matrix flag set, parse off non intra quant matrix
   * values.
   */

  get_bits1(data);
  if (data) {
    for (i = 0; i < 64; i++) {
      get_bits8(data);

      vid_stream->non_intra_quant_matrix[zigzag[i][1]][zigzag[i][0]] =
        (unsigned char) data;
    }
  }

  /* Adjust noise base matrix according to non_intra matrix */
  for( i = 0; i < 8; i++ )
    for( j = 0; j < 8; j++ )
      vid_stream->noise_base_matrix[i][j] = (short) vid_stream->non_intra_quant_matrix[i][j];
  
  j_rev_dct((short *) vid_stream->noise_base_matrix);
  
  for( i = 0; i < 8; i++ )
    for( j = 0; j < 8; j++ )
      vid_stream->noise_base_matrix[i][j] *= vid_stream->noise_base_matrix[i][j];

  /* Go to next start code. */

  next_start_code(vid_stream);

  /*
   * If next start code is extension start code, parse off extension data.
   */

  if (next_bits(32, EXT_START_CODE, vid_stream)) {
    flush_bits32;
    if (vid_stream->ext_data != NULL) {
      free(vid_stream->ext_data);
      vid_stream->ext_data = NULL;
    }
    vid_stream->ext_data = get_ext_data(vid_stream);
  }
  /* If next start code is user start code, parse off user data. */

  if (next_bits(32, USER_START_CODE, vid_stream)) {
    flush_bits32;
    if (vid_stream->user_data != NULL) {
      free(vid_stream->user_data);
      vid_stream->user_data = NULL;
    }
    vid_stream->user_data = get_ext_data(vid_stream);
  }
  return PARSE_OK;
}