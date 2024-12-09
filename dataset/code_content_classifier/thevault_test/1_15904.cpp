int16 KaxCluster::GetBlockLocalTimecode(uint64 aGlobalTimecode) const
{
  int64 TimecodeDelay = (int64(aGlobalTimecode) - int64(GlobalTimecode())) / int64(GlobalTimecodeScale());
  assert(TimecodeDelay >= int16(0x8000) && TimecodeDelay <= int16(0x7FFF));
  return int16(TimecodeDelay);
}