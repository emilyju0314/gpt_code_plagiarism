JoinNodeImpl::JoinNodeImpl(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode)
:JoinNodeImpl()
{
	m_inStructuredNode = par_inStructuredNode;
	m_owner = par_inStructuredNode;
}