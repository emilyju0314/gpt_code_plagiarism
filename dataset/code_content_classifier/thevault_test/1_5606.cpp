static inline Uint32 audio_header(Uint8 * pointer, Uint32 * framesize, double * frametime)
{
  Uint32 layer, version, frequency, bitrate, mode, padding, size;

  if(((pointer[0] & 0xff) != 0xff) || // No sync bits
     ((pointer[1] & 0xf0) != 0xf0) || //
     ((pointer[2] & 0xf0) == 0x00) || // Bitrate is 0
     ((pointer[2] & 0xf0) == 0xf0) || // Bitrate is 15
     ((pointer[2] & 0x0c) == 0x0c) || // Frequency is 3
     ((pointer[1] & 0x06) == 0x00))   // Layer is 4
     return(0);

  layer = 4 - (((pointer)[1] >> 1) & 3);
  version = (((pointer)[1] >> 3) & 1) ^ 1;
  padding = ((pointer)[2] >> 1) & 1;
  frequency = audio_frequencies[version][(((pointer)[2] >> 2) & 3)];
  bitrate = audio_bitrate[version][layer-1][(((pointer)[2] >> 4) & 15)];
  mode = ((pointer)[3] >> 6) & 3;

  if(layer==1)
  {
      size = 12000 * bitrate / frequency;
      if(frequency==0 && padding) size++;
      size <<= 2;
  }
  else
  {
      size = 144000 * bitrate / (frequency<<version);
      if(padding) size++;
  }
  if(framesize) *framesize = size;
  if(frametime) *frametime = 8.0 * size / (1000. * bitrate);
  
  return(4); /* Audio header size */
}