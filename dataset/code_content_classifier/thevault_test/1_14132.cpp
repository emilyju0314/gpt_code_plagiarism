ActionInputPinImpl::ActionInputPinImpl(std::weak_ptr<uml::Action > par_action)
:ActionInputPinImpl()
{
	m_action = par_action;
	m_owner = par_action;
}