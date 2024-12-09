InstanceSpecificationImpl::InstanceSpecificationImpl(std::weak_ptr<uml::Namespace > par_namespace)
:InstanceSpecificationImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}