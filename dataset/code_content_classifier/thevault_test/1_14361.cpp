DurationObservationImpl::DurationObservationImpl(std::weak_ptr<uml::Package > par_owningPackage)
:DurationObservationImpl()
{
	m_owningPackage = par_owningPackage;
	m_namespace = par_owningPackage;
}