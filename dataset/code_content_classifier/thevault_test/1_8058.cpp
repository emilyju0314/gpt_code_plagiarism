bool AvikPIDNew::calculateVadimSlope(const KalRep  *KRep  ,
				       double        *Slope ,
				       double        *Eslope) {
    
    std::vector<double>   res, flt, eres, eflt;
    mu2e::TrkStrawHit*    hit;
    double                resid, residerr, aresd, normflt, normresd;
    TrkHitVector const&   hotList = KRep->hitVector();

    for (auto ihot=hotList.begin(); ihot != hotList.end(); ++ihot) {
      hit = (mu2e::TrkStrawHit*) (*ihot);
      if (hit->isActive()) {
//-----------------------------------------------------------------------------
// 'unbiased' residual, signed with the radius - if the drift radius is greater than
// the track-to-wire distance, the residual is positive (need to double check the sign!)
// use active hits only
//-----------------------------------------------------------------------------
        hit->resid(resid,residerr,true);

        aresd    = (hit->poca().doca()>0?resid:-resid);
        normflt  = hit->fltLen() -  KRep->flt0();
        normresd = aresd/residerr;

        res.push_back(normresd);
        flt.push_back(normflt);
        eres.push_back(1.);
        eflt.push_back(0.1);
      }
    }

    error = new TGraphErrors(res.size(),flt.data(),res.data(),eflt.data(),eres.data());

    _minuit->SetPrintLevel(-1);
    _minuit->SetFCN(myfcn);

    const int dim(2);
    const char      par_name[dim][20]= {"offset","slope"};
    static Double_t step    [dim]    = {0.001,0.001};
    Double_t        sfpar   [dim]    = {0.0,0.005};
    Double_t        errsfpar[dim]    = {0.0,0.0};

    int ierflg = 0;
    for (int ii = 0; ii<dim; ii++) {
      _minuit->mnparm(ii,par_name[ii],sfpar[ii], step[ii], 0,0,ierflg);
    }

    _minuit->FixParameter(0);
    _minuit->Migrad();

    bool converged = _minuit->fCstatu.Contains("CONVERGED");
    if (!converged)
      {
        cout <<"-----------TOF Linear fit did not converge---------------------------" <<endl;
        return converged;
      }
    for (int i = 0;i<dim;i++) {
      _minuit->GetParameter(i,sfpar[i],errsfpar[i]);
    }

    *Slope  = sfpar[1];
    *Eslope = errsfpar[1];

    delete error;

    return converged;
  }