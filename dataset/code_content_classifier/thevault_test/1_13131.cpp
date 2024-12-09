MPESynthesiserBase::MPESynthesiserBase()
    : instrument (new MPEInstrument),
      sampleRate (0),
      minimumSubBlockSize (32),
      subBlockSubdivisionIsStrict (false)
{
    instrument->addListener (this);
}