std::shared_ptr<Bag<uml::OutputPin>> ConditionalNodeImpl::getResult() const
{
	if(m_result == nullptr)
	{
		m_result.reset(new Bag<uml::OutputPin>());
		
		
	}

    return m_result;
}