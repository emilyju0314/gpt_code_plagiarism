std::shared_ptr<Subset<uml::PackageMerge, uml::Element>> PackageImpl::getPackageMerge() const
{
	if(m_packageMerge == nullptr)
	{
		/*Subset*/
		m_packageMerge.reset(new Subset<uml::PackageMerge, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_packageMerge - Subset<uml::PackageMerge, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		m_packageMerge->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_packageMerge - Subset<uml::PackageMerge, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}

    return m_packageMerge;
}