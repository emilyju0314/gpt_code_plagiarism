std::shared_ptr<Subset<uml::NamedElement, uml::Element>> InformationFlowImpl::getInformationSource() const
{
	if(m_informationSource == nullptr)
	{
		/*Subset*/
		m_informationSource.reset(new Subset<uml::NamedElement, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_informationSource - Subset<uml::NamedElement, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		m_informationSource->initSubset(getSource());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_informationSource - Subset<uml::NamedElement, uml::Element >(getSource())" << std::endl;
		#endif
		
	}
//assert(m_informationSource);
    return m_informationSource;
}