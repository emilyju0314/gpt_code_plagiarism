string
Person::getTitle(string sLang)
{
/*
	if (string("") == sLang)
		sLang = _pContexte->getUser()->donneLang();
*/

	if (string("") == _sFullName)
		buildFullName();

	return _sFullName;
}