float  CalHelixFinderAlg::calculateRadialDist (const XYZVectorF& HitPos   ,
						  const XYZVectorF& HelCenter,
						  float        Radius   ) {
    float dx = HitPos.x()-HelCenter.x();
    float dy = HitPos.y()-HelCenter.y();
    float dr = sqrt(dx*dx+dy*dy)-Radius;

    return dr;
  }