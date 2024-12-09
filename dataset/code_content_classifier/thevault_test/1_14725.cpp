std::shared_ptr<Bag<uml::Property>> PropertyImpl::getSubsettedProperty() const
{
	if(m_subsettedProperty == nullptr)
	{
		m_subsettedProperty.reset(new Bag<uml::Property>());
		
		
	}

    return m_subsettedProperty;
}