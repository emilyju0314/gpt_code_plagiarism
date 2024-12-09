IntervalImpl::IntervalImpl(std::weak_ptr<uml::Package > par_owningPackage)
:IntervalImpl()
{
	m_owningPackage = par_owningPackage;
	m_namespace = par_owningPackage;
}