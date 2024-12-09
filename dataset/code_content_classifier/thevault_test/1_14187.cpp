ElementImportImpl::ElementImportImpl(std::weak_ptr<uml::Namespace > par_importingNamespace)
:ElementImportImpl()
{
	m_importingNamespace = par_importingNamespace;
	m_owner = par_importingNamespace;
}