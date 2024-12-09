void PeptideNamespace::AminoAcid::setDynamicMod(char mod, double modMass){
	_mod = mod;
	_dynamicMod = true;
	_addMod(modMass);
}