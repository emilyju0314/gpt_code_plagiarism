IncludeImpl::IncludeImpl(std::weak_ptr<uml::UseCase > par_includingCase)
:IncludeImpl()
{
	m_includingCase = par_includingCase;
	m_namespace = par_includingCase;
}