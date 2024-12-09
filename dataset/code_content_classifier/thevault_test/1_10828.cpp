static double NormEvidenceOf(double NormAdj) {
  NormAdj /= classify_norm_adj_midpoint;

  if (classify_norm_adj_curl == 3) {
    NormAdj = NormAdj * NormAdj * NormAdj;
  } else if (classify_norm_adj_curl == 2) {
    NormAdj = NormAdj * NormAdj;
  } else {
    NormAdj = pow(NormAdj, classify_norm_adj_curl);
  }
  return (1.0 / (1.0 + NormAdj));
}