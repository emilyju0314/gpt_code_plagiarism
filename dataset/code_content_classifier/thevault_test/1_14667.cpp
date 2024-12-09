InterfaceRealizationImpl::InterfaceRealizationImpl(std::weak_ptr<uml::Package > par_owningPackage)
:InterfaceRealizationImpl()
{
	m_owningPackage = par_owningPackage;
	m_namespace = par_owningPackage;
}