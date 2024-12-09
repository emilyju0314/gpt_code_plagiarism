std::shared_ptr<Subset<ecore::EAttribute, ecore::EStructuralFeature>> EClassImpl::getEAttributes() const
{
	if(m_eAttributes == nullptr)
	{
		/*Subset*/
		m_eAttributes.reset(new Subset<ecore::EAttribute, ecore::EStructuralFeature >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_eAttributes - Subset<ecore::EAttribute, ecore::EStructuralFeature >()" << std::endl;
		#endif
		
		/*Subset*/
		m_eAttributes->initSubset(getEStructuralFeatures());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_eAttributes - Subset<ecore::EAttribute, ecore::EStructuralFeature >(getEStructuralFeatures())" << std::endl;
		#endif
		
	}

    return m_eAttributes;
}