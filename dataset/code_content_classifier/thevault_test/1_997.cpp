inline int_u8 ntohll (int_u8 bytes)
{
  int_u8 check = 1;
  char *check1 = reinterpret_cast<char*>(&check);
  if (*check1==1) {
    // This is little-endian machine, have to convert to big
    char *look = reinterpret_cast<char*>(&bytes);
    swap(look[0], look[7]);
    swap(look[1], look[6]);
    swap(look[2], look[5]);
    swap(look[3], look[4]);
    return bytes;
  } else {
    // Big endian, do nothing
    return bytes;
  }
}