std::shared_ptr<SubsetUnion<uml::PackageableElement, uml::NamedElement>> PackageImpl::getPackagedElement() const
{
	if(m_packagedElement == nullptr)
	{
		/*SubsetUnion*/
		m_packagedElement.reset(new SubsetUnion<uml::PackageableElement, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_packagedElement - SubsetUnion<uml::PackageableElement, uml::NamedElement >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		m_packagedElement->initSubsetUnion(getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_packagedElement - SubsetUnion<uml::PackageableElement, uml::NamedElement >(getOwnedMember())" << std::endl;
		#endif
		
	}

    return m_packagedElement;
}