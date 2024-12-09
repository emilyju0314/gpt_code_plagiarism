PeptideNamespace::FragmentIon PeptideNamespace::FragmentIon::makeNLFrag(double lossMass,
																		size_t numNL) const
{
	PeptideNamespace::FragmentIon ret = FragmentIon(*this);
	
	//get new fragment type
	PeptideNamespace::IonType ionType;
	if(getBY() == 'b')
		ionType = PeptideNamespace::IonType::B_NL;
	else if(getBY() == 'y')
		ionType = PeptideNamespace::IonType::Y_NL;
	else if(getBY() == 'M' || getBY() == 'm')
		ionType = PeptideNamespace::IonType::M_NL;
	else throw std::runtime_error("Unknown ion type!");
	ret.setIonType(ionType);
	
	//add mass and nlMass
	ret.mass = mass - (lossMass / charge);
	ret._nlMass = -1 * lossMass;
	ret._numNl = numNL;

	return ret;
}