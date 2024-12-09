void ParticleFilter::prediction(double delta_t, double std_pos[], double velocity, double yaw_rate) {
  // distributions for random noise.
  normal_distribution<double> dist_x_Q(0, std_pos[0]);
  normal_distribution<double> dist_y_Q(0, std_pos[1]);
  normal_distribution<double> dist_theta_Q(0, std_pos[2]);
  
  for (Particle &particle: particles) {
    double delta_yaw = yaw_rate * delta_t;
    if (fabs(delta_yaw) < 0.000001) {  
      particle.x += velocity * delta_t * cos(particle.theta);
      particle.y += velocity * delta_t * sin(particle.theta);
    } else {
      particle.x += (velocity / yaw_rate) * (sin(particle.theta + delta_yaw) - sin(particle.theta));
      particle.y += (velocity / yaw_rate) * (cos(particle.theta) - (cos(particle.theta + delta_yaw)));
      particle.theta += delta_yaw;
    }
    particle.x += dist_x_Q(gen);
    particle.y += dist_y_Q(gen);
    particle.theta += dist_theta_Q(gen);
  }
}