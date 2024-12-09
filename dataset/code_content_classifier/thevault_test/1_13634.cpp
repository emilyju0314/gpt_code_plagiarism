void CallOperationActionActivationImpl::setCallAction(std::shared_ptr<uml::CallAction> _callAction)
{
	std::shared_ptr<uml::CallOperationAction> _callOperationAction = std::dynamic_pointer_cast<uml::CallOperationAction>(_callAction);
	if(_callOperationAction)
	{
		m_callOperationAction = _callOperationAction;

		//additional setter call for redefined reference CallActionActivation::callAction
		fUML::Semantics::Actions::CallActionActivationImpl::setCallAction(_callAction);
	}
	else
	{
		std::cerr<<"[CallOperationActionActivation::setCallAction] : Could not set callAction because provided callAction was not of type 'uml::CallOperationAction'"<<std::endl;
	}
}