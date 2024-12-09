ProtocolStateMachineImpl::ProtocolStateMachineImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
:ProtocolStateMachineImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}