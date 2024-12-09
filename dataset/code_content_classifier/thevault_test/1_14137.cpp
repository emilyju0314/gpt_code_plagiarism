ActionInputPinImpl::ActionInputPinImpl(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode)
:ActionInputPinImpl()
{
	m_inStructuredNode = par_inStructuredNode;
	m_owner = par_inStructuredNode;
}