std::shared_ptr<Bag<uml::Classifier>> ClassifierImpl::getGeneral() const
{
	if(m_general == nullptr)
	{
		m_general.reset(new Bag<uml::Classifier>());
		
		
	}

    return m_general;
}