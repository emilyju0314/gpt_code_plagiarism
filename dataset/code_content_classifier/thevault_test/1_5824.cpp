void TwoChQSP_SetSingleSite(CNRGbasisarray &SingleSite){


  // two channels: Q,S,Sz and P (parity) basis:


  SingleSite.NQNumbers=4;
  SingleSite.Nshell=0;
  // new
  SingleSite.totalS=true;
  SingleSite.Sqnumbers.push_back(1);

  
  // 16 states divided in 10 blocks

  // -2 0 0 P=+1 : | 0 0>
  SingleSite.QNumbers.push_back(-2.0);
  SingleSite.QNumbers.push_back(0.0);
  SingleSite.QNumbers.push_back(0.0);
  SingleSite.QNumbers.push_back(1.0);


  SingleSite.BlockBegEnd.push_back(0);
  SingleSite.BlockBegEnd.push_back(0);

  // -1 1/2 1/2 P=-1 : | 0 up> 

  SingleSite.QNumbers.push_back(-1.0);
  SingleSite.QNumbers.push_back(0.5);
  SingleSite.QNumbers.push_back(0.5);
  SingleSite.QNumbers.push_back(-1.0);

  SingleSite.BlockBegEnd.push_back(1);
  SingleSite.BlockBegEnd.push_back(1);


  // -1 1/2 1/2 P=+1 : | up 0> 

  SingleSite.QNumbers.push_back(-1.0);
  SingleSite.QNumbers.push_back(0.5);
  SingleSite.QNumbers.push_back(0.5);
  SingleSite.QNumbers.push_back(1.0);

  SingleSite.BlockBegEnd.push_back(2);
  SingleSite.BlockBegEnd.push_back(2);


  // -1 1/2 -1/2 P=-1 : | 0 dn> 


  SingleSite.QNumbers.push_back(-1.0);
  SingleSite.QNumbers.push_back(0.5);
  SingleSite.QNumbers.push_back(-0.5);
  SingleSite.QNumbers.push_back(-1.0);

  SingleSite.BlockBegEnd.push_back(3);
  SingleSite.BlockBegEnd.push_back(3);

  // -1 1/2 -1/2 P=+1 : | dn 0> 


  SingleSite.QNumbers.push_back(-1.0);
  SingleSite.QNumbers.push_back(0.5);
  SingleSite.QNumbers.push_back(-0.5);
  SingleSite.QNumbers.push_back(1.0);

  SingleSite.BlockBegEnd.push_back(4);
  SingleSite.BlockBegEnd.push_back(4);


  // 0 0 0 P=-1 : 1/sqrt(2)(| up dn>-| dn up>); 

  SingleSite.QNumbers.push_back(0.0);
  SingleSite.QNumbers.push_back(0.0); // Singlet
  SingleSite.QNumbers.push_back(0.0);
  SingleSite.QNumbers.push_back(-1.0);

  SingleSite.BlockBegEnd.push_back(5);
  SingleSite.BlockBegEnd.push_back(5);


  // 0 0 0 P=1 : | 0 up dn>; | up dn 0>;


  SingleSite.QNumbers.push_back(0.0);
  SingleSite.QNumbers.push_back(0.0);
  SingleSite.QNumbers.push_back(0.0);
  SingleSite.QNumbers.push_back(1.0);

  SingleSite.BlockBegEnd.push_back(6);
  SingleSite.BlockBegEnd.push_back(7);
 


  // 0 1 -1 P=-1: | dn dn> 

  SingleSite.QNumbers.push_back(0.0);
  SingleSite.QNumbers.push_back(1.0); // Triplet
  SingleSite.QNumbers.push_back(-1.0);
  SingleSite.QNumbers.push_back(-1.0);

  SingleSite.BlockBegEnd.push_back(8);
  SingleSite.BlockBegEnd.push_back(8);


  // 0 1 0 P=-1: 1/sqrt(2)(| up dn>+| dn up>) 

  SingleSite.QNumbers.push_back(0.0);
  SingleSite.QNumbers.push_back(1.0); // Triplet
  SingleSite.QNumbers.push_back(0.0);
  SingleSite.QNumbers.push_back(-1.0);

  SingleSite.BlockBegEnd.push_back(9);
  SingleSite.BlockBegEnd.push_back(9);


  // 0 1 1 P=-1: | up up> 

  SingleSite.QNumbers.push_back(0.0);
  SingleSite.QNumbers.push_back(1.0); // Triplet
  SingleSite.QNumbers.push_back(1.0);
  SingleSite.QNumbers.push_back(-1.0);

  SingleSite.BlockBegEnd.push_back(10);
  SingleSite.BlockBegEnd.push_back(10);

  // 1 1/2 1/2 P=1: | up  up dn>;

  SingleSite.QNumbers.push_back(1.0);
  SingleSite.QNumbers.push_back(0.5);
  SingleSite.QNumbers.push_back(0.5);
  SingleSite.QNumbers.push_back(1.0);

  SingleSite.BlockBegEnd.push_back(11);
  SingleSite.BlockBegEnd.push_back(11);

  // 1 1/2 1/2 P=-1: | up dn   up> 

  SingleSite.QNumbers.push_back(1.0);
  SingleSite.QNumbers.push_back(0.5);
  SingleSite.QNumbers.push_back(0.5);
  SingleSite.QNumbers.push_back(-1.0);

  SingleSite.BlockBegEnd.push_back(12);
  SingleSite.BlockBegEnd.push_back(12);


  // 1 1/2 -1/2 P=1: | dn  up dn>

  SingleSite.QNumbers.push_back(1.0);
  SingleSite.QNumbers.push_back(0.5);
  SingleSite.QNumbers.push_back(-0.5);
  SingleSite.QNumbers.push_back(1.0);

  SingleSite.BlockBegEnd.push_back(13);
  SingleSite.BlockBegEnd.push_back(13);

  // 1 1/2 -1/2 P=-1: | up dn   dn> 

  SingleSite.QNumbers.push_back(1.0);
  SingleSite.QNumbers.push_back(0.5);
  SingleSite.QNumbers.push_back(-0.5);
  SingleSite.QNumbers.push_back(-1.0);

  SingleSite.BlockBegEnd.push_back(14);
  SingleSite.BlockBegEnd.push_back(14);

  // 2 0 0 P=+1: | up dn  up dn>

  SingleSite.QNumbers.push_back(2.0);
  SingleSite.QNumbers.push_back(0.0);
  SingleSite.QNumbers.push_back(0.0);
  SingleSite.QNumbers.push_back(1.0);

  SingleSite.BlockBegEnd.push_back(15);
  SingleSite.BlockBegEnd.push_back(15);


  // Type labels the state
  for (int ii=0;ii<16;ii++){
    SingleSite.iType.push_back(ii);
  }

  SingleSite.ChildStates.push_back( vector<int>());
  SingleSite.ChildStates.clear();  

  return;

}