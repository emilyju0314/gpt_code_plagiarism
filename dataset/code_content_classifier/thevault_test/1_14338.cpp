TimeEventImpl::TimeEventImpl(std::weak_ptr<uml::Package > par_owningPackage)
:TimeEventImpl()
{
	m_owningPackage = par_owningPackage;
	m_namespace = par_owningPackage;
}