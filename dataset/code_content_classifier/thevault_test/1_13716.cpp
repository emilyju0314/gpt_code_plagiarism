PackageImportImpl::PackageImportImpl(std::weak_ptr<uml::Namespace > par_importingNamespace)
:PackageImportImpl()
{
	m_importingNamespace = par_importingNamespace;
	m_owner = par_importingNamespace;
}