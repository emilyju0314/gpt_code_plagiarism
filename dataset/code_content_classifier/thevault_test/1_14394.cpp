std::shared_ptr<Bag<uml::Classifier>> InformationFlowImpl::getConveyed() const
{
	if(m_conveyed == nullptr)
	{
		m_conveyed.reset(new Bag<uml::Classifier>());
		
		
	}
//assert(m_conveyed);
    return m_conveyed;
}