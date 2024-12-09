PackageableElementImpl::PackageableElementImpl(std::weak_ptr<uml::Package > par_owningPackage)
:PackageableElementImpl()
{
	m_owningPackage = par_owningPackage;
	m_namespace = par_owningPackage;
}