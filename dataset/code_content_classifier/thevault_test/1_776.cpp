static void interp_hist_entry( double*** hist, double rbin, double cbin,
                               double obin, double mag, int d, int n )
{
  double d_r, d_c, d_o, v_r, v_c, v_o;
  double** row, * h;
  int r0, c0, o0, rb, cb, ob, r, c, o;

  r0 = cvFloor( rbin );
  c0 = cvFloor( cbin );
  o0 = cvFloor( obin );
  d_r = rbin - r0;
  d_c = cbin - c0;
  d_o = obin - o0;

  /*
    The entry is distributed into up to 8 bins.  Each entry into a bin
    is multiplied by a weight of 1 - d for each dimension, where d is the
    distance from the center value of the bin measured in bin units.
  */
  for( r = 0; r <= 1; r++ )
    {
      rb = r0 + r;
      if( rb >= 0  &&  rb < d )
        {
          v_r = mag * ( ( r == 0 )? 1.0 - d_r : d_r );
          row = hist[rb];
          for( c = 0; c <= 1; c++ )
            {
              cb = c0 + c;
              if( cb >= 0  &&  cb < d )
                {
                  v_c = v_r * ( ( c == 0 )? 1.0 - d_c : d_c );
                  h = row[cb];
                  for( o = 0; o <= 1; o++ )
                    {
                      ob = ( o0 + o ) % n;
                      v_o = v_c * ( ( o == 0 )? 1.0 - d_o : d_o );
                      h[ob] += v_o;
                    }
                }
            }
        }
    }
}