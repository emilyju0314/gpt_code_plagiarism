void DynamicsSimulator_UT::getLinkData(int ichara, LinkDataType t, vectorn& out)
{
	VRMLloader const& l=*_characters[ichara]->skeleton;


	OpenHRP::DynamicsSimulator& s=*this;
	OpenHRP::World_UT::CharacterInfo& cinfo=getWorld()->characters[0];

	DynamicsSimulator_UT_getLinkData(l, cinfo, t, out);

}