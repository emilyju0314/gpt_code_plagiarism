NSPhraseMot::NSPhraseMot(NSPatPathoData* pPatPathoElement, NSContexte* pCtx)
            :NSRoot(pCtx)
{
	metAZero();

  _sLexique    = pPatPathoElement->getLexique();
	_sComplement = pPatPathoElement->getComplement();
	_sCertitude  = pPatPathoElement->getCertitude();
  _sPluriel    = pPatPathoElement->getPluriel();
  _sUnite      = pPatPathoElement->getUnit();

  _sTexteLibre = pPatPathoElement->getTexteLibre();

  _pComplement = (NSPhraseur*) 0;
}