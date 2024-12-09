U32 HD44780Analyzer::TimeToSamplesOrMore(double AS)
{
  AS*=mSampleRateHz;
  if (((U32)AS)==AS)
    return (U32)AS;
  else return (U32)AS+1;
}