DurationIntervalImpl::DurationIntervalImpl(std::weak_ptr<uml::ValueSpecificationAction > par_valueSpecificationAction)
:DurationIntervalImpl()
{
	m_valueSpecificationAction = par_valueSpecificationAction;
	m_owner = par_valueSpecificationAction;
}