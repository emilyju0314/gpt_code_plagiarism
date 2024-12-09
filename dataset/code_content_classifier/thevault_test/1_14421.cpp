InstanceValueImpl::InstanceValueImpl(std::weak_ptr<uml::ValueSpecificationAction > par_valueSpecificationAction)
:InstanceValueImpl()
{
	m_valueSpecificationAction = par_valueSpecificationAction;
	m_owner = par_valueSpecificationAction;
}