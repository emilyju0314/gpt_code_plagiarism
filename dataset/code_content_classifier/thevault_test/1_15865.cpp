string
Person::getTranslatedBirthDate(string sLang)
{
  if (string("") == _sBirthDate)
		return string("");

  string sFormat = _pContexte->getSuperviseur()->getText("0localInformation", "dateFormat", sLang, _pContexte);

  return getFormatedDate(_sBirthDate, sLang, sFormat);
}