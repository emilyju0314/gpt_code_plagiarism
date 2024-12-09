int CNRGmatrix::GetMatElPosition(int iblock1, int iblock2, int iel, int jel){

  int iMatBlock=FindMatBlock(iblock1,iblock2);

  // Watch out: if BlockBegEnd has "holes", iel or jel can be negative (state is not there)

  // iel,jel index states within the block (starting from 0)

  if ( (iMatBlock<0)||(iel<0)||(jel<0) ){
    // Message is harmless.
    //cout << " CNRGmatrix::GetMatElPosition: iMatBlock not found " << endl; 
    return(-1);
  }
  else{
    int i0=GetMatBlockLimit(iMatBlock, 0);
    int Nbl1=CNRGarray::GetBlockSize(iblock1);
    int Nbl2=CNRGarray::GetBlockSize(iblock2);
    int rbl=ij2rNSq(Nbl1,Nbl2,iel,jel);
    
    // watch out for this one!! 
    if ((UpperTriangular)&&(iblock1==iblock2)){
      if (iel>jel)
	rbl=ij2rUpTr(Nbl1,jel,iel);
      else
	rbl=ij2rUpTr(Nbl1,iel,jel);
    }
    return(i0+rbl);
  }

}