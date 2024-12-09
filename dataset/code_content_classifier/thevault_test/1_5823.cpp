int TwoChQSNoSz_SetSingleSite(CNRGbasisarray* pSingleSite){

  pSingleSite->NQNumbers=2;
  pSingleSite->Nshell=0;
  // new
  pSingleSite->totalS=true;
  pSingleSite->Sqnumbers.push_back(1);


  // 16 states divided in 6 Q,S blocks
  // with Sz entering in iDegen (Sz=10*iDegen)


  // -2 0 : | 0 0>
  pSingleSite->QNumbers.push_back(-2.0);
  pSingleSite->QNumbers.push_back(0.0);

  pSingleSite->BlockBegEnd.push_back(0);
  pSingleSite->BlockBegEnd.push_back(0);

  pSingleSite->iDegen.push_back(0); // Sz=0

  // -1 1/2 : | 0 up> and | up 0> ; | 0 dn> and | dn 0> 

  pSingleSite->QNumbers.push_back(-1.0);
  pSingleSite->QNumbers.push_back(0.5);

  pSingleSite->BlockBegEnd.push_back(1);
  pSingleSite->BlockBegEnd.push_back(4);

  pSingleSite->iDegen.push_back(5); // Sz=0.5  
  pSingleSite->iDegen.push_back(5); // Sz=0.5
  pSingleSite->iDegen.push_back(-5); // Sz=-0.5  
  pSingleSite->iDegen.push_back(-5); // Sz=-0.5


  // 0 0 : 1/sqrt(2)(| up dn>-| dn up>); | 0 up dn>; | up dn 0>; 

  pSingleSite->QNumbers.push_back(0.0);
  pSingleSite->QNumbers.push_back(0.0); // includes Singlet

  pSingleSite->BlockBegEnd.push_back(5);
  pSingleSite->BlockBegEnd.push_back(7);

  pSingleSite->iDegen.push_back(0); // Sz=0
  pSingleSite->iDegen.push_back(0); // Sz=0
  pSingleSite->iDegen.push_back(0); // Sz=0


  // 0 1 : | dn dn> ;  1/sqrt(2)(| up dn>+| dn up>) ;  | up up> 

  pSingleSite->QNumbers.push_back(0.0);
  pSingleSite->QNumbers.push_back(1.0); // Triplet

  pSingleSite->BlockBegEnd.push_back(8);
  pSingleSite->BlockBegEnd.push_back(10);

  pSingleSite->iDegen.push_back(-10); // Sz=0
  pSingleSite->iDegen.push_back(0); // Sz=0
  pSingleSite->iDegen.push_back(10); // Sz=0


  // 1 1/2 : | up  up dn>; | up dn   up> ; | dn  up dn>; | up dn   dn> 

  pSingleSite->QNumbers.push_back(1.0);
  pSingleSite->QNumbers.push_back(0.5);

  pSingleSite->BlockBegEnd.push_back(11);
  pSingleSite->BlockBegEnd.push_back(14);

  pSingleSite->iDegen.push_back(5); // Sz=0.5  
  pSingleSite->iDegen.push_back(5); // Sz=0.5
  pSingleSite->iDegen.push_back(-5); // Sz=-0.5  
  pSingleSite->iDegen.push_back(-5); // Sz=-0.5


  // 2 0 : | up dn  up dn>

  pSingleSite->QNumbers.push_back(2.0);
  pSingleSite->QNumbers.push_back(0.0);

  pSingleSite->BlockBegEnd.push_back(15);
  pSingleSite->BlockBegEnd.push_back(15);

  pSingleSite->iDegen.push_back(0); // Sz=0


  // Type labels the state
  for (int ii=0;ii<16;ii++){
    pSingleSite->iType.push_back(ii);
    // New and useful...
    pSingleSite->StCameFrom.push_back(ii);
  }


  return(0);
}