InputPinImpl::InputPinImpl(std::weak_ptr<uml::Activity > par_activity)
:InputPinImpl()
{
	m_activity = par_activity;
	m_owner = par_activity;
}