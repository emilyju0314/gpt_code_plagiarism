std::shared_ptr<Bag<uml::Message>> InformationFlowImpl::getRealizingMessage() const
{
	if(m_realizingMessage == nullptr)
	{
		m_realizingMessage.reset(new Bag<uml::Message>());
		
		
	}

    return m_realizingMessage;
}