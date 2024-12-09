OpaqueActionImpl::OpaqueActionImpl(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode)
:OpaqueActionImpl()
{
	m_inStructuredNode = par_inStructuredNode;
	m_owner = par_inStructuredNode;
}