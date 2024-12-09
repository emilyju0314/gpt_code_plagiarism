PropertyImpl::PropertyImpl(std::weak_ptr<uml::Interface > par_interface)
:PropertyImpl()
{
	m_interface = par_interface;
	m_namespace = par_interface;
}