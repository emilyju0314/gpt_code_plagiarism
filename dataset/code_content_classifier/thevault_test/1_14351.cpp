std::shared_ptr<Subset<ecore::EEnumLiteral, ecore::EObject>> EEnumImpl::getELiterals() const
{
	if(m_eLiterals == nullptr)
	{
		/*Subset*/
		m_eLiterals.reset(new Subset<ecore::EEnumLiteral, ecore::EObject >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_eLiterals - Subset<ecore::EEnumLiteral, ecore::EObject >()" << std::endl;
		#endif
		
		/*Subset*/
		m_eLiterals->initSubset(getEContens());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_eLiterals - Subset<ecore::EEnumLiteral, ecore::EObject >(getEContens())" << std::endl;
		#endif
		
	}

    return m_eLiterals;
}