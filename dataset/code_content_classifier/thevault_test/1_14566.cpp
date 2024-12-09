std::shared_ptr<Subset<uml::QualifierValue, uml::Element>> LinkEndDataImpl::getQualifier() const
{
	if(m_qualifier == nullptr)
	{
		/*Subset*/
		m_qualifier.reset(new Subset<uml::QualifierValue, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_qualifier - Subset<uml::QualifierValue, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		m_qualifier->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_qualifier - Subset<uml::QualifierValue, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}

    return m_qualifier;
}