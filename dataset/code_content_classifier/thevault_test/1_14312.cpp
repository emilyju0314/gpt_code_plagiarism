DurationIntervalImpl::DurationIntervalImpl(std::weak_ptr<uml::Package > par_owningPackage)
:DurationIntervalImpl()
{
	m_owningPackage = par_owningPackage;
	m_namespace = par_owningPackage;
}