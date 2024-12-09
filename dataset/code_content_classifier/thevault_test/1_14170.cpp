std::shared_ptr<Subset<uml::NamedElement, uml::NamedElement>> ClassifierImpl::getInheritedMember() const
{
	if(m_inheritedMember == nullptr)
	{
		/*Subset*/
		m_inheritedMember.reset(new Subset<uml::NamedElement, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_inheritedMember - Subset<uml::NamedElement, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		m_inheritedMember->initSubset(getMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_inheritedMember - Subset<uml::NamedElement, uml::NamedElement >(getMember())" << std::endl;
		#endif
		
	}

    return m_inheritedMember;
}