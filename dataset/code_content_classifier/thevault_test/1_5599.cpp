static int ParsePicture( VidStream* vid_stream, TimeStamp time_stamp )
{
  unsigned int data;
  int i;

  /* Flush header start code. */
  flush_bits32;

  /* This happens if there is a picture code before a sequence start */
  if (vid_stream->ring[0] == NULL) {
    printf("Warning: picture block before sequence header block\n");
    return SKIP_PICTURE;
  }

  /* Parse off temporal reference. */
  get_bits10(data);
  vid_stream->picture.temp_ref = data;

  /* Parse of picture type. */
  get_bits3(data);
  vid_stream->picture.code_type = data;

  if ((vid_stream->picture.code_type == B_TYPE) &&
      ((vid_stream->future == NULL) ||
       ((vid_stream->past == NULL) && !(vid_stream->group.closed_gop))))
    /* According to 2-D.5.1 (p D-18) this is ok, if the refereneces are OK */
    return SKIP_PICTURE;

  if ((vid_stream->picture.code_type == P_TYPE) && (vid_stream->future == NULL))
    return SKIP_PICTURE;

#ifdef ANALYSIS
  StartTime();
  stat_a[0].frametype = vid_stream->picture.code_type;
  stat_a[0].number = 1;
  stat_a[0].totsize = 45;
  pictureSizeCount = bitCountRead();
#endif

  /* Parse off vbv buffer delay value. */
  get_bits16(data);
  vid_stream->picture.vbv_delay = data;

  /* If P or B type frame... */

  if ((vid_stream->picture.code_type == P_TYPE) || 
      (vid_stream->picture.code_type == B_TYPE)) {

    /* Parse off forward vector full pixel flag. */
    get_bits1(data);
    if (data) {
      vid_stream->picture.full_pel_forw_vector = TRUE;
    } else {
      vid_stream->picture.full_pel_forw_vector = FALSE;
    }

    /* Parse of forw_r_code. */
    get_bits3(data);

    /* Decode forw_r_code into forw_r_size and forw_f. */

    vid_stream->picture.forw_r_size = data - 1;
    vid_stream->picture.forw_f = (1 << vid_stream->picture.forw_r_size);
  }
  /* If B type frame... */

  if (vid_stream->picture.code_type == B_TYPE) {

    /* Parse off back vector full pixel flag. */
    get_bits1(data);
    if (data)
      vid_stream->picture.full_pel_back_vector = TRUE;
    else
      vid_stream->picture.full_pel_back_vector = FALSE;

    /* Parse off back_r_code. */
    get_bits3(data);

    /* Decode back_r_code into back_r_size and back_f. */

    vid_stream->picture.back_r_size = data - 1;
    vid_stream->picture.back_f = (1 << vid_stream->picture.back_r_size);
  }
  /* Get extra bit picture info. */

  if (vid_stream->picture.extra_info != NULL) {
    free(vid_stream->picture.extra_info);
    vid_stream->picture.extra_info = NULL;
  }
  vid_stream->picture.extra_info = get_extra_bit_info(vid_stream);

  /* Goto next start code. */
  next_start_code(vid_stream);

  /* If start code is extension start code, parse off extension data. */

  if (next_bits(32, EXT_START_CODE, vid_stream)) {
    flush_bits32;

    if (vid_stream->picture.ext_data != NULL) {
      free(vid_stream->picture.ext_data);
      vid_stream->picture.ext_data = NULL;
    }
    vid_stream->picture.ext_data = get_ext_data(vid_stream);
  }
  /* If start code is user start code, parse off user data. */

  if (next_bits(32, USER_START_CODE, vid_stream)) {
    flush_bits32;

    if (vid_stream->picture.user_data != NULL) {
      free(vid_stream->picture.user_data);
      vid_stream->picture.user_data = NULL;
    }
    vid_stream->picture.user_data = get_ext_data(vid_stream);
  }

  /* Find a pict image structure in ring buffer not currently locked. */

  i = 0;

  while (vid_stream->ring[i]->locked != 0) {
    if (++i >= RING_BUF_SIZE) {
      perror("Fatal error. Ring buffer full.");
      exit(1);
    }
  }

  /* Set current pict image structure to the one just found in ring. */

  vid_stream->current = vid_stream->ring[i];

  /* Set time stamp. */

  vid_stream->current->show_time = time_stamp;

  /* Reset past macroblock address field. */

  vid_stream->mblock.past_mb_addr = -1;

  return PARSE_OK;
}