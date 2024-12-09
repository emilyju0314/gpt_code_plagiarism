UsageImpl::UsageImpl(std::weak_ptr<uml::Package > par_owningPackage)
:UsageImpl()
{
	m_owningPackage = par_owningPackage;
	m_namespace = par_owningPackage;
}