void
writeTridiagSymMatlab( const char* filename,
                       float* d, float* s, 
                       float* eigenvals, 
                       const unsigned int n )
{
  std::ofstream file( filename, std::ios::out);

  // write diagonal entries
  writeVectorMatlab( file, "d", d, n);

  // write superdiagonal entries
  writeVectorMatlab( file, "s", s, n-1);

  // write eigenvalues
  writeVectorMatlab( file, "eigvals", eigenvals, n);

  file.close();
}