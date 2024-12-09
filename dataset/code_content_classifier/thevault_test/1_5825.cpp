double CNRGmatrix::CalcTrace(){

  double trace=0.0;
 
  vector<int>::iterator it;

  it=MatBlockMap.begin();
  int iMatBlock=0;
  while ( it< MatBlockMap.end() ){
    int ibl1=*it;
    int ibl2=*(it+1);
    // Only diagonal blocks
    if (ibl1==ibl2){
      int i0=GetMatBlockLimit(iMatBlock, 0);
      int Nbl1=CNRGarray::GetBlockSize(ibl1);
      for (int iel=0;iel<Nbl1;iel++){
	int rbl=ij2rNSq(Nbl1,Nbl1,iel,iel); // Gets the diagonal element
	if (UpperTriangular){
	  rbl=ij2rUpTr(Nbl1,iel,iel);
	}
	trace+=MatEl[i0+rbl];
      } 
      // iel index states within the block (starting from 0)
    }
    // if diagonal, loop over MatBlock
    iMatBlock++;
    it=it+2;
  }
  // end while

  return(trace);
}