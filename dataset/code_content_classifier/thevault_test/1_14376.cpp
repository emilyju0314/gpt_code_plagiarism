OpaqueActionImpl::OpaqueActionImpl(std::weak_ptr<uml::Activity > par_activity)
:OpaqueActionImpl()
{
	m_activity = par_activity;
	m_owner = par_activity;
}