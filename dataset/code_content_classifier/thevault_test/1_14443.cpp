std::shared_ptr<Bag<fUML::Semantics::Activities::ExpansionNodeActivation>> ExpansionActivationGroupImpl::getGroupInputs() const
{
	if(m_groupInputs == nullptr)
	{
		m_groupInputs.reset(new Bag<fUML::Semantics::Activities::ExpansionNodeActivation>());
		
		
	}

    return m_groupInputs;
}