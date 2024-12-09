void ParticleFilter::init(double x, double y, double theta, double std[]) {
  num_particles = 50;
  normal_distribution<double> dist_x(x, std[0]);
  normal_distribution<double> dist_y(y, std[1]);
  normal_distribution<double> dist_theta(theta, std[2]);
  
  for (int i = 0; i < num_particles; i++) {
  	Particle particle;
    particle.id = 0;
    particle.x = dist_x(gen);
    particle.y= dist_y(gen);
    particle.theta = dist_theta(gen);
    particle.weight = 1.0;
    particles.push_back(particle);
    weights.push_back(1.0);
  }
  is_initialized = true;
}