uint32_t GetDeviceTraceBufferSize(uint32_t property)
{
  switch(property) {
    case 0 : return 8192;
    case 1 : return 1024;
    case 2 : return 2048;
    case 3 : return 4096;
    case 4 : return 16384;
    case 5 : return 32768;
    case 6 : return 65536;
    case 7 : return 131072;
    default : break;
  }
  return 8192;
}