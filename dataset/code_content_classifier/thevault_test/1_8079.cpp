bool CalHelixFinderAlg::calculateTrackParameters(const XYZVectorF&   p1       ,
						   const XYZVectorF&   p2       ,
						   const XYZVectorF&   p3       ,
						   XYZVectorF&         Center   ,
						   float&         Radius   ,
						   float&         Phi0     ,
						   float&         DfDz32) {
    //evaluate the area covered by the Triplet
    float dist2ij = (p1 - p2).Mag2();
    float dist2ik = (p1 - p3).Mag2();
    float dist2jk = (p2 - p3).Mag2();
    float area2   = (dist2ij*dist2jk + dist2ik*dist2jk + dist2ij*dist2ik) - 0.5*(dist2ij*dist2ij + dist2jk*dist2jk + dist2ik*dist2ik);
    if(area2 < _minarea2)              return false;


    Center.SetZ(p2.z());

    float x_m, y_m, x_n, y_n;
    // coordinates of the mean point between p1 and p3
    x_m = (p3.x() + p1.x())/2.;
    y_m = (p3.y() + p1.y())/2.;
    // coordinates of the mean point between p2 and p3
    x_n = (p3.x() + p2.x())/2.;
    y_n = (p3.y() + p2.y())/2.;
    //------------------------------------------------------------//

    //calculate now the term of the line ortoghonal to the mid point of
    //the cord which links p1 and p3
    float m = -1.*(p3.x() - p1.x())/(p3.y() - p1.y());
    float c = y_m - x_m*m;
    //the eq. is: y = x*m + c

    //calculate now the term of the line ortoghonal to the mid point of
    //the cord which links p2 and p3
    float k = -1.*(p3.x() - p2.x())/(p3.y() - p2.y());
    float t = y_n - x_n*k;
    //the eq. is: y = x*k + t

    //check we are not in a degenerate case where m is close to k, which rapresents two almost parallel lines
    float limit = 0.8;//FIXME!
    
    if ( (m/k>0) && ( (m/k) - int(m/k) > limit) ) {//invert p3 with p1 and recalculate: x_n, y_n, k, t
      x_n = (p1.x() + p2.x())/2.;
      y_n = (p1.y() + p2.y())/2.;
      k   = -1.*(p1.x() - p2.x())/(p1.y() - p2.y());
      t   = y_n - x_n*k;
     }

    // calculate Center.x and Center.y
    float x0 = (t - c)/(m - k);//(c - t) * (k*m)/(m-k);
    Center.SetX(x0);
    float y0 = m*x0 + c;   //(c - t) * m / (m - k) + t;
    Center.SetY(y0);
//-----------------------------------------------------------------------------
// calculate the radius,phi0, tanLambda assuming that the helix also crosses 
// the point (0,0). Note that the Z-position of the stopping target is not used
//-----------------------------------------------------------------------------
    float dx3  = p3.x() - x0;
    float dy3  = p3.y() - y0;
    float dz32 = p3.z() - p2.z();

    Radius      = std::sqrt(dx3*dx3+dy3*dy3);

    float dx2  = (p2.x() - x0);
    float dy2  = (p2.y() - y0);

    Phi0        = polyAtan2(dy2,dx2);
//-----------------------------------------------------------------------------
// this assumes that the helix is right-handed, *FIXME*
// make sure that we are lookign for a particle which makes close to expected 
// number of turns
//-----------------------------------------------------------------------------
    float dphi32 = polyAtan2(dy3,dx3) - Phi0;
    if (dphi32*_dfdzsign < 0.) dphi32 += 2.*M_PI;

    //    float exp_dphi = _mpDfDz*dz32;

    //check id DfDz is within the range 
    if ( (fabs(DfDz32) < _minDfDz) || (fabs(DfDz32) > _maxDfDz)) DfDz32 = _mpDfDz;

    DfDz32 = dphi32/dz32; 

    float   diff      = fabs(DfDz32 - _mpDfDz);
    float   diff_plus = fabs( (dphi32 + 2.*M_PI)/dz32 -_mpDfDz );
    while ( diff_plus < diff ){
      dphi32  = dphi32 + 2.*M_PI;
      DfDz32      = dphi32/dz32;
      diff      = fabs(DfDz32 - _mpDfDz);
      diff_plus = fabs( (dphi32 + 2.*M_PI)/dz32 -_mpDfDz );
    }
    
    float   diff_minus = fabs( (dphi32 - 2.*M_PI)/dz32 -_mpDfDz );
    while ( diff_minus < diff ){
      dphi32   = dphi32 - 2.*M_PI;
      DfDz32       = dphi32/dz32;
      diff       = fabs(DfDz32 - _mpDfDz);
      diff_minus = fabs( (dphi32 - 2.*M_PI)/dz32 -_mpDfDz );
    }

    //check id DfDz is within the range 
    if ( (fabs(DfDz32) < _minDfDz) || (fabs(DfDz32) > _maxDfDz)) DfDz32 = _mpDfDz;

    if (_debug > 5) {
//-----------------------------------------------------------------------------
// in debug mode also want to print the helix parameters, calculate them
// phi00 - phi angle of (x0,y0) point - center of the helix
//-----------------------------------------------------------------------------
      float d0     = sqrt(x0*x0+y0*y0)-Radius;
      float phi00  = polyAtan2(y0,x0);                    // sign taken into account 
      float tandip = DfDz32*_dfdzsign*Radius;             // signs of DfDz32 and _dfdzsign should be the same
      float dphi   = phi00-Phi0;
      if (dphi < 0) dphi += 2*M_PI;                        // *FIXME* right-handed helix

      float z0     = p2.z()-dphi*dz32/dphi32;

      printf("[CalHelixFinderAlg:calculateTrackParameters] X0: %9.3f Y0: %9.3f phi0: %8.5f p1.z = %9.3f p2.z = %9.3f p3.z = %9.3f dphi32 = %8.5f dfdz = %8.5f\n",
	     Center.x(),Center.y(),Phi0,p1.z(),p2.z(),p3.z(),dphi32,DfDz32);
      printf("[CalHelixFinderAlg:calculateTrackParameters] z0 = %9.3f d0 = %8.4f  phi00 = %8.5f omega = %8.5f tandip = %8.4f\n",z0,d0,phi00,1/Radius,tandip);
    }

    return true;
  }