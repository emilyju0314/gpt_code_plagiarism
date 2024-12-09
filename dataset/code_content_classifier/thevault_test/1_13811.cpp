RemoveVariableValueActionImpl::RemoveVariableValueActionImpl(std::weak_ptr<uml::Namespace > par_namespace)
:RemoveVariableValueActionImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}