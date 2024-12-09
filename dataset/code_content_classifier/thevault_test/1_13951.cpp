std::shared_ptr<Subset<uml::ParameterSet, uml::NamedElement>> BehavioralFeatureImpl::getOwnedParameterSet() const
{
	if(m_ownedParameterSet == nullptr)
	{
		/*Subset*/
		m_ownedParameterSet.reset(new Subset<uml::ParameterSet, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_ownedParameterSet - Subset<uml::ParameterSet, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		m_ownedParameterSet->initSubset(getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_ownedParameterSet - Subset<uml::ParameterSet, uml::NamedElement >(getOwnedMember())" << std::endl;
		#endif
		
	}

    return m_ownedParameterSet;
}