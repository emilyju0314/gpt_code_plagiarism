PortImpl::PortImpl(std::weak_ptr<uml::DataType > par_datatype)
:PortImpl()
{
	m_datatype = par_datatype;
	m_namespace = par_datatype;
}