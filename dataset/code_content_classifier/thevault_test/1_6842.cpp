void EWPolicy::detectBr(int dt_inv, int db_inv) {
  ewB = new EWdetectorB;
  ewB->init(ew_adj);
  ewB->setLink(qsrc, qdst);
  ewB->setDt(dt_inv);
  ewB->setDb(db_inv);
}