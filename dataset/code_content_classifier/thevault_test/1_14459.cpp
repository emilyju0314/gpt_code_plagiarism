PortImpl::PortImpl(std::weak_ptr<uml::Property > par_associationEnd)
:PortImpl()
{
	m_associationEnd = par_associationEnd;
	m_owner = par_associationEnd;
}