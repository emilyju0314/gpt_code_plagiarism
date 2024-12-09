void
TrafficSource::attachTo(Agent * agent) {
  agent_ = agent;
  previous_ = agent_->addTrafficSource(this);
  size(agent_->size()); 
  place();
}