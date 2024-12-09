std::shared_ptr<Subset<uml::EnumerationLiteral, uml::NamedElement>> EnumerationImpl::getOwnedLiteral() const
{
	if(m_ownedLiteral == nullptr)
	{
		/*Subset*/
		m_ownedLiteral.reset(new Subset<uml::EnumerationLiteral, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_ownedLiteral - Subset<uml::EnumerationLiteral, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		m_ownedLiteral->initSubset(getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_ownedLiteral - Subset<uml::EnumerationLiteral, uml::NamedElement >(getOwnedMember())" << std::endl;
		#endif
		
	}

    return m_ownedLiteral;
}