bool 
RegExp::REBase::MatchNext(RegExp::REContext* pcContext, const char* pzString)
{
  if (_pcNext)
  {
    REContext
      cLocalContext(*pcContext);

    if (_pcNext->Match(&cLocalContext, pzString))
    {
      pcContext->_nCharactersMatched += cLocalContext._nCharactersMatched;
      return true;
    }
    else
    {
      pcContext->_nCharactersMatched = 0;
      return false;
    }
  }
  return true;
}