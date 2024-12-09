inline void rotmat(const double& a, const double& b , double& c, double& s)
    {
      using std::abs;
      using std::sqrt;
      if ( b == 0.0 )
      {
        c = 1.0;
        s = 0.0;
      }
      else if ( abs(b) > abs(a) )
      {
        double temp = a / b;
        s = 1.0 / sqrt( 1.0 + temp*temp );
        c = temp * s;
      }
      else
      {
        double temp = b / a;
        c = 1.0 / sqrt( 1.0 + temp*temp );
        s = temp * c;
      }
    }