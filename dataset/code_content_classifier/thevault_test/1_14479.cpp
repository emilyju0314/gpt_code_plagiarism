std::shared_ptr<Bag<uml::Clause>> ConditionalNodeActivationImpl::getSelectedClauses() const
{
	if(m_selectedClauses == nullptr)
	{
		m_selectedClauses.reset(new Bag<uml::Clause>());
		
		
	}

    return m_selectedClauses;
}