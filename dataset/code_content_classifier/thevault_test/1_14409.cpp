ReplyActionImpl::ReplyActionImpl(std::weak_ptr<uml::Activity > par_activity)
:ReplyActionImpl()
{
	m_activity = par_activity;
	m_owner = par_activity;
}