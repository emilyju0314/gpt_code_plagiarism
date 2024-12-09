PinImpl::PinImpl(std::weak_ptr<uml::Activity > par_activity)
:PinImpl()
{
	m_activity = par_activity;
	m_owner = par_activity;
}