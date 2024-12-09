int vtkGenericEnSightReader2::ReadNextDataLine(char result[256])
{
  int isComment = 1;
  int value = 1;

  while( isComment && value )
    {
    value = this->ReadLine(result);
    if( *result && result[0] != '#' )
      {
      size_t len = strlen( result );
      unsigned int i = 0;
      while( i < len && (static_cast<unsigned int>(result[i]) <= 255) && isspace(result[i]) )
        {
        ++i;
        }
      // If there was only space characters this is a comment, thus skip it
      if( i != len )
        {
        // The line was not empty, not begining by '#' and not composed
        // of only white space, this is not a comment
        isComment = 0;
        }
      }
    }

  return value;
}