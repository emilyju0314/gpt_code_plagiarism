ExecutionEnvironmentImpl::ExecutionEnvironmentImpl(std::weak_ptr<uml::Namespace > par_namespace)
:ExecutionEnvironmentImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}