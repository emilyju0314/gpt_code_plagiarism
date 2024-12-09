TimeExpressionImpl::TimeExpressionImpl(std::weak_ptr<uml::ValueSpecificationAction > par_valueSpecificationAction)
:TimeExpressionImpl()
{
	m_valueSpecificationAction = par_valueSpecificationAction;
	m_owner = par_valueSpecificationAction;
}