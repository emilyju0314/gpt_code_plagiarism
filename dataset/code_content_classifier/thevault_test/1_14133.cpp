ActionInputPinImpl::ActionInputPinImpl(std::weak_ptr<uml::Activity > par_activity)
:ActionInputPinImpl()
{
	m_activity = par_activity;
	m_owner = par_activity;
}