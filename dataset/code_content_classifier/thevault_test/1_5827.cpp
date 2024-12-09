void CNRGmatrix::PushMatEl(double El, int ist, int jst){
  int ibl,jbl;

  int iblock1=CNRGarray::GetBlockFromSt(ist,ibl);
  int iblock2=CNRGarray::GetBlockFromSt(jst,jbl);

  int iPos=GetMatElPosition(iblock1,iblock2,ibl,jbl);

//   if (iPos>-1) MatEl[iPos]=El;
  if (iPos>-1)
    if (IsComplex){MatElCplx[iPos]=(complex<double>)El;}
    else MatEl[iPos]=El;

  //PushBlockMatEl(El,iblock1,iblock2,ibl,jbl);

}