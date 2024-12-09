std::shared_ptr<Bag<fUML::Semantics::Activities::Offer>> ActivityEdgeInstanceImpl::getOffers() const
{
	if(m_offers == nullptr)
	{
		m_offers.reset(new Bag<fUML::Semantics::Activities::Offer>());
		
		
	}

    return m_offers;
}