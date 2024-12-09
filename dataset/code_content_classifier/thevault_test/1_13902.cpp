std::shared_ptr<Subset<uml::ProfileApplication, uml::Element>> PackageImpl::getProfileApplication() const
{
	if(m_profileApplication == nullptr)
	{
		/*Subset*/
		m_profileApplication.reset(new Subset<uml::ProfileApplication, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_profileApplication - Subset<uml::ProfileApplication, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		m_profileApplication->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_profileApplication - Subset<uml::ProfileApplication, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}

    return m_profileApplication;
}