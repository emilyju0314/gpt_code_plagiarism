void PinActivationImpl::setNode(std::shared_ptr<uml::ActivityNode> _node)
{
	std::shared_ptr<uml::Pin> _pin = std::dynamic_pointer_cast<uml::Pin>(_node);
	if(_pin)
	{
		m_pin = _pin;

		//additional setter call for redefined reference ActivityNodeActivation::node
		fUML::Semantics::Activities::ActivityNodeActivationImpl::setNode(_node);
	}
	else
	{
		std::cerr<<"[PinActivation::setNode] : Could not set node because provided node was not of type 'uml::Pin'"<<std::endl;
	}
}