unsigned char IRSendRev::IsDta()
{
  //modified:
  return ((MessageCharCount != 0) ? 1 : 0);
  // end modified
}