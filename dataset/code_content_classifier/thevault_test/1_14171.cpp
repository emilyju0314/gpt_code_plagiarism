std::shared_ptr<Subset<uml::UseCase, uml::NamedElement>> ClassifierImpl::getOwnedUseCase() const
{
	if(m_ownedUseCase == nullptr)
	{
		/*Subset*/
		m_ownedUseCase.reset(new Subset<uml::UseCase, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_ownedUseCase - Subset<uml::UseCase, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		m_ownedUseCase->initSubset(getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_ownedUseCase - Subset<uml::UseCase, uml::NamedElement >(getOwnedMember())" << std::endl;
		#endif
		
	}

    return m_ownedUseCase;
}