std::shared_ptr<uml::Behavior > ExecutionImpl::getBehavior() const
{
	//generated from getterbody annotation
if(!m_behavior)
{
	m_behavior = std::dynamic_pointer_cast<uml::Behavior>(this->getTypes()->front());
}

return m_behavior;
	//end of body
}