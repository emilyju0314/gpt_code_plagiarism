std::shared_ptr<Bag<std::string> > OpaqueActionImpl::getBody() const 
{
	if(m_body == nullptr)
	{
		m_body.reset(new Bag<std::string>());
	}
	return m_body;
}