ActorImpl::ActorImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
:ActorImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}