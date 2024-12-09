void CClientPIC::EatLine (FILE *fp)
{
  // check if line begins with '//'
  for (;;)
    {
      char c1, c2;
      fread (&c1, 1, 1, fp);
      fread (&c2, 1, 1, fp);
      
      if (c1 == '/' && c2 == '/')
	{
	  do
	    {
	      fread (&c1, 1, 1, fp);
	    }
	  while (c1 != '\n' && !feof(fp));
	}
      else
	{
	  fseek (fp, -2, SEEK_CUR);
	  return;         // exit from here.
	}
    }
}