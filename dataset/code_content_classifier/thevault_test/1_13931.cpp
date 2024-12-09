DependencyImpl::DependencyImpl(std::weak_ptr<uml::Package > par_owningPackage)
:DependencyImpl()
{
	m_owningPackage = par_owningPackage;
	m_namespace = par_owningPackage;
}