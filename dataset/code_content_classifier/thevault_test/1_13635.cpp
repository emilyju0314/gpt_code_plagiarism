void CallOperationActionActivationImpl::setAction(std::shared_ptr<uml::Action> _action)
{
	std::shared_ptr<uml::CallOperationAction> _callOperationAction = std::dynamic_pointer_cast<uml::CallOperationAction>(_action);
	if(_callOperationAction)
	{
		m_callOperationAction = _callOperationAction;

		//additional setter call for redefined reference CallActionActivation::callAction
		fUML::Semantics::Actions::CallActionActivationImpl::setAction(_action);
	}
	else
	{
		std::cerr<<"[CallOperationActionActivation::setAction] : Could not set action because provided action was not of type 'uml::CallOperationAction'"<<std::endl;
	}
}