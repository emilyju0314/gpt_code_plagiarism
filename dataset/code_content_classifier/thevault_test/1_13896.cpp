std::shared_ptr<Subset<uml::Package, uml::PackageableElement /*Subset does not reference a union*/>> PackageImpl::getNestedPackage() const
{
	if(m_nestedPackage == nullptr)
	{
		/*Subset*/
		m_nestedPackage.reset(new Subset<uml::Package, uml::PackageableElement /*Subset does not reference a union*/ >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_nestedPackage - Subset<uml::Package, uml::PackageableElement /*Subset does not reference a union*/ >()" << std::endl;
		#endif
		
		/*Subset*/
		m_nestedPackage->initSubset(getPackagedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_nestedPackage - Subset<uml::Package, uml::PackageableElement /*Subset does not reference a union*/ >(getPackagedElement())" << std::endl;
		#endif
		
	}

    return m_nestedPackage;
}