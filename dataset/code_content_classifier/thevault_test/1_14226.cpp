ParameterImpl::ParameterImpl(std::weak_ptr<uml::Operation > par_operation)
:ParameterImpl()
{
	m_operation = par_operation;
	m_namespace = par_operation;
}