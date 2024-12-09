std::shared_ptr<Bag<uml::GeneralizationSet>> ClassifierImpl::getPowertypeExtent() const
{
	if(m_powertypeExtent == nullptr)
	{
		m_powertypeExtent.reset(new Bag<uml::GeneralizationSet>());
		
		
	}

    return m_powertypeExtent;
}