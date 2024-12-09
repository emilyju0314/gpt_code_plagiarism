void TwoChQS_SetH0CMphonon(vector<double> Params,CNRGbasisarray* pSingleSite,CNRGarray* pAeig,CNRGbasisarray* pAbasisH0,CNRGmatrix* NRGMats){


  // Parameters:

  double U_norm=Params[0];
  double ed_norm=Params[1];

  // Gamma_tilde = (2 Gamma/pi)/(1/2*(1+Lambda^-1))^2
  // Params[2] = sqrt(Gamma_tilde/Lambda) = chi_S
  // Change here: chi_S = Params[2], chi_A = alpha*Params[2]
  //double chi_N[2]={Params[2],Params[3]};
  double chi_N[2]={Params[2],Params[6]*Params[2]};

  double w0=Params[4];
  double lambda=Params[5];
  double alpha=Params[6];

  int Nph=(int)Params[7];

  double auxEl=0.0;


  cout << "e1 = " << U_norm << endl;
  cout << "e2 = " << ed_norm+U_norm << endl;
  cout << "e3 = " << 2.0*ed_norm+3.0*U_norm << endl;

  cout << "chi_N(S,A) = " << chi_N[0] << "  " << chi_N[1] << endl;

  cout << " w0 = " << w0 << endl;
  cout << " lambda = " << lambda << endl;
  cout << " alpha = " << alpha << endl;
  

  // Set H0

  pAeig->ClearAll();

  CNRGarray AeigHimp(2);

  // Set basis for Hm1
  AeigHimp.Nshell=-1;
  AeigHimp.NQNumbers=2; //(Q,S)

  // |0>  = |-1 0> 
  AeigHimp.QNumbers.push_back(-1.0);
  AeigHimp.QNumbers.push_back(0.0);
  AeigHimp.dEn.push_back(0.0);
  AeigHimp.BlockBegEnd.push_back(0);
  AeigHimp.BlockBegEnd.push_back(0);
  // |up> = |0 0.5> Simple as that (or |dn>)
  AeigHimp.QNumbers.push_back(0.0);
  AeigHimp.QNumbers.push_back(0.5);
  AeigHimp.BlockBegEnd.push_back(1);
  AeigHimp.BlockBegEnd.push_back(1);
  AeigHimp.dEn.push_back(0.0);
  // |up dn> = |1 0> 
  AeigHimp.QNumbers.push_back(1.0);
  AeigHimp.QNumbers.push_back(0.0);
  AeigHimp.BlockBegEnd.push_back(2);
  AeigHimp.BlockBegEnd.push_back(2);
  AeigHimp.dEn.push_back(0.0);
  //

  ////
  ////  Set the matrices
  ////

  CNRGmatrix MatArray[3];

  for (int imat=0; imat<3; imat++)
    MatArray[imat].SyncNRGarray(AeigHimp);

  //
  // MatArray[0]: Hm1 in the OLD basis
  //

  MatArray[0].MatEl.push_back(U_norm);
  MatArray[0].MatEl.push_back(ed_norm+U_norm);
  MatArray[0].MatEl.push_back(2.0*ed_norm+3.0*U_norm);

  // one state per block, diagonal
  for (int ii=0;ii<=2;ii++)
    {
      MatArray[0].MatBlockMap.push_back(ii);
      MatArray[0].MatBlockMap.push_back(ii);
      MatArray[0].MatBlockBegEnd.push_back(ii);
      MatArray[0].MatBlockBegEnd.push_back(ii);
    }

//   cout << " Hm1 : " << endl;
//   for (int ibl=0;ibl<MatArray[0].NumMatBlocks();ibl++)
//     MatArray[0].PrintMatBlock(ibl);

  //
  // MatArray[1]: (nd_sigma-1) in the OLD basis
  //

  MatArray[1].MatEl.push_back(-1.0);
  MatArray[1].MatEl.push_back(0.0);
  MatArray[1].MatEl.push_back(1.0);

  // one state per block, diagonal
  for (int ii=0;ii<=2;ii++)
    {
      MatArray[1].MatBlockMap.push_back(ii);
      MatArray[1].MatBlockMap.push_back(ii);
      MatArray[1].MatBlockBegEnd.push_back(ii);
      MatArray[1].MatBlockBegEnd.push_back(ii);
    }

  // MatArray[2]: reduced <||d||> elements in the OLD basis

  MatArray[2].MatEl.push_back(1.0);
  MatArray[2].MatBlockMap.push_back(0);
  MatArray[2].MatBlockMap.push_back(1);
  MatArray[2].MatBlockBegEnd.push_back(0);
  MatArray[2].MatBlockBegEnd.push_back(0);

  MatArray[2].MatEl.push_back(-sqrt(2.0));
  MatArray[2].MatBlockMap.push_back(1);
  MatArray[2].MatBlockMap.push_back(2);
  MatArray[2].MatBlockBegEnd.push_back(1);
  MatArray[2].MatBlockBegEnd.push_back(1);

  //
  // Add a site: N=0 basis 
  //

  pAbasisH0->NQNumbers=2;

  CNRGbasisarray ACut=CutStates(&AeigHimp, 100);
  QS_BuildBasis(&ACut,pAbasisH0,pSingleSite,1);


  // Add Phonons: simply copy blocks

  for (int ibl=0;ibl<pAbasisH0->NumBlocks();ibl++)
    pAbasisH0->CopyBlock(ibl,Nph);

//    pAbasisH0->PrintAll();

  // Add vectors to block basis
  // 3xNph states


  CNRGmatrix H0(*pAbasisH0);

  H0.NeedOld=false;
  H0.UpperTriangular=true;
  H0.CheckForMatEl=Diag_check;
  H0.CalcHNMatEl=TwoChQS_H0ph_MatEl;


  vector<double> ParamsH0;
  ParamsH0.push_back(chi_N[0]);
  ParamsH0.push_back(chi_N[1]);
  ParamsH0.push_back(w0);
  ParamsH0.push_back(lambda);
  ParamsH0.push_back(alpha);

  
  int ist=4;
   int jst=7;
   double testEl=H0.CalcHNMatEl(ParamsH0,pAbasisH0,pSingleSite,MatArray,ist,jst);

//    cout << " <" << ist << "|H0|" << jst << "> = " << testEl <<endl; 

//    for (ist=8;ist<=19;ist++)
//      {
//        for (jst=8;jst<=19;jst++)
// 	 {
//     testEl=H0.CalcHNMatEl(ParamsH0,pAbasisH0,pSingleSite,MatArray,ist,jst);
//     cout << " <" << ist << "|H0|" << jst << "> = " << testEl <<endl; 
// 	 }
//      }

   H0.DiagHN(ParamsH0,pAbasisH0,pSingleSite,MatArray,pAeig);

//    int ibl=1;
//    pAbasisH0->PrintBlockBasis(ibl);
//    H0.PrintMatBlock(ibl,ibl);

//    ibl=8;
//    pAbasisH0->PrintBlockBasis(ibl);
//    H0.PrintMatBlock(ibl,ibl);
   


}