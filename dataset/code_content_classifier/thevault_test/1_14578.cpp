AbstractionImpl::AbstractionImpl(std::weak_ptr<uml::Package > par_owningPackage)
:AbstractionImpl()
{
	m_owningPackage = par_owningPackage;
	m_namespace = par_owningPackage;
}