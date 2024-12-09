void HugeInteger::shrink_to_fit() {
  int *buffer = new int[size];
  for (unsigned int i = 0; i < size; i++)
    buffer[i] = elems[i];
  delete[] elems;
  elems = buffer;
}