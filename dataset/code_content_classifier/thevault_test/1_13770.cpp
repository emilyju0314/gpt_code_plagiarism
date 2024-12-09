std::shared_ptr<Bag<uml::Dependency>> NamedElementImpl::getClientDependency() const
{
	if(m_clientDependency == nullptr)
	{
		m_clientDependency.reset(new Bag<uml::Dependency>());
		
		
	}

    return m_clientDependency;
}