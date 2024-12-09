PropertyImpl::PropertyImpl(std::weak_ptr<uml::Property > par_associationEnd)
:PropertyImpl()
{
	m_associationEnd = par_associationEnd;
	m_owner = par_associationEnd;
}