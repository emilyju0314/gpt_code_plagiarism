std::shared_ptr<Subset<uml::Gate, uml::NamedElement>> InteractionImpl::getFormalGate() const
{
	if(m_formalGate == nullptr)
	{
		/*Subset*/
		m_formalGate.reset(new Subset<uml::Gate, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_formalGate - Subset<uml::Gate, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		m_formalGate->initSubset(getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_formalGate - Subset<uml::Gate, uml::NamedElement >(getOwnedMember())" << std::endl;
		#endif
		
	}

    return m_formalGate;
}