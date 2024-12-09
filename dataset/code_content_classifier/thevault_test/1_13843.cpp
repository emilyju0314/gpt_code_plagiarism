PinImpl::PinImpl(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode)
:PinImpl()
{
	m_inStructuredNode = par_inStructuredNode;
	m_owner = par_inStructuredNode;
}