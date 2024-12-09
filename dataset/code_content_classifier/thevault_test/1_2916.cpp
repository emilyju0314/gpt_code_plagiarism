float CalcObjFunc(std::vector<float> *obs, std::vector<float> *sim,
                  OBJECTIVES obj) {

  switch (obj) {
  case OBJECTIVE_NSCE:
    return CalcNSCE(obs, sim);
  case OBJECTIVE_CC:
    return CalcCC(obs, sim);
  case OBJECTIVE_SSE:
    return CalcSSE(obs, sim);
  default:
    return 0;
  }
}