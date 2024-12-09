void lsqr_error( char  *msg,
                 int   code  )
{
  fprintf(stderr, "\t%s\n", msg);
  exit(code);
}