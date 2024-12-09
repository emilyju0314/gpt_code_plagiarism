std::shared_ptr<Bag<fUML::Semantics::Activities::ExpansionNodeActivation>> ExpansionActivationGroupImpl::getGroupOutputs() const
{
	if(m_groupOutputs == nullptr)
	{
		m_groupOutputs.reset(new Bag<fUML::Semantics::Activities::ExpansionNodeActivation>());
		
		
	}

    return m_groupOutputs;
}