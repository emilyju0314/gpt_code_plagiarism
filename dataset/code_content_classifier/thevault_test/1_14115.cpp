IntervalConstraintImpl::IntervalConstraintImpl(std::weak_ptr<uml::Package > par_owningPackage)
:IntervalConstraintImpl()
{
	m_owningPackage = par_owningPackage;
	m_namespace = par_owningPackage;
}