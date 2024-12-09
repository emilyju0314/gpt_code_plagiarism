std::shared_ptr<Bag<uml::Observation>> TimeExpressionImpl::getObservation() const
{
	if(m_observation == nullptr)
	{
		m_observation.reset(new Bag<uml::Observation>());
		
		
	}

    return m_observation;
}