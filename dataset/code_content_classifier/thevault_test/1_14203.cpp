std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityEdgeInstance>> ActivityNodeActivationImpl::getOutgoingEdges() const
{
	if(m_outgoingEdges == nullptr)
	{
		m_outgoingEdges.reset(new Bag<fUML::Semantics::Activities::ActivityEdgeInstance>());
		
		
	}

    return m_outgoingEdges;
}