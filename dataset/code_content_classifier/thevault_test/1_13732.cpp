std::shared_ptr<Subset<ecore::EParameter, ecore::EObject>> EOperationImpl::getEParameters() const
{
	if(m_eParameters == nullptr)
	{
		/*Subset*/
		m_eParameters.reset(new Subset<ecore::EParameter, ecore::EObject >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_eParameters - Subset<ecore::EParameter, ecore::EObject >()" << std::endl;
		#endif
		
		/*Subset*/
		m_eParameters->initSubset(getEContens());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_eParameters - Subset<ecore::EParameter, ecore::EObject >(getEContens())" << std::endl;
		#endif
		
	}

    return m_eParameters;
}