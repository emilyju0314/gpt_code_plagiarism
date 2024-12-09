std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> ActivityNodeActivationImpl::getHeldTokens() const
{
	if(m_heldTokens == nullptr)
	{
		m_heldTokens.reset(new Bag<fUML::Semantics::Activities::Token>());
		
		
	}

    return m_heldTokens;
}