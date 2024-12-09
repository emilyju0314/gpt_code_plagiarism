double Tissue::SodiumPotassiumPump(double intraNa_mM, double extraNa_mM, double extraK_mM, double potential_V)
{
  //Formulation of Luo1994Dynamic used in Yi2002Mathematical
  double maxPumpRate_umol_Per_min = 7.15e-8;
  double potassiumMichaelis_mM = 1.0;
  double sodiumMichaelis_mM = 15.0;

  double KTerm = extraK_mM / (extraK_mM + potassiumMichaelis_mM);
  double NaTerm = 1.0 / (1.0 + pow((sodiumMichaelis_mM / intraNa_mM), 1.5));
  double sigma = (1.0 / 7.0) * (exp(extraNa_mM / 69.73) - 1);
  double beta = potential_V * 96485.0 / (8.314 * 310.0);
  double f = 1.0 / (1.0 + 0.1245 * exp(-0.1 * beta) + 0.0365 * sigma * exp(-beta));

  double pumpFlux_umol_Per_min = maxPumpRate_umol_Per_min * f * NaTerm * KTerm;

  return pumpFlux_umol_Per_min;
}