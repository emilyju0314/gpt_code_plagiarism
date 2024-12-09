ObjectNodeImpl::ObjectNodeImpl(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode)
:ObjectNodeImpl()
{
	m_inStructuredNode = par_inStructuredNode;
	m_owner = par_inStructuredNode;
}