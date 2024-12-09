U32 HD44780Analyzer::TimeToSamplesOrLess(double AS)
{
  AS*=mSampleRateHz;
  return (U32)AS;
}