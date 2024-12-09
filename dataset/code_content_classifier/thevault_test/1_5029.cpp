void Network::CollapseNetwork() {
  if (cells_.size() > 0) {
    for (NetworkUnit * cell : cells_) {
      delete cell;
    }
    cells_.clear();
  }

  id_map_.clear();

  parameter_collection_.Collapse();

  network_state_.set_next_uuid(0);
  network_state_.set_time(0);

  // Need to clean the memory for the solvers
  NetworkUnit::FreeSolverMemory();

  if (topology_) {
    delete topology_;
    topology_ = NULL;
  }

  // Don't forget to reset UUIDs
  BioFactory::ResetUUIDs();

  id_map_.clear();
}