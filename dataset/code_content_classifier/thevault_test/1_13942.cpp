std::shared_ptr<Bag<uml::Classifier>> ReclassifyObjectActionImpl::getNewClassifier() const
{
	if(m_newClassifier == nullptr)
	{
		m_newClassifier.reset(new Bag<uml::Classifier>());
		
		
	}

    return m_newClassifier;
}