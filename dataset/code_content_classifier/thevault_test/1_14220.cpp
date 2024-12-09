std::shared_ptr<Bag<ecore::EStringToStringMapEntry>> EAnnotationImpl::getDetails() const
{
	if(m_details == nullptr)
	{
		m_details.reset(new Bag<ecore::EStringToStringMapEntry>());
		
		
	}

    return m_details;
}