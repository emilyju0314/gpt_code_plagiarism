double TwoChQS_d_fd_MatEl(vector<double> Params,
			  CNRGbasisarray* pAbasis, 
			  CNRGbasisarray* pSingleSite,
			  CNRGmatrix* MatArray,
			  int ist, int jst)
{

  //
  // Calculates sum_{sigma} <ist| d_{sigma} f+_{0 ich sigma} + h.c |jst>
  // 
  // Two channels with Q,S symmetry
  //
  //  - ich=1 or 2 is the first input in Params 
  //  - ist!=jst (returns zero otherwise)
  //  - MatArray[0] carries the REDUCED <istcf || d || jstcf> elements

  int ich=(int)Params[0];

  if ( (ich!=1)&&(ich!=2) ) 
    {
      cout << " d_fd_MatEl: Invalid channel choice" << endl;
      return(0.0);
    }

  if (ist==jst) return(0.0); //Off-diagonal terms only


  double Qi=pAbasis->GetQNumberFromSt(ist,0);
  double Si=pAbasis->GetQNumberFromSt(ist,1);   

  double Qj=pAbasis->GetQNumberFromSt(jst,0);
  double Sj=pAbasis->GetQNumberFromSt(jst,1);   

  if (dNEqual(Qi,Qj)||dNEqual(Si,Sj)) return(0.0);

  double HmatEl=0.0;
  
  int type_i=pAbasis->iType[ist];
  int type_j=pAbasis->iType[jst];

  // Reduced matrix element from <istcf| d | jstcf>
  double OldEl=MatArray[0].GetMatEl(pAbasis->StCameFrom[ist],
				    pAbasis->StCameFrom[jst]);
  int typep=type_i;
  int type=type_j;

  // if zero, try the h.c term
  if (dEqual(OldEl,0.0))
    {
      OldEl=MatArray[0].GetMatEl(pAbasis->StCameFrom[jst],
				 pAbasis->StCameFrom[ist]);
      typep=type_j;
      type=type_i;
    }

  // Get SingleSite QNumbers
  int pos=0;
  int iblssp=pSingleSite->GetBlockFromSt(typep,pos);
  int iblss=pSingleSite->GetBlockFromSt(type,pos);

  double Qtildep=pSingleSite->GetQNumber(iblssp,0);
  double Stildep=pSingleSite->GetQNumber(iblssp,1);
  double Sztildep=pSingleSite->GetQNumber(iblssp,2);


  double Qtilde=pSingleSite->GetQNumber(iblss,0);
  double Stilde=pSingleSite->GetQNumber(iblss,1);
  double Sztilde=pSingleSite->GetQNumber(iblss,2);

  double Soldp=Si-Sztildep;
  double Sold=Si-Sztilde;


  // Check Fermi Sign
  double FermiSign=1.0;
  // will be -1 if only one of them is zero (A XOR B)
  // 

  if ( (dEqual(Qtilde,1.0)||dEqual(Qtilde,-1.0))&&
       (dEqual(Sztilde,0.5)||dEqual(Sztilde,-0.5)) ) FermiSign=-1.0;
  // Fermi sign appears IF there is an 
  // odd number of fermionic ops in site state 
  // Only one electron "alone" in one channel, 
  // e.g. |0 up> or |dn 0> (not |up dn>

  // now get
  // auxEl=sum_ch <fd_{ch 0 sigma} f_{-1 sigma}>
  // REMEMBER:
  // |Q S>_N+1 = sum <So Szo Stil Sztil|SS>|QoSo>|Qtil Stil>

  // NO Loop in channels


  double auxCG[]={0.0,0.0,0.0,0.0};
  double siteqnumsp[]={Qtildep,Stildep,Sztildep};
  double siteqnums[]={Qtilde,Stilde,Sztilde};
  // Loop in sigma
  for (int sigma=-1;sigma<=1;sigma+=2)
    {
      double dSigma=0.5*(double)sigma;

      // Loop in Szold
      for (double Szold=Sold;Szold>=-Sold;Szold-=1.0)
	{
	  double Szoldp=Szold-dSigma;
	  Sztilde=Si-Szold;
	  Sztildep=Sztilde+dSigma;
	  // Changing dSigma changes Sztildep
	  // Need an extra loop in the "p" block

	  // Site matrix element: finds the block
	  siteqnums[2]=Sztilde;
	  siteqnumsp[2]=Sztildep;
	  int siteblock=pSingleSite->GetBlockFromQNumbers(siteqnums);
	  int siteblockp=pSingleSite->GetBlockFromQNumbers(siteqnumsp);

  
	  if ( (siteblock<pSingleSite->NumBlocks())&&
	       (siteblockp<pSingleSite->NumBlocks())&&
	       (dLEqual(fabs(Sztilde),Stilde))&&
	       (dLEqual(fabs(Sztildep),Stildep))&&
	       (dLEqual(fabs(Szold),Sold))&&
	       (dLEqual(fabs(Szoldp),Soldp)) )
	    {
	      // CG coefs
	      auxCG[0]=CGordan(Sold,Szold,
			       Stilde,Sztilde,
			       Si,Si);				 

	      auxCG[1]=CGordan(Soldp,Szoldp,
			       Stildep,Sztildep,
			       Si,Si);

	      auxCG[2]=CGordan(Soldp,Szoldp,
			       0.5,dSigma,
			       Sold,Szold);

// 	      cout << " Stilde = " << Stilde 
// 		   << " Sztilde = " << Sztilde
// 		   << " Stildep = " << Stildep 
// 		   << " Sztildep = " << Sztildep 
// 		   << endl;
				  
	      //Loop in site blocks!! Necessary!
	      for (int sitestatep=pSingleSite->GetBlockLimit(siteblockp,0);sitestatep<=pSingleSite->GetBlockLimit(siteblockp,1);sitestatep++)
		{
		  for (int sitestate=pSingleSite->GetBlockLimit(siteblock,0);sitestate<=pSingleSite->GetBlockLimit(siteblock,1);sitestate++)
		    {
		      double SpSm[2];
		      SpSm[0]=TwoChQS_SpSm_table(sitestate,type);
		      SpSm[1]=TwoChQS_SpSm_table(sitestatep,typep);
		      auxCG[3]=TwoChQS_fd_table(ich,sigma,
						sitestatep,sitestate);
 
		      HmatEl+=auxCG[0]*auxCG[1]*auxCG[2]*OldEl*auxCG[3]*FermiSign*SpSm[0]*SpSm[1];
		    }
		  // end loop in site block
		}
	      // end loop in site blockp
	    }
	  // END Calc coefs safeguard
	}
      // End loop in Szold
    }
  //END Sum in sigma


  return(HmatEl);

}