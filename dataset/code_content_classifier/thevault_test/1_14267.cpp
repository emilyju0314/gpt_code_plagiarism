AcceptCallActionImpl::AcceptCallActionImpl(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode)
:AcceptCallActionImpl()
{
	m_inStructuredNode = par_inStructuredNode;
	m_owner = par_inStructuredNode;
}