std::shared_ptr<Bag<uml::Classifier>> InformationItemImpl::getRepresented() const
{
	if(m_represented == nullptr)
	{
		m_represented.reset(new Bag<uml::Classifier>());
		
		
	}

    return m_represented;
}