int IRSendRev::decode(decode_results *results)
{
  //results->rawbuf = irparams.rawbuf;
  //results->rawlen = irparams.rawlen;
  if (irparams.rcvstate != STATE_STOP)
  {
    return ERR;
  }
  // Throw away and start over
  //modified:
  ClearNew();
  // end modified
  return 1;
}