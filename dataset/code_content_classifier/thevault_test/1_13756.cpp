std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> TokenSetImpl::getTokens() const
{
	if(m_tokens == nullptr)
	{
		m_tokens.reset(new Bag<fUML::Semantics::Activities::Token>());
		
		
	}

    return m_tokens;
}