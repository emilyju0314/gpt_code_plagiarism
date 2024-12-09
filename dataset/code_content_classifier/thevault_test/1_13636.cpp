void CallOperationActionActivationImpl::setNode(std::shared_ptr<uml::ActivityNode> _node)
{
	std::shared_ptr<uml::CallOperationAction> _callOperationAction = std::dynamic_pointer_cast<uml::CallOperationAction>(_node);
	if(_callOperationAction)
	{
		m_callOperationAction = _callOperationAction;

		//additional setter call for redefined reference CallActionActivation::callAction
		fUML::Semantics::Actions::CallActionActivationImpl::setNode(_node);
	}
	else
	{
		std::cerr<<"[CallOperationActionActivation::setNode] : Could not set node because provided node was not of type 'uml::CallOperationAction'"<<std::endl;
	}
}