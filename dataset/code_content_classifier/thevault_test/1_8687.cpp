static ink_hrtime
elapsed_from_start(int sock)
{
  ink_hrtime timenow = ink_get_hrtime_internal();
  return ink_hrtime_diff_msec(timenow, fd[sock].start);
}