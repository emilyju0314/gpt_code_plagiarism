std::shared_ptr<Bag<uml::Extension>> ClassImpl::getExtension() const
{
	if(m_extension == nullptr)
	{
		m_extension.reset(new Bag<uml::Extension>());
		
		
	}

    return m_extension;
}