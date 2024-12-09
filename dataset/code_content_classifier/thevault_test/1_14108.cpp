ExpressionImpl::ExpressionImpl(std::weak_ptr<uml::Package > par_owningPackage)
:ExpressionImpl()
{
	m_owningPackage = par_owningPackage;
	m_namespace = par_owningPackage;
}