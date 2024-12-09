ComponentRealizationImpl::ComponentRealizationImpl(std::weak_ptr<uml::Component > par_abstraction)
:ComponentRealizationImpl()
{
	m_abstraction = par_abstraction;
	m_owner = par_abstraction;
}