void customGDALErrorHandler(CPLErr err, int n, const char *msg)
{
  if (err == CE_Failure || err == CE_Fatal)
  {
    CPLDefaultErrorHandler(err, n, msg);
  }
}