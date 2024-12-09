ConstraintImpl::ConstraintImpl(std::weak_ptr<uml::Package > par_owningPackage)
:ConstraintImpl()
{
	m_owningPackage = par_owningPackage;
	m_namespace = par_owningPackage;
}