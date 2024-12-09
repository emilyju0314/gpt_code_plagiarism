BufferingAudioSource::BufferingAudioSource (PositionableAudioSource* s,
                                            TimeSliceThread& thread,
                                            const bool deleteSourceWhenDeleted,
                                            const int bufferSizeSamples,
                                            const int numChannels,
                                            bool prefillBufferOnPrepareToPlay)
    : source (s, deleteSourceWhenDeleted),
      backgroundThread (thread),
      numberOfSamplesToBuffer (jmax (1024, bufferSizeSamples)),
      numberOfChannels (numChannels),
      bufferValidStart (0),
      bufferValidEnd (0),
      nextPlayPos (0),
      sampleRate (0),
      wasSourceLooping (false),
      isPrepared (false),
      prefillBuffer (prefillBufferOnPrepareToPlay)
{
    jassert (source != nullptr);

    jassert (numberOfSamplesToBuffer > 1024); // not much point using this class if you're
                                              //  not using a larger buffer..
}