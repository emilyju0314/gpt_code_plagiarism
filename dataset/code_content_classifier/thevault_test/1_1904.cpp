unsigned char b2i(char base)
{
  switch (base)
  {
    case 'A' : return 0;
    case 'C' : return 1;
    case 'G' : return 2;
    case 'T' : return 3;
    case '$' : return 4;

    default: 
      cerr << "Unknown base: " << base << endl;
      return b2i('A');
  };
}