void ParticleFilter::dataAssociation(vector<LandmarkObs> predicted, vector<LandmarkObs>& observations) {

  double closest;
  double distance;
  
  for (LandmarkObs &observation: observations) {
    closest = std::numeric_limits<double>::max();
    
    for (const LandmarkObs &prediction: predicted) { 
      distance = dist(observation.x, observation.y, prediction.x, prediction.y);
      
      if(distance < closest) {
      	closest = distance;
        observation.id = prediction.id;
      }
    }
  }
}