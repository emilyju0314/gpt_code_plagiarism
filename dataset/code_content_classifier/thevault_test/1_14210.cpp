TimeExpressionImpl::TimeExpressionImpl(std::weak_ptr<uml::Package > par_owningPackage)
:TimeExpressionImpl()
{
	m_owningPackage = par_owningPackage;
	m_namespace = par_owningPackage;
}