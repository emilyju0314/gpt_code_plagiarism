EnumerationLiteralImpl::EnumerationLiteralImpl(std::weak_ptr<uml::Package > par_owningPackage)
:EnumerationLiteralImpl()
{
	m_owningPackage = par_owningPackage;
	m_namespace = par_owningPackage;
}