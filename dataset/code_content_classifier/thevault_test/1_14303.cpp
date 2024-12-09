std::shared_ptr<Bag<fUML::Semantics::Loci::SemanticStrategy>> ExecutionFactoryImpl::getStrategies() const
{
	if(m_strategies == nullptr)
	{
		m_strategies.reset(new Bag<fUML::Semantics::Loci::SemanticStrategy>());
		
		
	}

    return m_strategies;
}