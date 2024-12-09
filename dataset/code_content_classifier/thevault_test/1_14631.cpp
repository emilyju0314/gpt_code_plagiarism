AcceptEventActionImpl::AcceptEventActionImpl(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode)
:AcceptEventActionImpl()
{
	m_inStructuredNode = par_inStructuredNode;
	m_owner = par_inStructuredNode;
}