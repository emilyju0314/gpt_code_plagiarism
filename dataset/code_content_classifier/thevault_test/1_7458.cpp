bool PKFmanip::readHeader(istream &in) {

  char tmp[1024];
  in.getline(tmp,sizeof tmp);

  // Header begin
  if(strncmp(tmp,"PKF 0.2",7)) {
    cerr << "ERROR : readkPKF() : Not in PKF 0.2 format!\n";
    return false;
  }
  in.getline(tmp,sizeof tmp);
  if(strncmp(tmp,"BIARC_KNOT",10)) {
    cerr << "Expected BIARC_KNOT. Only Biarc Format is supported.\n";
    return false;
  }
  _NameString    = setString(tmp+11);
  _EticString    = readString(in,"ETICL","ETIC");
  _CiteString    = readString(in,"CITEL","CITE");
  _HistoryString = readString(in,"HISTL","HIST");
  //Header End

  return true;
}