void
NSEpiFlechiesDB::ConvertitMajuscule(char* chaine)
{
  for (size_t i = 0; i < strlen(chaine); i++)
  {
    switch (chaine[i])
    {
      case 'È' ://200
      case 'É' :
      case 'Ê' :
      case 'Ë' :
			case 'é' :
      case 'ë' :
      case 'è' :
      case 'ê' : chaine[i] =  'E';
                 break;
      case 'À' :
      case 'Á' :
      case 'Â' :
      case 'Ã' :
      case 'Ä' :
      case 'Å' : //197
      case 'Æ' :
      case 'à' : //226
      case 'â' :
      case 'ã' :
      case 'ä' :
      case 'å' :
      case 'æ' :
      case 'á' : chaine[i] =  'A';
                 break;
      case 'Ì' :
      case 'Í' :
      case 'Î' :
      case 'Ï' :
      case 'í' :
      case 'î' :
      case 'ï' : chaine[i] =  'I';
                 break;
      case 'Ü' ://220
      case 'Û' :
      case 'Ú' :
      case 'Ù' : //216
      case 'ú' :
      case 'û' :
      case 'ü' :
      case 'ù' : chaine[i] =  'U';
                 break;
      case 'Õ' : //213
      case 'Ö' :
      case 'Ô' :
      case 'Ó' :
      case 'Ò' :
      case 'ò' : //242
      case 'ó' :
      case 'ô' :
      case 'õ' :
      case 'ö' : chaine[i] = 'O';
                 break;
      case 'ñ' :
      case 'Ñ' : chaine[i] = 'N'; //209
                 break;
      case 'Ý' :
      case 'ÿ' : chaine[i] = 'Y'; //209
                 break;
      case 'Ç' :
      case 'ç' : chaine[i] = 'C'; //209
                 break;
      case 'Ð' : chaine[i] = 'D'; //209
                 break;
#ifdef __linux__
      default  : chaine[i] = toupper(chaine[i]);
#endif
    }
  }
#ifndef __linux__
  chaine = strupr(chaine);
#endif
}