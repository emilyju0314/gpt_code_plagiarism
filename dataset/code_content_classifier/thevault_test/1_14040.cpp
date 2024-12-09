AddVariableValueActionImpl::AddVariableValueActionImpl(std::weak_ptr<uml::Namespace > par_namespace)
:AddVariableValueActionImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}