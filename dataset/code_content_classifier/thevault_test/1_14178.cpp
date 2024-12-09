OperationTemplateParameterImpl::OperationTemplateParameterImpl(std::weak_ptr<uml::TemplateSignature > par_signature)
:OperationTemplateParameterImpl()
{
	m_signature = par_signature;
	m_owner = par_signature;
}