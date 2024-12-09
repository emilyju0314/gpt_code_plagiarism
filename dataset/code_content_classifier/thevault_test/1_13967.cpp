IntervalImpl::IntervalImpl(std::weak_ptr<uml::ValueSpecificationAction > par_valueSpecificationAction)
:IntervalImpl()
{
	m_valueSpecificationAction = par_valueSpecificationAction;
	m_owner = par_valueSpecificationAction;
}