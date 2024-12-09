std::shared_ptr<Bag<uml::Connector>> InformationFlowImpl::getRealizingConnector() const
{
	if(m_realizingConnector == nullptr)
	{
		m_realizingConnector.reset(new Bag<uml::Connector>());
		
		
	}

    return m_realizingConnector;
}