std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>> CompoundValueImpl::getFeatureValues() const
{
	if(m_featureValues == nullptr)
	{
		m_featureValues.reset(new Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>());
		
		
	}

    return m_featureValues;
}