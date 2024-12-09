std::shared_ptr<Bag<uml::State>> ObjectNodeImpl::getInState() const
{
	if(m_inState == nullptr)
	{
		m_inState.reset(new Bag<uml::State>());
		
		
	}

    return m_inState;
}