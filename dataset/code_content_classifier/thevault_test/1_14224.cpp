ParameterImpl::ParameterImpl(std::weak_ptr<uml::Behavior > par_behavior)
:ParameterImpl()
{
	m_behavior = par_behavior;
	m_namespace = par_behavior;
}