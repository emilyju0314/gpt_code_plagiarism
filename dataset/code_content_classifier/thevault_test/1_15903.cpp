uint64 KaxCluster::GlobalTimecode() const
{
  assert(bPreviousTimecodeIsSet);
  uint64 result = MinTimecode;

  if (result < PreviousTimecode)
    result = PreviousTimecode + 1;

  return result;
}