ReplyActionImpl::ReplyActionImpl(std::weak_ptr<uml::Namespace > par_namespace)
:ReplyActionImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}