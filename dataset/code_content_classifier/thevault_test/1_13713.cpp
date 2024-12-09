void CallBehaviorActionActivationImpl::setCallAction(std::shared_ptr<uml::CallAction> _callAction)
{
	std::shared_ptr<uml::CallBehaviorAction> _callBehaviorAction = std::dynamic_pointer_cast<uml::CallBehaviorAction>(_callAction);
	if(_callBehaviorAction)
	{
		m_callBehaviorAction = _callBehaviorAction;

		//additional setter call for redefined reference CallActionActivation::callAction
		fUML::Semantics::Actions::CallActionActivationImpl::setCallAction(_callAction);
	}
	else
	{
		std::cerr<<"[CallBehaviorActionActivation::setCallAction] : Could not set callAction because provided callAction was not of type 'uml::CallBehaviorAction'"<<std::endl;
	}
}