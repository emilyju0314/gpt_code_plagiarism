void TimeAndPhiClusterFinder::calculateMean(TimeCluster& tc, const std::vector<float>& comboHitTime) 
  {        
      if (tc._strawHitIdxs.empty()) {tc._pos = XYZVectorF(0,0,0);tc._t0._t0=0; tc._t0._t0err =0; tc._nsh = 0; return;};
      
      tc._nsh = 0;            
      float tacc(0),tacc2(0),xacc(0),yacc(0),zacc(0),weight(0);
      for (auto ish :tc._strawHitIdxs) 
      {
          const ComboHit& ch = chcol_->at(ish);
          tc._nsh += ch.nStrawHits();

          float htime = comboHitTime[ish];
          float hwt   = ch.nStrawHits();

          weight += hwt;
          tacc   += htime*hwt;
          tacc2  += htime*htime*hwt;
          xacc   += ch.pos().x()*hwt;
          yacc   += ch.pos().y()*hwt;
          zacc   += ch.pos().z()*hwt;
      }
      
      tacc/=weight;
      tacc2/=weight;
      xacc/=weight;
      yacc/=weight;
      zacc/=weight;
          
      tc._t0._t0    = tacc;
      tc._t0._t0err = sqrtf(tacc2-tacc*tacc);
      tc._pos       = XYZVectorF(xacc, yacc, zacc);          
  }