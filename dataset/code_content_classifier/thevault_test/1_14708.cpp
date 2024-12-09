PropertyImpl::PropertyImpl(std::weak_ptr<uml::Class > par_class)
:PropertyImpl()
{
	m_class = par_class;
	m_namespace = par_class;
}