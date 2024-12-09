CallBehaviorActionImpl::CallBehaviorActionImpl(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode)
:CallBehaviorActionImpl()
{
	m_inStructuredNode = par_inStructuredNode;
	m_owner = par_inStructuredNode;
}