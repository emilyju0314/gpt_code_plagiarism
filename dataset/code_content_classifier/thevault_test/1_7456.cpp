void PKFmanip::clear() {
  delete _NameString;    _NameString = NULL;
  delete _EticString;    _EticString = NULL;
  delete _CiteString;    _CiteString = NULL;
  delete _HistoryString; _HistoryString = NULL;
}