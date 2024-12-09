LiteralStringImpl::LiteralStringImpl(std::weak_ptr<uml::Package > par_owningPackage)
:LiteralStringImpl()
{
	m_owningPackage = par_owningPackage;
	m_namespace = par_owningPackage;
}