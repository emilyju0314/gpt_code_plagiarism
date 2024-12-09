void ReadSelfActionActivationImpl::setAction(std::shared_ptr<uml::Action> _action)
{
	std::shared_ptr<uml::ReadSelfAction> _readSelfAction = std::dynamic_pointer_cast<uml::ReadSelfAction>(_action);
	if(_readSelfAction)
	{
		m_readSelfAction = _readSelfAction;

		//additional setter call for redefined reference ActionActivation::action
		fUML::Semantics::Actions::ActionActivationImpl::setAction(_action);
	}
	else
	{
		std::cerr<<"[ReadSelfActionActivation::setAction] : Could not set action because provided action was not of type 'uml::ReadSelfAction'"<<std::endl;
	}
}