ExtensionPointImpl::ExtensionPointImpl(std::weak_ptr<uml::UseCase > par_useCase)
:ExtensionPointImpl()
{
	m_useCase = par_useCase;
	m_namespace = par_useCase;
}