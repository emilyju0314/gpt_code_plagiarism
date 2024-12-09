PrimitiveTypeImpl::PrimitiveTypeImpl(std::weak_ptr<uml::Namespace > par_namespace)
:PrimitiveTypeImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}