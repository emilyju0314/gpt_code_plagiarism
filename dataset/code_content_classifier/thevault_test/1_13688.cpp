LiteralIntegerImpl::LiteralIntegerImpl(std::weak_ptr<uml::Package > par_owningPackage)
:LiteralIntegerImpl()
{
	m_owningPackage = par_owningPackage;
	m_namespace = par_owningPackage;
}