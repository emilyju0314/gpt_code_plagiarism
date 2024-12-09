void CallBehaviorActionActivationImpl::setAction(std::shared_ptr<uml::Action> _action)
{
	std::shared_ptr<uml::CallBehaviorAction> _callBehaviorAction = std::dynamic_pointer_cast<uml::CallBehaviorAction>(_action);
	if(_callBehaviorAction)
	{
		m_callBehaviorAction = _callBehaviorAction;

		//additional setter call for redefined reference CallActionActivation::callAction
		fUML::Semantics::Actions::CallActionActivationImpl::setAction(_action);
	}
	else
	{
		std::cerr<<"[CallBehaviorActionActivation::setAction] : Could not set action because provided action was not of type 'uml::CallBehaviorAction'"<<std::endl;
	}
}