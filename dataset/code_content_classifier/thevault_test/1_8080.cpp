void CalHelixFinderAlg::plotZPhi(int ISet) {

    TCanvas* c;
    int      color;
    TMarker* m;
    char     name[200];
//-----------------------------------------------------------------------------
// retrieve the data points for storing in TGraphs
//-----------------------------------------------------------------------------
    std::vector<mu2e::ComboHit>* xyzp = {0};
    CalHelixFinderData*          helx;

    if ((ISet >=0 ) && (ISet < 6)) {
      //      xyzp   = &_results[ISet]._xyzp;
      helx   = &_results[ISet]._helix;
    }
    else {
      printf("ISet = %i undefined, return\n",ISet);
      return;
    }

    int nhits = xyzp->size();

    printf("nhits = %10i\n",nhits);

    mu2e::ComboHit* hit;

    XYZVectorF* pos;

    float x[1000], y[1000];
    float z[1000], phi[1000], phi1[1000];

    int    flag[1000];

    for (int i=0; i<nhits; i++) {
      hit = & xyzp->at(i);
      pos = & hit->_pos;

      x[i]    = hit->_pos.x();
      y[i]    = hit->_pos.y();
      z[i]    = hit->_pos.z();
      flag[i] = *((int*) &hit->_flag);
      phi [i] = polyAtan2(hit->_pos.y(), hit->_pos.x());//hit->_pos.phi();

      phi1[i] = polyAtan2(y[i]-helx->_center.y(),x[i]-helx->_center.x());

      printf("i: %3i ind: %5i x: %10.3f y: %10.3f z: %10.3f phi: %10.3f phi1: %10.3f 0x%08x %5i\n",
	     i,(int) hit->index(),
	     pos->x(),pos->y(),pos->z(),phi[i],phi1[i],
	     flag[i], hit->_flag.hasAllProperties(StrawHitFlag::outlier));
    }

//-----------------------------------------------------------------------------
// straight line in RPhi out of the fit
//-----------------------------------------------------------------------------
    float phi0 = helx->_fz0;
    float dfdz = helx->_dfdz;

    sprintf(name,"c_plot_hits_phiz_%i",ISet);

    c = (TCanvas*) gROOT->GetListOfCanvases()->FindObject(name);

    if (c != NULL) delete c;

    c = new TCanvas(name,Form("c_phiz %i",ISet),1200,1000);
    c->Divide(1,2);
//-----------------------------------------------------------------------------
// plot PHI-Z picture
//-----------------------------------------------------------------------------
    c->cd(1);
    gPad->SetGrid();

    TH2F* h2_phiz = new TH2F("h2_phiz",Form("phiZ VIEW %i",ISet),2200,-1600,2800,80,-20,20);
    h2_phiz->SetStats(0);
    h2_phiz->Draw();

    for (int i=0; i<nhits; i++) {
      hit = &xyzp->at(i);
//-----------------------------------------------------------------------------
// predict phi at this Z to resolve 2pi ambiguities
//-----------------------------------------------------------------------------
      float pred = phi0+dfdz*z[i];
      float phib = phi1[i];

      while (phib-pred >  M_PI) phib -= 2*M_PI;
      while (phib-pred <- M_PI) phib += 2*M_PI;

      m   = new TMarker(z[i],phib,2);

      if (hit->_flag.hasAllProperties(StrawHitFlag::outlier)) color = kBlack;
      else                  color = kRed;

      m->SetMarkerColor(color);
      m->SetMarkerSize(0.7);
      m->Draw();
    }

    TF1 *yf = new TF1("yf","[0]+x*[1]",-1600., 2800.);
    yf->SetParameters(phi0, dfdz);
    yf->SetLineWidth(1);
    yf->Draw("same");
//-----------------------------------------------------------------------------
// plot residuals from the straight line fit
//-----------------------------------------------------------------------------
    c->cd(2);
    gPad->SetGrid();

    TH2F* h22_phiz = new TH2F("h22_phiz",Form("Delta(phi) Vs Z, VIEW %i",ISet),2200,-1600,2800,200,-1,1);
    h22_phiz->SetStats(0);
    h22_phiz->Draw();

    float dphi;

    for (int i=0; i<nhits; i++) {
      hit = &xyzp->at(i);
//-----------------------------------------------------------------------------
// predict phi at this Z to resolve 2pi ambiguities
//-----------------------------------------------------------------------------
      float pred = phi0+dfdz*z[i];
      float phib = phi1[i];

      dphi = TVector2::Phi_mpi_pi(phib-pred);
      m    = new TMarker(z[i],dphi,2);

      if (hit->_flag.hasAllProperties(StrawHitFlag::outlier)) color = kBlack;
      else                  color = kRed;

      m->SetMarkerSize(0.7);
      m->SetMarkerColor(color);
      m->Draw();
    }

    TF1 *yf2 = new TF1("yf","[0]+x*[1]",-1600., 2800.);
    yf2->SetLineWidth(1);
    yf2->SetParameters(0, 0);
    yf2->Draw("same");
    
    helx->print("from CalHelixFinderAlg::plotZPhi");
  }