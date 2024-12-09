std::shared_ptr<Subset<ecore::EReference, ecore::EStructuralFeature>> EClassImpl::getEReferences() const
{
	if(m_eReferences == nullptr)
	{
		/*Subset*/
		m_eReferences.reset(new Subset<ecore::EReference, ecore::EStructuralFeature >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_eReferences - Subset<ecore::EReference, ecore::EStructuralFeature >()" << std::endl;
		#endif
		
		/*Subset*/
		m_eReferences->initSubset(getEStructuralFeatures());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_eReferences - Subset<ecore::EReference, ecore::EStructuralFeature >(getEStructuralFeatures())" << std::endl;
		#endif
		
	}

    return m_eReferences;
}