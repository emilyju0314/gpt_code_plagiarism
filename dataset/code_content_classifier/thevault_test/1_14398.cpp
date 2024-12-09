std::shared_ptr<Bag<uml::ActivityEdge>> InformationFlowImpl::getRealizingActivityEdge() const
{
	if(m_realizingActivityEdge == nullptr)
	{
		m_realizingActivityEdge.reset(new Bag<uml::ActivityEdge>());
		
		
	}

    return m_realizingActivityEdge;
}