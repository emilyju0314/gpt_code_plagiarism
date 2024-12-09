void ParticleFilter::resample() {
  std::discrete_distribution<int> sampler(weights.begin(), weights.end());

  for (auto &particle: particles) {
    size_t idx = sampler(gen);
    particle = particles[idx];
  }
}