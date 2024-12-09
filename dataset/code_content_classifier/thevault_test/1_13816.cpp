CallEventImpl::CallEventImpl(std::weak_ptr<uml::Package > par_owningPackage)
:CallEventImpl()
{
	m_owningPackage = par_owningPackage;
	m_namespace = par_owningPackage;
}