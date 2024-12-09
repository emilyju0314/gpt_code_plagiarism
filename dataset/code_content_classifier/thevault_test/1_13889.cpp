ExecutionEnvironmentImpl::ExecutionEnvironmentImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
:ExecutionEnvironmentImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}