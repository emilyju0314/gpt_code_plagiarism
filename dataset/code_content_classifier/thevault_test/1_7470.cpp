BOOL AnnealAll(CurveBundle<TVec> &rKnot,CAnnealInfo &info,float &dCurEnergy) {

  CurveBundle<TVec> rCopy(rKnot);
  vector<Biarc<TVec> >::iterator b;
  TVec tnow,pnow;
  int n;
  float d;

shuffle_again:
  for (int i=0;i<rKnot.curves();++i) {
    n=0;
    // Displace points
    for (b=rKnot[i].begin();b!=rKnot[i].end();b++) {
      pnow = b->getPoint();
      d=info.m_dStepSize*(StepArray[n].Get(1));
      // cout << "d = " << d << endl;
      TVec vTan = TVec(r(-d,d)*r(0,1), r(-d,d)*r(0,1), r(-d,d)*r(0,1));
      pnow += vTan;
      b->setPoint(pnow);
      ++n;
    }
    n=0;
    // Displace tangents
#if 1
    for (b=rKnot[i].begin();b!=rKnot[i].end();++b) {
      tnow = b->getTangent();
      d=info.m_dStepSize*(StepArray[n].Get(0));
      // cout << "d = " << d << endl;
      TVec vTan = TVec(r(-d,d)*r(0,1), r(-d,d)*r(0,1), r(-d,d)*r(0,1));
      tnow += vTan;
      tnow.normalize();
      b->setTangent(tnow);
      ++n;
    }
  }
#else
  }
  rKnot.computeTangents();
#endif // Tangents

  for (int i=0;i<rKnot.curves();++i) {
    for (int n=0;n<rKnot[i].nodes();++n) {
      if (!(rKnot[i][n].isProper())) {
        rKnot = rCopy;
cout << "AGAIN\n";
        goto shuffle_again;
      }
    }
  }