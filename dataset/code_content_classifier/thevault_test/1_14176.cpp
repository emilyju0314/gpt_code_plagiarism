std::shared_ptr<Bag<uml::UseCase>> ClassifierImpl::getUseCase() const
{
	if(m_useCase == nullptr)
	{
		m_useCase.reset(new Bag<uml::UseCase>());
		
		
	}

    return m_useCase;
}