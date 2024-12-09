DBIResult
NSFlechies::open(bool bOpenShared)
{
	//
	// Appelle la fonction open() de la classe de base pour ouvrir
	// l'index primaire
	//
	lastError = NSFiche::open(sFileName.c_str(), NSF_GUIDES, bOpenShared);

	return (lastError);
}