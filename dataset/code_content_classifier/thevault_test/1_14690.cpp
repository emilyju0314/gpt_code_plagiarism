BehaviorExecutionSpecificationImpl::BehaviorExecutionSpecificationImpl(std::weak_ptr<uml::Namespace > par_namespace)
:BehaviorExecutionSpecificationImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}