std::shared_ptr<Bag<uml::Classifier>> InstanceSpecificationImpl::getClassifier() const
{
	if(m_classifier == nullptr)
	{
		m_classifier.reset(new Bag<uml::Classifier>());
		
		
	}

    return m_classifier;
}