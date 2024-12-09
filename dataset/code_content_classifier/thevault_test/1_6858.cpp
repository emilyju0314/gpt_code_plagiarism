void
TrafficSource::placeOnAgent() { 
  if (agent_) {
    x_ = agent_->x();
    y_ = agent_->y() + agent_->height(); // Agent scales it's height, 
                                     // It's messy but works
    update_bb();
  }
}