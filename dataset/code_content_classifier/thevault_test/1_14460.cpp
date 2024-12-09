PortImpl::PortImpl(std::weak_ptr<uml::Class > par_class)
:PortImpl()
{
	m_class = par_class;
	m_namespace = par_class;
}