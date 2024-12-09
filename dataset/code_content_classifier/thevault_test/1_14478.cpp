std::shared_ptr<Bag<fUML::Semantics::Actions::ClauseActivation>> ConditionalNodeActivationImpl::getClauseActivations() const
{
	if(m_clauseActivations == nullptr)
	{
		m_clauseActivations.reset(new Bag<fUML::Semantics::Actions::ClauseActivation>());
		
		
	}

    return m_clauseActivations;
}