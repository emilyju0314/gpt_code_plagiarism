TrkExtTrajPoint TrkExt::calculateNextPosition (TrkExtTrajPoint r00, double ds, double mass2, int charge) { 
    HepVector r0(6), re(6);
    r0 = r00.vector();
    HepVector dr1_ds = _runge_kutta_newpar_f(r0, getBField(r0), charge);   HepVector r1 = r0+0.5*ds*dr1_ds;
    HepVector dr2_ds = _runge_kutta_newpar_f(r1, getBField(r1), charge);   HepVector r2 = r0+0.5*ds*dr2_ds;
    HepVector dr3_ds = _runge_kutta_newpar_f(r2, getBField(r2), charge);   HepVector r3 = r0+ds*dr3_ds;
    HepVector dr4_ds = _runge_kutta_newpar_f(r3, getBField(r3), charge);

    re = r0 + (dr1_ds/6. + dr2_ds/3. + dr3_ds/3. + dr4_ds/6.)*ds;

    Hep3Vector x(re[0], re[1], re[2]);
    int volid = _mydet.volumeId(x);

    double p = r00.momentum().mag();
    double v = p/safeSqrt(p*p+mass2)*VELOCITY_OF_LIGHT; 
    double ft = ds / v * 1.e6; 

    return TrkExtTrajPoint(r00.trajPointId()+1, re, volid, r00.flightLength()+ds, r00.flightTime()+ft);
  }