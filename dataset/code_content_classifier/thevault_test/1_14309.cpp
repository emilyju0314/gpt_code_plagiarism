LiteralSpecificationImpl::LiteralSpecificationImpl(std::weak_ptr<uml::ValueSpecificationAction > par_valueSpecificationAction)
:LiteralSpecificationImpl()
{
	m_valueSpecificationAction = par_valueSpecificationAction;
	m_owner = par_valueSpecificationAction;
}