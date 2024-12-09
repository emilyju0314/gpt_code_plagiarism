std::shared_ptr<Subset<uml::ComponentRealization, uml::Element>> ComponentImpl::getRealization() const
{
	if(m_realization == nullptr)
	{
		/*Subset*/
		m_realization.reset(new Subset<uml::ComponentRealization, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_realization - Subset<uml::ComponentRealization, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		m_realization->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_realization - Subset<uml::ComponentRealization, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}

    return m_realization;
}