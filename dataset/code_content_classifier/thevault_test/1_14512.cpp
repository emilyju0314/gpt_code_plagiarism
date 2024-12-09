OpaqueExpressionImpl::OpaqueExpressionImpl(std::weak_ptr<uml::ValueSpecificationAction > par_valueSpecificationAction)
:OpaqueExpressionImpl()
{
	m_valueSpecificationAction = par_valueSpecificationAction;
	m_owner = par_valueSpecificationAction;
}