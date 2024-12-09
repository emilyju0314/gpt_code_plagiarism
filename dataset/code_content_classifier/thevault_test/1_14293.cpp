CreateObjectActionImpl::CreateObjectActionImpl(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode)
:CreateObjectActionImpl()
{
	m_inStructuredNode = par_inStructuredNode;
	m_owner = par_inStructuredNode;
}