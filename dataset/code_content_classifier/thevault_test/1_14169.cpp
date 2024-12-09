std::shared_ptr<Subset<uml::Generalization, uml::Element>> ClassifierImpl::getGeneralization() const
{
	if(m_generalization == nullptr)
	{
		/*Subset*/
		m_generalization.reset(new Subset<uml::Generalization, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_generalization - Subset<uml::Generalization, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		m_generalization->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_generalization - Subset<uml::Generalization, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}

    return m_generalization;
}