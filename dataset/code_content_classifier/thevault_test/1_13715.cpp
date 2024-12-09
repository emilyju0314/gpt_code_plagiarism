void CallBehaviorActionActivationImpl::setNode(std::shared_ptr<uml::ActivityNode> _node)
{
	std::shared_ptr<uml::CallBehaviorAction> _callBehaviorAction = std::dynamic_pointer_cast<uml::CallBehaviorAction>(_node);
	if(_callBehaviorAction)
	{
		m_callBehaviorAction = _callBehaviorAction;

		//additional setter call for redefined reference CallActionActivation::callAction
		fUML::Semantics::Actions::CallActionActivationImpl::setNode(_node);
	}
	else
	{
		std::cerr<<"[CallBehaviorActionActivation::setNode] : Could not set node because provided node was not of type 'uml::CallBehaviorAction'"<<std::endl;
	}
}