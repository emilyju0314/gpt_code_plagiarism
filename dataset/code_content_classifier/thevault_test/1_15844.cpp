void
NSDico::donneCodeSens(string& sCode)
{
    string sCodeCat = CodeCategorie(sCode);
  size_t iSize    = strlen(sCode.c_str());

  if ((string("£") == sCodeCat) && (iSize > BASE_FORMAT_SENS_LEN))
  {
  	if (string("£SG") != string(sCode, 0, 3))
    {
        sCode = string(sCode, 0, BASE_FORMAT_SENS_LEN);
      return;
    }
  }

	if ((string("$") != sCodeCat) && (iSize >= BASE_LEXI_LEN))
  {
    sCode = string(sCode, 0, BASE_SENS_LEN);
    return;
  }
}