std::shared_ptr<Bag<uml::ExpansionNode>> ExpansionRegionImpl::getInputElement() const
{
	if(m_inputElement == nullptr)
	{
		m_inputElement.reset(new Bag<uml::ExpansionNode>());
		
		
	}
//assert(m_inputElement);
    return m_inputElement;
}