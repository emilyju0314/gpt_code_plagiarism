ExpressionImpl::ExpressionImpl(std::weak_ptr<uml::ValueSpecificationAction > par_valueSpecificationAction)
:ExpressionImpl()
{
	m_valueSpecificationAction = par_valueSpecificationAction;
	m_owner = par_valueSpecificationAction;
}