unsigned int readbin(istream& in, unsigned char nbytes)
{
  // check for endianness
  int t = 1;
  bool le = (*(char *)&t == 1);
  // allocate buffer
  unsigned char buffer[4];
  for (int i = 0; i < 4; i++)
    buffer[i] = 0;
  
  // read into buffer
  for (int i = 0; i < nbytes; i++)
  {
    int index = i + (4-nbytes);
    if (le)
      index = nbytes-i - 1;
    in.read(recs(buffer+index), 1);
    if (in.bad())
      return -1;
  }
  return *(int*)(char*)(buffer);
}