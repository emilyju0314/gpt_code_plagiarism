SubregionStream::SubregionStream (InputStream* const sourceStream,
                                  const int64 start, const int64 length,
                                  const bool deleteSourceWhenDestroyed)
  : source (sourceStream, deleteSourceWhenDestroyed),
    startPositionInSourceStream (start),
    lengthOfSourceStream (length)
{
    SubregionStream::setPosition (0);
}