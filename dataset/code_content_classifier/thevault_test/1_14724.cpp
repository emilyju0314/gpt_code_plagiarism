std::shared_ptr<SubsetUnion<uml::Property, uml::RedefinableElement>> PropertyImpl::getRedefinedProperty() const
{
	if(m_redefinedProperty == nullptr)
	{
		/*SubsetUnion*/
		m_redefinedProperty.reset(new SubsetUnion<uml::Property, uml::RedefinableElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_redefinedProperty - SubsetUnion<uml::Property, uml::RedefinableElement >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		m_redefinedProperty->initSubsetUnion(getRedefinedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_redefinedProperty - SubsetUnion<uml::Property, uml::RedefinableElement >(getRedefinedElement())" << std::endl;
		#endif
		
	}

    return m_redefinedProperty;
}