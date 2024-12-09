InstanceValueImpl::InstanceValueImpl(std::weak_ptr<uml::Package > par_owningPackage)
:InstanceValueImpl()
{
	m_owningPackage = par_owningPackage;
	m_namespace = par_owningPackage;
}