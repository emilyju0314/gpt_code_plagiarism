ResamplingAudioSource::ResamplingAudioSource (AudioSource* const inputSource,
                                              const bool deleteInputWhenDeleted,
                                              const int channels)
    : input (inputSource, deleteInputWhenDeleted),
      ratio (1.0),
      lastRatio (1.0),
      bufferPos (0),
      sampsInBuffer (0),
      subSampleOffset (0),
      numChannels (channels)
{
    jassert (input != nullptr);
    zeromem (coefficients, sizeof (coefficients));
}