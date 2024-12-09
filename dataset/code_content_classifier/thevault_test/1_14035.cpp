ManifestationImpl::ManifestationImpl(std::weak_ptr<uml::Package > par_owningPackage)
:ManifestationImpl()
{
	m_owningPackage = par_owningPackage;
	m_namespace = par_owningPackage;
}