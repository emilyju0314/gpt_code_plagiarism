int					compOrient( double dx, double dy, double *ux, double *uy, int oBin ) {
  if(oBin<=1) return 0; int o0=0, o1=oBin-1;
  double s0=fabs(ux[o0]*dx+uy[o0]*dy);
  double s1=fabs(ux[o1]*dx+uy[o1]*dy);
  while( 1 ) {
    if(o0==o1-1) { return ((s0>s1) ? o0 : o1); }
    if( s0<s1 ) {
      o0+=(o1-o0+1)>>1; s0=fabs(ux[o0]*dx+uy[o0]*dy);
    } else {
      o1-=(o1-o0+1)>>1; s1=fabs(ux[o1]*dx+uy[o1]*dy);
    }
  }
}