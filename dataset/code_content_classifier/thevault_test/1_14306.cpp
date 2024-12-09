LiteralSpecificationImpl::LiteralSpecificationImpl(std::weak_ptr<uml::Package > par_owningPackage)
:LiteralSpecificationImpl()
{
	m_owningPackage = par_owningPackage;
	m_namespace = par_owningPackage;
}