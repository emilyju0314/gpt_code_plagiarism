parameters::parameters(const Rcpp::List& p) {
  
  // take parameter values from an R list
  eta = rcpp_to_double(p["eta"]);
  rho = rcpp_to_double(p["rho"]);
  a0 = rcpp_to_double(p["a0"]);
  s2 = rcpp_to_double(p["s2"]);
  rA = rcpp_to_double(p["rA"]);
  rT = rcpp_to_double(p["rT"]);
  rD = rcpp_to_double(p["rD"]);
  rU = rcpp_to_double(p["rU"]);
  rP = rcpp_to_double(p["rP"]);
  dE = rcpp_to_double(p["dE"]);
  tl = rcpp_to_double(p["tl"]);
  cD = rcpp_to_double(p["cD"]);
  cT = rcpp_to_double(p["cT"]);
  cU = rcpp_to_double(p["cU"]);
  g_inf =	rcpp_to_double(p["g_inf"]);
  d1 = rcpp_to_double(p["d1"]);
  dd = rcpp_to_double(p["dd"]);
  ID0	= rcpp_to_double(p["ID0"]);
  kd = rcpp_to_double(p["kd"]);
  ud = rcpp_to_double(p["ud"]);
  ad0 = rcpp_to_double(p["ad0"]);
  fd0 = rcpp_to_double(p["fd0"]);
  gd = rcpp_to_double(p["gd"]);
  aA = rcpp_to_double(p["aA"]);
  aU = rcpp_to_double(p["aU"]);
  b0 = rcpp_to_double(p["b0"]);
  b1 = rcpp_to_double(p["b1"]);
  db = rcpp_to_double(p["db"]);
  IB0 = rcpp_to_double(p["IB0"]);
  kb = rcpp_to_double(p["kb"]);
  ub = rcpp_to_double(p["ub"]);
  phi0 = rcpp_to_double(p["phi0"]);
  phi1 = rcpp_to_double(p["phi1"]);
  dc = rcpp_to_double(p["dc"]);
  IC0	= rcpp_to_double(p["IC0"]);
  kc = rcpp_to_double(p["kc"]);
  uc = rcpp_to_double(p["uc"]);
  PM = rcpp_to_double(p["PM"]);
  dm = rcpp_to_double(p["dm"]);
  tau	= rcpp_to_double(p["tau"]);
  mu = rcpp_to_double(p["mu"]);
  f = rcpp_to_double(p["f"]);
  Q0 = rcpp_to_double(p["Q0"]);
}