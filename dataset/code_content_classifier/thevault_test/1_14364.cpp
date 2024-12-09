std::shared_ptr<Bag<uml::NamedElement>> DurationObservationImpl::getEvent() const
{
	if(m_event == nullptr)
	{
		m_event.reset(new Bag<uml::NamedElement>());
		
		
	}
//assert(m_event);
    return m_event;
}