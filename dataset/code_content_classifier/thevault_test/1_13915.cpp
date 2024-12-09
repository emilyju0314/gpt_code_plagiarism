CallBehaviorActionImpl::CallBehaviorActionImpl(std::weak_ptr<uml::Namespace > par_namespace)
:CallBehaviorActionImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}