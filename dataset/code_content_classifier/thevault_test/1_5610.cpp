void correct_underflow( VidStream* vid_stream )
{
  int status;

  status = get_more_data(vid_stream);

  if (status  < 0) {
    if (!quietFlag) {
      fprintf (stderr, "\n");
      perror("Unexpected read error.");
    }
    exit(1);
  }
  else if ((status == 0) && (vid_stream->buf_length < 1)) {
    if (!quietFlag) {
      fprintf(stderr, "\nImproper or missing sequence end code.\n");
    }
#ifdef ANALYSIS
    PrintAllStats(vid_stream);
#endif

    vid_stream->film_has_ended=TRUE;
    return;
  }
#ifdef UTIL2
  vid_stream->curBits = *vid_stream->buffer << vid_stream->bit_offset;
#else
  vid_stream->curBits = *vid_stream->buffer;
#endif

}