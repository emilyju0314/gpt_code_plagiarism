void SimulationUtils::ProgressNotifier(double TotalTime, double Interval)
{
	std::clog.precision(4);
	NS_LOG_UNCOND("Simulation Progress: " << ((Simulator::Now ().GetSeconds())*100/TotalTime) << " %");
	Simulator::Schedule(Seconds(Interval), &SimulationUtils::ProgressNotifier, this, TotalTime, Interval);
}