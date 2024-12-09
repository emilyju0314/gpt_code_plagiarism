InstanceSpecificationImpl::InstanceSpecificationImpl(std::weak_ptr<uml::Package > par_owningPackage)
:InstanceSpecificationImpl()
{
	m_owningPackage = par_owningPackage;
	m_namespace = par_owningPackage;
}