bool ConvertFortranStringToCString(char* fortranString, int fortranStringLength,
                                   char* cString, int cStringMaxLength)
{
  if(fortranStringLength >= cStringMaxLength)
    {
    return false;
    }

  for(int i=0;i<fortranStringLength;i++)
    {
    cString[i] = fortranString[i];
    }
  cString[fortranStringLength] = '\0';
  return true;
}