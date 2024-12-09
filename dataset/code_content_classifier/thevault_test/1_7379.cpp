void Solvers::Phasors(double phase_offset, vector<Complex> *n) {
  // Compute the center frequency.
  double fcenter = 0;
  for (int i = 0; i < solvers_.size(); i++) {
    fcenter += solvers_[i]->frequency_ / solvers_.size();
  }

  // Compute phasors.
  auto window = solvers_[0]->config_.wideband_window;
  n->resize(solvers_.size());
  for (int i = 0; i < solvers_.size(); i++) {
    (*n)[i] = exp(Complex(0, phase_offset * solvers_[i]->frequency_ / fcenter))
              / double(solvers_.size());
    if (window == ScriptConfig::HAMMING) {
      double scale = 0.5 - 0.5*cos((i+1) * 2*M_PI / (solvers_.size()+1));
      (*n)[i] *= scale;
    }
  }
}