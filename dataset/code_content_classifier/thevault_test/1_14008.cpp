EncapsulatedClassifierImpl::EncapsulatedClassifierImpl(std::weak_ptr<uml::Namespace > par_namespace)
:EncapsulatedClassifierImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}