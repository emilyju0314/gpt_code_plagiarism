int AvikPIDNew::CalculateSlope(vector<double>& Fltlen, vector<double>& Res, double& Slope, double& Err) {

    double dl, dr, fltSum(0), resSum(0), fltMean, resMean, fltVar(0), resVar(0), fltRes(0), fltDev, resDev, rCoeff;

    int n = Fltlen.size();

    if (n > 1) {
      for (int i=0; i<n; i++) {
        fltSum += Fltlen[i];
        resSum += Res[i];
      }

      fltMean = fltSum/n;
      resMean = resSum/n;

      for (int i=0; i<n; i++) {
        dl      = Fltlen[i] - fltMean;
        dr      = Res   [i] - resMean;
        fltVar += dl*dl;
        resVar += dr*dr;
        fltRes += dl*dr;
      }

      fltDev = sqrt(fltVar/n);              // sigxx
      resDev = sqrt(resVar/n);              // sigyy
      rCoeff = fltRes/sqrt(fltVar*resVar);  //

      Slope  = rCoeff*resDev/fltDev;
      Err    = 0.1/sqrt(fltVar);
    }
    else {
//-----------------------------------------------------------------------------
// degenerate case
//-----------------------------------------------------------------------------
      Slope = 1.e6;
      Err   = 1.e6;
    }
    return 0;
  }