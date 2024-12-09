std::shared_ptr<Subset<uml::InterfaceRealization, uml::Element>> BehavioredClassifierImpl::getInterfaceRealization() const
{
	if(m_interfaceRealization == nullptr)
	{
		/*Subset*/
		m_interfaceRealization.reset(new Subset<uml::InterfaceRealization, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_interfaceRealization - Subset<uml::InterfaceRealization, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		m_interfaceRealization->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_interfaceRealization - Subset<uml::InterfaceRealization, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}

    return m_interfaceRealization;
}