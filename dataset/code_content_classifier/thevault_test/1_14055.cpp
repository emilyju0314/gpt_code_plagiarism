LiteralStringImpl::LiteralStringImpl(std::weak_ptr<uml::ValueSpecificationAction > par_valueSpecificationAction)
:LiteralStringImpl()
{
	m_valueSpecificationAction = par_valueSpecificationAction;
	m_owner = par_valueSpecificationAction;
}