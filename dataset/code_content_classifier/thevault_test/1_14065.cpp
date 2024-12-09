std::shared_ptr<Subset<ecore::EAnnotation, ecore::EObject>> EModelElementImpl::getEAnnotations() const
{
	if(m_eAnnotations == nullptr)
	{
		/*Subset*/
		m_eAnnotations.reset(new Subset<ecore::EAnnotation, ecore::EObject >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_eAnnotations - Subset<ecore::EAnnotation, ecore::EObject >()" << std::endl;
		#endif
		
		/*Subset*/
		m_eAnnotations->initSubset(getEContens());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_eAnnotations - Subset<ecore::EAnnotation, ecore::EObject >(getEContens())" << std::endl;
		#endif
		
	}

    return m_eAnnotations;
}