ComponentRealizationImpl::ComponentRealizationImpl(std::weak_ptr<uml::Package > par_owningPackage)
:ComponentRealizationImpl()
{
	m_owningPackage = par_owningPackage;
	m_namespace = par_owningPackage;
}