void PeptideNamespace::AminoAcid::addStaticMod(double modMass)
{
	_staticMod = true;
	_addMod(modMass);
}