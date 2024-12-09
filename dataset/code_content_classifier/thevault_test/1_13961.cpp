std::shared_ptr<Bag<uml::Class>> ClassImpl::getSuperClass() const
{
	if(m_superClass == nullptr)
	{
		m_superClass.reset(new Bag<uml::Class>());
		
		
	}

    return m_superClass;
}