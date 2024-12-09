void AvikPID::calculateOsSums(const vector<Doublet>* ListOfDoublets,
                                double& Drds, double& DrdsErr, int& NUsedHits,
                                double& Sum , int& NUsedDoublets) {

    vector<double> fltLen;
    vector<double> resid;
    const Doublet* multiplet;
//-----------------------------------------------------------------------------
// calculate slopes using OS doublets
//-----------------------------------------------------------------------------
    AddOsMultiplets(ListOfDoublets,fltLen,resid);
    CalculateSlope(fltLen,resid,Drds,DrdsErr);
    NUsedHits = fltLen.size();

    NUsedDoublets = 0;
    Sum           = 0.;

    int nnlets    = ListOfDoublets->size();
    int ndblts    = 0.;

    for (int i=0; i<nnlets; i++) {
      multiplet    = &ListOfDoublets->at(i);
      int nhits    = multiplet->fNStrawHits;
      if (nhits >= 2) {
        ndblts += 1;
        if (! multiplet->isSameSign()) {
          double ddxdz    = multiplet->bestDxDzRes();
          if (fabs(ddxdz) < _maxDeltaDxDzOs) {
//          double residsq = 0;
//          if (abs(dxdzresid) < _bound) residsq = (1/pow(_bound, _pow1))*pow(abs(dxdzresid), _pow1);
//          else residsq   = (1/pow(_bound, _pow1))*pow(_bound, (_pow1 - _pow2))*pow(abs(dxdzresid), _pow2);
            double dr2     = weightedSlopeResidual(ddxdz);
            Sum           += dr2;
            NUsedDoublets += 1.;
          }
        }
      }
    }
  }