PropertyImpl::PropertyImpl(std::weak_ptr<uml::Association > par_owningAssociation)
:PropertyImpl()
{
	m_owningAssociation = par_owningAssociation;
	m_namespace = par_owningAssociation;
}