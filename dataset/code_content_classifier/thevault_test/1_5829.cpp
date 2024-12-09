void CNRGmatrix::PutInRegularForm(int iblock){

  // Get block info
  int iMatBlock=FindMatBlock(iblock,iblock);

  if (iMatBlock<0)
    {
      cout << "PutInDiagForm: Cannot find block " 
	   << iblock << endl;
      return;
    }
  int NstSq=GetMatBlockSize(iMatBlock);
  int Nst=GetBlockSize(iblock);
  int iblBeg=GetMatBlockLimit(iMatBlock,0);

  // Set "unscrambled" array

  double *BlArray = new double [NstSq];
  int i1,j1,ipos;

  for (int ii=0;ii<NstSq;ii++)
    {
      // Get corresponding i,j (new)
      r2ij(Nst,ii,i1,j1);
      // Get Pmn
      ipos=Pmn(Nst,i1,j1); //(old)
      BlArray[ii]=MatEl[iblBeg+ipos];
    }

  // Unscramble
   for (int ii=0;ii<NstSq;ii++)
     MatEl[iblBeg+ii]=BlArray[ii];

  delete[] BlArray;

}