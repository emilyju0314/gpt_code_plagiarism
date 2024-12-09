StartClassifierBehaviorActionImpl::StartClassifierBehaviorActionImpl(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode)
:StartClassifierBehaviorActionImpl()
{
	m_inStructuredNode = par_inStructuredNode;
	m_owner = par_inStructuredNode;
}