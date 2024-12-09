ObservationImpl::ObservationImpl(std::weak_ptr<uml::Package > par_owningPackage)
:ObservationImpl()
{
	m_owningPackage = par_owningPackage;
	m_namespace = par_owningPackage;
}