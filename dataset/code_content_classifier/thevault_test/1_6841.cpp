void EWPolicy::detectPr(int dt_inv, int db_inv) {
  ewP = new EWdetectorP;
  ewP->setLink(qsrc, qdst);
  ewP->setDt(dt_inv);
  ewP->setDb(db_inv);
}