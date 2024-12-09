const char *fl_filename_name( const char *name ) 
{
  const char *p, *q;
  if (!name) return (0);
  for ( p = q = name ; *p ; ) 
  {
    if ( ( p[0] == ':' ) && ( p[1] == ':' ) ) 
    {
      q = p+2;
      p++;
    }
    else if (p[0] == '/')
      q = p + 1;
    p++;
  }
  return q;
}