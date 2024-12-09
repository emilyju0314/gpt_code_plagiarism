void ReadSelfActionActivationImpl::setNode(std::shared_ptr<uml::ActivityNode> _node)
{
	std::shared_ptr<uml::ReadSelfAction> _readSelfAction = std::dynamic_pointer_cast<uml::ReadSelfAction>(_node);
	if(_readSelfAction)
	{
		m_readSelfAction = _readSelfAction;

		//additional setter call for redefined reference ActionActivation::action
		fUML::Semantics::Actions::ActionActivationImpl::setNode(_node);
	}
	else
	{
		std::cerr<<"[ReadSelfActionActivation::setNode] : Could not set node because provided node was not of type 'uml::ReadSelfAction'"<<std::endl;
	}
}