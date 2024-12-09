PortImpl::PortImpl(std::weak_ptr<uml::Association > par_owningAssociation)
:PortImpl()
{
	m_owningAssociation = par_owningAssociation;
	m_namespace = par_owningAssociation;
}