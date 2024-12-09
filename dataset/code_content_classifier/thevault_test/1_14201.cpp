std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityEdgeInstance>> ActivityNodeActivationImpl::getIncomingEdges() const
{
	if(m_incomingEdges == nullptr)
	{
		m_incomingEdges.reset(new Bag<fUML::Semantics::Activities::ActivityEdgeInstance>());
		
		
	}

    return m_incomingEdges;
}