OpaqueExpressionImpl::OpaqueExpressionImpl(std::weak_ptr<uml::Package > par_owningPackage)
:OpaqueExpressionImpl()
{
	m_owningPackage = par_owningPackage;
	m_namespace = par_owningPackage;
}