ClearAssociationActionImpl::ClearAssociationActionImpl(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode)
:ClearAssociationActionImpl()
{
	m_inStructuredNode = par_inStructuredNode;
	m_owner = par_inStructuredNode;
}