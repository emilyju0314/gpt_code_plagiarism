void
NSPhraseMot::metAZero()
{
  _sPreposition = string("");
  _sTexteLibre  = string("");
  _avecArticle  = articleSans;
  _posForcee    = posStandard;
  _numForme     = numSimple;

  _sLexique     = string("");
  _sComplement  = string("");
  _sCertitude   = string("");
  _sPluriel     = string("");

  _sFormat      = string("");
  _sMethode     = string("");
  _sUnite       = string("");

  _iPriorite    = 50;  // standard priority
}