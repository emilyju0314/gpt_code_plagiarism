InputPinImpl::InputPinImpl(std::weak_ptr<uml::Action > par_action)
:InputPinImpl()
{
	m_action = par_action;
	m_owner = par_action;
}