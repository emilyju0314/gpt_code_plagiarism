void				compGradImg( double *I, double *G, int *O, int h, int w, int nCh, int oBin ) {
  // compute unit vectors evenly distributed at oBin orientations
  double *ux = (double*) mxMalloc(oBin*sizeof(double));
  double *uy = (double*) mxMalloc(oBin*sizeof(double));
  for( int o=0; o<oBin; o++ ) ux[o]=cos(double(o)/double(oBin)*PI);
  for( int o=0; o<oBin; o++ ) uy[o]=sin(double(o)/double(oBin)*PI);
  
  // compute gradients for each channel, pick strongest gradient
  int y, x, c; double *I1, v, dx, dy, dx1, dy1, v1;
  #define COMPGRAD(x0, x1, rx, y0, y1, ry) { v=-1; for(c=0; c<nCh; c++) { \
          I1 = I + c*h*w + x*h + y; \
          dy1 = (*(I1+y1)-*(I1-y0))*ry; \
                  dx1 = (*(I1+x1*h)-*(I1-x0*h))*rx; \
                  v1=dx1*dx1+dy1*dy1; if(v1>v) { v=v1; dx=dx1; dy=dy1; }} \
          *(G+x*h+y)=sqrt(v); *(O+x*h+y)=compOrient(dx, dy, ux, uy, oBin); }
  
  // centered differences on interior points
  for( x=1; x<w-1; x++ ) for( y=1; y<h-1; y++ ) COMPGRAD(1, 1, 1, 1, 1, 1);
  
  // uncentered differences along each edge
  x=0;   for( y=1; y<h-1; y++ ) COMPGRAD(0, 1, 2, 1, 1, 1);
  y=0;   for( x=1; x<w-1; x++ ) COMPGRAD(1, 1, 1, 0, 1, 2);
  x=w-1; for( y=1; y<h-1; y++ ) COMPGRAD(1, 0, 2, 1, 1, 1);
  y=h-1; for( x=1; x<w-1; x++ ) COMPGRAD(1, 1, 1, 1, 0, 2);
  
  // finally uncentered differences at corners
  x=0;   y=0;   COMPGRAD(0, 1, 2, 0, 1, 2);
  x=w-1; y=0;   COMPGRAD(1, 0, 2, 0, 1, 2);
  x=0;   y=h-1; COMPGRAD(0, 1, 2, 1, 0, 2);
  x=w-1; y=h-1; COMPGRAD(1, 0, 2, 1, 0, 2);
  
  mxFree(ux); mxFree(uy);
}