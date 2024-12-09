ForkNodeImpl::ForkNodeImpl(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode)
:ForkNodeImpl()
{
	m_inStructuredNode = par_inStructuredNode;
	m_owner = par_inStructuredNode;
}