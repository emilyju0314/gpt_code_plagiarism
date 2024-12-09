void CNRGmatrix::SaveBinary(char filename[]){

  //
  // Saves actually: < c+ + c > (Hermitian)
  //

  FILE *pFile;
  int i,j;
  double auxEl=0.0;

  pFile=fopen(filename,"wb");
  for (i=0;i<Nstates();i++)
    {
      for (j=0;j<Nstates();j++)
	{
	  auxEl=GetMatEl(i,j); 
	  fwrite (&auxEl, sizeof(double), 1 ,pFile); 
	}
    }
  fclose(pFile);



}