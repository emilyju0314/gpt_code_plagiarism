ActivityGroupImpl::ActivityGroupImpl(std::weak_ptr<uml::Activity > par_inActivity)
:ActivityGroupImpl()
{
	m_inActivity = par_inActivity;
	m_owner = par_inActivity;
}