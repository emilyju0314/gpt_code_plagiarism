PortImpl::PortImpl(std::weak_ptr<uml::Interface > par_interface)
:PortImpl()
{
	m_interface = par_interface;
	m_namespace = par_interface;
}