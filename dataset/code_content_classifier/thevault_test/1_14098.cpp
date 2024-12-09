std::shared_ptr<Subset<uml::Lifeline, uml::NamedElement>> InteractionImpl::getLifeline() const
{
	if(m_lifeline == nullptr)
	{
		/*Subset*/
		m_lifeline.reset(new Subset<uml::Lifeline, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_lifeline - Subset<uml::Lifeline, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		m_lifeline->initSubset(getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_lifeline - Subset<uml::Lifeline, uml::NamedElement >(getOwnedMember())" << std::endl;
		#endif
		
	}

    return m_lifeline;
}