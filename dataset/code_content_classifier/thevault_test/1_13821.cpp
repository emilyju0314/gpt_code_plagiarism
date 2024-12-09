GeneralizationSetImpl::GeneralizationSetImpl(std::weak_ptr<uml::Package > par_owningPackage)
:GeneralizationSetImpl()
{
	m_owningPackage = par_owningPackage;
	m_namespace = par_owningPackage;
}