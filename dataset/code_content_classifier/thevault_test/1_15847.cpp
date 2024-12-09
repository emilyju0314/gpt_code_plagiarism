void
NSFilGuide::InverseChaine(string* pLocalisation, string* pInverse)
{
	if (NULL == pInverse)
        return;
    *pInverse = string("");

	if ((NULL == pLocalisation) || (string("") == *pLocalisation))
        return;

    size_t posit = pLocalisation->find(string(1, cheminSeparationMARK));
  if (posit == string::npos)
	{
        *pInverse = *pLocalisation;
    return;
	}

    size_t debut = 0;
    int    i = 1;

	while (posit != string::npos)
	{
		if (i == 1 )
            *pInverse = string(1, cheminSeparationMARK) + string(*pLocalisation, debut, posit - debut) + *pInverse;
		else
			*pInverse = string(*pLocalisation, debut, posit - debut) + *pInverse;

        debut = posit;
        posit = pLocalisation->find(string(1, cheminSeparationMARK), debut+1);
        i++;
	}
    *pInverse = string(*pLocalisation, debut+1, strlen(pLocalisation->c_str())-debut-1) + *pInverse;
}