CallActionImpl::CallActionImpl(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode)
:CallActionImpl()
{
	m_inStructuredNode = par_inStructuredNode;
	m_owner = par_inStructuredNode;
}