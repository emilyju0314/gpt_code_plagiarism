void Intersection::simulate()
{
  //Starts the traffic light simulation
  _trafficLight.simulate();

  //Launches vehicle queue processing in a thread
  _threads.emplace_back(std::thread(&Intersection::processVehicleQueue, this));
}