std::shared_ptr<Bag<uml::ExpansionNode>> ExpansionRegionImpl::getOutputElement() const
{
	if(m_outputElement == nullptr)
	{
		m_outputElement.reset(new Bag<uml::ExpansionNode>());
		
		
	}

    return m_outputElement;
}