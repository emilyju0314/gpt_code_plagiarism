inline int CalcMandelbrotDS(const dfloat xPos, const dfloat yPos, 
							const dfloat xJParam, const dfloat yJParam, const int crunch, const bool isJulia)
{
    dfloat x, y, xx, yy, sum;
    int i = crunch;

	dfloat xC, yC ;
	if(isJulia) {
		dseq(xC, xJParam) ;     // xC0 = xJParam ;
		dseq(yC, yJParam) ;     // yC0 = yJParam ;
		dseq(y, yPos);      // y = yPos;
		dseq(x, xPos);      // x = xPos;
		dsmul(yy, y, y);    // yy = y * y;
		dsmul(xx, x, x);	// xx = x * x;
		dsadd(sum, xx, yy); // sum = xx + yy;
	}
	else {
		dseq(xC, xPos) ;     // xC = xPos ;
		dseq(yC, yPos) ;     // yC = yPos ;
		dsdeq(y, 0.0) ;	// y = 0 ;
		dsdeq(x, 0.0) ;	// x = 0 ;
		dsdeq(yy, 0.0) ;   // yy = 0 ;
		dsdeq(xx, 0.0) ;   // xx = 0 ;
		dsdeq(sum, 0.0) ;   // sum = 0 ;
	}
    while (--i && (sum[0] < 4.0f)) {
        dsmul(y, x, y);     // y = x * y * 2.0f + yC ;
        dsadd(y, y, y);
        dsadd(y, y, yC);

        dssub(x, xx, yy);   //  x = xx - yy + xC ;
        dsadd(x, x, xC);

        dsmul(yy, y, y);    // yy = y * y;
        dsmul(xx, x, x);    // xx = x * x;
        dsadd(sum, xx, yy); // sum = xx + yy;
    }
    return i;
}