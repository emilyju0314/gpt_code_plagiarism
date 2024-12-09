TimeConstraintImpl::TimeConstraintImpl(std::weak_ptr<uml::Package > par_owningPackage)
:TimeConstraintImpl()
{
	m_owningPackage = par_owningPackage;
	m_namespace = par_owningPackage;
}