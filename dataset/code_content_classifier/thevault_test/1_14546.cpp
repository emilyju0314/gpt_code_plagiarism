std::shared_ptr<Subset<ecore::EOperation, ecore::EObject>> EClassImpl::getEOperations() const
{
	if(m_eOperations == nullptr)
	{
		/*Subset*/
		m_eOperations.reset(new Subset<ecore::EOperation, ecore::EObject >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_eOperations - Subset<ecore::EOperation, ecore::EObject >()" << std::endl;
		#endif
		
		/*Subset*/
		m_eOperations->initSubset(getEContens());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_eOperations - Subset<ecore::EOperation, ecore::EObject >(getEContens())" << std::endl;
		#endif
		
	}

    return m_eOperations;
}