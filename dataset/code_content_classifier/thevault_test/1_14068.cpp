EventImpl::EventImpl(std::weak_ptr<uml::Package > par_owningPackage)
:EventImpl()
{
	m_owningPackage = par_owningPackage;
	m_namespace = par_owningPackage;
}