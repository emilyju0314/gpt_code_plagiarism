std::shared_ptr<Subset<uml::Transition, uml::NamedElement>> RegionImpl::getTransition() const
{
	if(m_transition == nullptr)
	{
		/*Subset*/
		m_transition.reset(new Subset<uml::Transition, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_transition - Subset<uml::Transition, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		m_transition->initSubset(getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_transition - Subset<uml::Transition, uml::NamedElement >(getOwnedMember())" << std::endl;
		#endif
		
	}

    return m_transition;
}