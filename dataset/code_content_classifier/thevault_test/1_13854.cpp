DurationConstraintImpl::DurationConstraintImpl(std::weak_ptr<uml::Package > par_owningPackage)
:DurationConstraintImpl()
{
	m_owningPackage = par_owningPackage;
	m_namespace = par_owningPackage;
}