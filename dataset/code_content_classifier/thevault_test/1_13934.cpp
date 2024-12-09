std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element>> DependencyImpl::getSupplier() const
{
	if(m_supplier == nullptr)
	{
		/*SubsetUnion*/
		m_supplier.reset(new SubsetUnion<uml::NamedElement, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_supplier - SubsetUnion<uml::NamedElement, uml::Element >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		m_supplier->initSubsetUnion(getTarget());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_supplier - SubsetUnion<uml::NamedElement, uml::Element >(getTarget())" << std::endl;
		#endif
		
	}
//assert(m_supplier);
    return m_supplier;
}