void TimeAndPhiClusterFinder::findPhiPeaks(TimeCandidate& tc, TimeClusterCollection& tccol) 
  {
       const static unsigned len = unsigned(2*M_PI/pbin_)+1;
       std::vector<unsigned> phiHist(len,0);

       for (auto ish : tc.strawIdx_) 
       {
            const ComboHit& ch = chcol_->at(ish);
            float phi          = ch.pos().phi()+M_PI;
            unsigned ibin      = unsigned(phi/pbin_);
            phiHist[ibin]     += ch.nStrawHits();
       }
       
       std::vector<unsigned> istart,iend;
       associateScan(phiHist,istart,iend);

       for (unsigned ic=0;ic<istart.size();++ic)
       {
           TimeCluster tclu;
           tclu._t0 = TrkT0(tc.t0_,tbin_/0.5);
           tclu._caloCluster = tc.caloCluster_;
           tclu._strawHitIdxs.reserve(16);
           
           for (const auto sIdx :tc.strawIdx_ )
           {
               const ComboHit& ch = chcol_->at(sIdx);
               float phi          = ch.pos().phi()+M_PI;
               unsigned ibin      = unsigned(phi/pbin_);
               if (ibin < istart[ic]) ibin +=len;        
                                     
               if (ibin >= istart[ic] && ibin<iend[ic])
               {
                   tclu._nsh +=ch.nStrawHits(); 
                   tclu._strawHitIdxs.emplace_back(sIdx);
               }
           } 
           if (tclu._nsh > minNSHits_) tccol.push_back(tclu);
       }        
   }