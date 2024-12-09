std::shared_ptr<Subset<uml::Type, uml::PackageableElement /*Subset does not reference a union*/>> PackageImpl::getOwnedType() const
{
	if(m_ownedType == nullptr)
	{
		/*Subset*/
		m_ownedType.reset(new Subset<uml::Type, uml::PackageableElement /*Subset does not reference a union*/ >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_ownedType - Subset<uml::Type, uml::PackageableElement /*Subset does not reference a union*/ >()" << std::endl;
		#endif
		
		/*Subset*/
		m_ownedType->initSubset(getPackagedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_ownedType - Subset<uml::Type, uml::PackageableElement /*Subset does not reference a union*/ >(getPackagedElement())" << std::endl;
		#endif
		
	}

    return m_ownedType;
}