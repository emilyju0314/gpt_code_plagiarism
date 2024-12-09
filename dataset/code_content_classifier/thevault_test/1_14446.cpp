std::shared_ptr<Bag<fUML::Semantics::Actions::OutputPinActivation>> ExpansionActivationGroupImpl::getRegionInputs() const
{
	if(m_regionInputs == nullptr)
	{
		m_regionInputs.reset(new Bag<fUML::Semantics::Actions::OutputPinActivation>());
		
		
	}

    return m_regionInputs;
}