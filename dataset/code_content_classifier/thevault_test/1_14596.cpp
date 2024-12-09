ChangeEventImpl::ChangeEventImpl(std::weak_ptr<uml::Package > par_owningPackage)
:ChangeEventImpl()
{
	m_owningPackage = par_owningPackage;
	m_namespace = par_owningPackage;
}