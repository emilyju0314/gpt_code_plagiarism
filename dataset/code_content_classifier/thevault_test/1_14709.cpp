PropertyImpl::PropertyImpl(std::weak_ptr<uml::DataType > par_datatype)
:PropertyImpl()
{
	m_datatype = par_datatype;
	m_namespace = par_datatype;
}