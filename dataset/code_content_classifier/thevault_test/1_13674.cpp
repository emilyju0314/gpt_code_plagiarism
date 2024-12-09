CommunicationPathImpl::CommunicationPathImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
:CommunicationPathImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}