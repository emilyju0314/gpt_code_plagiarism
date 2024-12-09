void Plumbing::SetEnableTraining(TrainingState state) {
  Network::SetEnableTraining(state);
  for (auto &i : stack_) {
    i->SetEnableTraining(state);
  }
}