std::shared_ptr<Subset<uml::Substitution, uml::Element>> ClassifierImpl::getSubstitution() const
{
	if(m_substitution == nullptr)
	{
		/*Subset*/
		m_substitution.reset(new Subset<uml::Substitution, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_substitution - Subset<uml::Substitution, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		m_substitution->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_substitution - Subset<uml::Substitution, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}

    return m_substitution;
}