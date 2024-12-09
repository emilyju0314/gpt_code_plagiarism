std::shared_ptr<Subset<ecore::EObject, ecore::EObject>> EAnnotationImpl::getContents() const
{
	if(m_contents == nullptr)
	{
		/*Subset*/
		m_contents.reset(new Subset<ecore::EObject, ecore::EObject >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_contents - Subset<ecore::EObject, ecore::EObject >()" << std::endl;
		#endif
		
		/*Subset*/
		m_contents->initSubset(getEContens());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_contents - Subset<ecore::EObject, ecore::EObject >(getEContens())" << std::endl;
		#endif
		
	}

    return m_contents;
}