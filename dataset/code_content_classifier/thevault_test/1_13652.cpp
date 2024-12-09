InputPinImpl::InputPinImpl(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode)
:InputPinImpl()
{
	m_inStructuredNode = par_inStructuredNode;
	m_owner = par_inStructuredNode;
}