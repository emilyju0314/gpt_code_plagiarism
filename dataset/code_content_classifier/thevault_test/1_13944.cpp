std::shared_ptr<Bag<uml::Classifier>> ReclassifyObjectActionImpl::getOldClassifier() const
{
	if(m_oldClassifier == nullptr)
	{
		m_oldClassifier.reset(new Bag<uml::Classifier>());
		
		
	}

    return m_oldClassifier;
}