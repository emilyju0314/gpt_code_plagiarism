void HugeInteger::input(istream &inFile) {
  char numericString[200];

  inFile >> numericString;

  size = strlen(numericString);
  if (size > 0) {
    delete[] elems;
    elems = new int[size];
    for (unsigned int i = 0; i < size; i++)
      elems[size - i - 1] = numericString[i] - '0';
  }
}