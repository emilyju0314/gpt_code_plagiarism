gsl_complex TMatrix_Anderson(double omega,
			void *params){
  // Get parameters from params. Example
  //vector<double> VecParam=*(vector<double> *)(params);

  CConductance Gaux=*(CConductance *)params;


  gsl_complex caux;
  //GSL_SET_COMPLEX(&caux,0.0,3.0);

  // Delta1*G11(omega)

  double Delta1=Gaux.CondParams[1]; // Check this.

  // Debugging
//   cout << "Delta 1 = " << Delta1 
//        << " rho(w=" << omega << ") = " << Gaux.SpecVec[0].RhoInterpol(omega) 
//        << endl;

  //cout << "pi*Delta1*rho(0) = " <<  M_PI*Delta1*Gaux.SpecVec[0].RhoInterpol(0.0) << endl;
  caux=Gaux.SpecVec[0].GreensFunction(omega);
  caux=gsl_complex_mul_real (caux,Delta1);

  return(caux);

}